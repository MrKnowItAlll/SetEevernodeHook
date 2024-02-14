//------------------------------------------------------------------------------
/*
    Copyright (c) 2024 Transia, LLC

    This financial product is intended for use by individuals or entities who
    possess the necessary licenses and qualifications to solicit and utilize
    such products in accordance with applicable laws and regulations.
    Unauthorized use or distribution of this product may be subject to legal
    consequences.

    The information provided in this financial product is for informational
    purposes only and should not be considered as financial advice or a
    recommendation to engage in any specific investment or financial strategy.
    It is important to consult with a qualified professional or financial
    advisor before making any investment decisions.
*/
//==============================================================================

#include "hookapi.h"

// clang-format off
uint8_t txn[283] =
{
/* size,upto */
/*   3,  0 */   0x12U, 0x00U, 0x00U,                                                            /* tt = Payment */
/*   5,  3*/    0x22U, 0x80U, 0x00U, 0x00U, 0x00U,                                              /* flags = tfCanonical */
/*   5,  8 */   0x24U, 0x00U, 0x00U, 0x00U, 0x00U,                                              /* sequence = 0 */
/*   5, 13 */   0x99U, 0x99U, 0x99U, 0x99U, 0x99U,                                              /* dtag, flipped */
/*   6, 18 */   0x20U, 0x1AU, 0x00U, 0x00U, 0x00U, 0x00U,                                       /* first ledger seq */
/*   6, 24 */   0x20U, 0x1BU, 0x00U, 0x00U, 0x00U, 0x00U,                                       /* last ledger seq */
/*  49, 30 */   0x61U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U,                         /* amount field 9 or 49 bytes */
                0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U,
                0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U,
                0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U,
                0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U,
                0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99U, 0x99,
/*   9, 79 */   0x68U, 0x40U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,                   /* fee      */
/*  35, 88 */   0x73U, 0x21U, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* pubkey   */
/*  22,123 */   0x81U, 0x14U, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                           /* src acc  */
/*  22,145 */   0x83U, 0x14U, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                           /* dst acc  */
/* 116,167 */                                                                                    /* emit details */
/*   0,283 */
};
// clang-format on

// TX BUILDER
#define FLS_OUT (txn + 20U)
#define LLS_OUT (txn + 26U)
#define DTAG_OUT (txn + 14U)
#define AMOUNT_OUT (txn + 30U)
#define FEE_OUT (txn + 80U)
#define HOOK_ACC (txn + 125U)
#define OTX_ACC (txn + 147U)
#define EMIT_OUT (txn + 167U)

#define CURRENCY_OFFSET 8U

int64_t hook(uint32_t reserved)
{
    TRACESTR("redirect.c: Called.");

    // ACCOUNT: Hook Account
    hook_account(HOOK_ACC, 20);

    // ACCOUNT: Origin Tx Account
    uint8_t otx_acc[20];
    otxn_field(otx_acc, 20, sfAccount);

    // FILTER ON: ACCOUNT
    if (BUFFER_EQUAL_20(HOOK_ACC, otx_acc))
        DONE("redirect: outgoing tx on `Account`.");

    uint8_t amount_buf[48];
    int64_t amount_len = otxn_field(SBUF(amount_buf), sfAmount);
    if (amount_len == 8)
    {
        DONE("redirect: Ignoring XRP Transaction");
    }

    // HOOK PARAM: Get account Destination
    uint8_t dest_key[1] = {'A'};
    if (hook_param(OTX_ACC, 20, SBUF(dest_key)) != 20)
    {
        DONE("redirect.c: Cant get Hook Parameter `A`");
    }

    // FILTER ON: EXCLUDE ACCOUNT
    if (BUFFER_EQUAL_20(OTX_ACC, otx_acc))
        DONE("redirect: Accepting EVR from excluded account");

    int64_t oslot = otxn_slot(0);
    if (oslot < 0)
        rollback(SBUF("redirect: Could not slot originating txn."), 1);

    int64_t amt_slot = slot_subfield(oslot, sfAmount, 0);
    if (amt_slot < 0)
        rollback(SBUF("redirect: Could not slot otxn.sfAmount"), 2);

    int64_t amount_xfl = slot_float(amt_slot);
    TRACEVAR(amount_xfl);
    if (float_compare(amount_xfl, 0, COMPARE_LESS | COMPARE_EQUAL) == 1)
        rollback(SBUF("redirect.c: Invalid Txn Parameter `AMT`"), __LINE__);

    //Redirect only for EVR
    uint8_t curr_buffer[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'E', 'V', 'R', 0, 0, 0, 0, 0};
    if (!BUFFER_EQUAL_20(amount_buf + CURRENCY_OFFSET, curr_buffer))
    {
        DONE("redirect: Ignoring non EVR Transaction");
    }

    // TXN: PREPARE: Init
    etxn_reserve(1);

    // TXN PREPARE: FirstLedgerSequence
    uint32_t fls = (uint32_t)ledger_seq() + 1;
    *((uint32_t *)(FLS_OUT)) = FLIP_ENDIAN(fls);

    // TXN PREPARE: LastLedgerSequense
    uint32_t lls = fls + 4;
    *((uint32_t *)(LLS_OUT)) = FLIP_ENDIAN(lls);

    // TXN PREPARE: Amount
    float_sto(AMOUNT_OUT, 49, amount_buf + 8, 20, amount_buf + 28, 20, amount_xfl, sfAmount);

    // TXN PREPARE: Dest Tag <- Source Tag
    if (otxn_field(DTAG_OUT, 4, sfSourceTag) == 4)
        *(DTAG_OUT - 1) = 0x2EU;

    // TXN PREPARE: Emit Metadata
    etxn_details(EMIT_OUT, 116U);

    // TXN PREPARE: Fee
    {
        int64_t fee = etxn_fee_base(SBUF(txn));
        uint8_t *b = FEE_OUT;
        *b++ = 0b01000000 + ((fee >> 56) & 0b00111111);
        *b++ = (fee >> 48) & 0xFFU;
        *b++ = (fee >> 40) & 0xFFU;
        *b++ = (fee >> 32) & 0xFFU;
        *b++ = (fee >> 24) & 0xFFU;
        *b++ = (fee >> 16) & 0xFFU;
        *b++ = (fee >> 8) & 0xFFU;
        *b++ = (fee >> 0) & 0xFFU;
    }

    TRACEHEX(txn); // <- final tx blob

    // TXN: Emit/Send Txn
    uint8_t emithash[32];
    int64_t emit_result = emit(SBUF(emithash), SBUF(txn));
    if (emit_result > 0)
    {
        accept(SBUF("redirect.c: Tx emitted success."), __LINE__);
    }
    accept(SBUF("redirect.c: Tx emitted failure."), __LINE__);

    _g(1, 1);
    // unreachable
    return 0;
}
