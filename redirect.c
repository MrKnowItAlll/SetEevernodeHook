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


#define KEYLET_HOOK 1
#define KEYLET_HOOK_STATE 2
#define KEYLET_ACCOUNT 3
#define KEYLET_AMENDMENTS 4
#define KEYLET_CHILD 5
#define KEYLET_SKIP 6
#define KEYLET_FEES 7
#define KEYLET_NEGATIVE_UNL 8
#define KEYLET_LINE 9
#define KEYLET_OFFER 10
#define KEYLET_QUALITY 11
#define KEYLET_EMITTED_DIR 12
#define KEYLET_TICKET 13
#define KEYLET_SIGNERS 14
#define KEYLET_CHECK 15
#define KEYLET_DEPOSIT_PREAUTH 16
#define KEYLET_UNCHECKED 17
#define KEYLET_OWNER_DIR 18
#define KEYLET_PAGE 19
#define KEYLET_ESCROW 20
#define KEYLET_PAYCHAN 21
#define KEYLET_EMITTED 22
#define KEYLET_NFT_OFFER 23
#define KEYLET_HOOK_DEFINITION 24

#define COMPARE_EQUAL 1U
#define COMPARE_LESS 2U
#define COMPARE_GREATER 4U

#define SUCCESS 0
#define OUT_OF_BOUNDS -1
#define INTERNAL_ERROR -2
#define TOO_BIG -3
#define TOO_SMALL -4
#define DOESNT_EXIST -5
#define NO_FREE_SLOTS -6
#define INVALID_ARGUMENT -7
#define ALREADY_SET -8
#define PREREQUISITE_NOT_MET -9
#define FEE_TOO_LARGE -10
#define EMISSION_FAILURE -11
#define TOO_MANY_NONCES -12
#define TOO_MANY_EMITTED_TXN -13
#define NOT_IMPLEMENTED -14
#define INVALID_ACCOUNT -15
#define GUARD_VIOLATION -16
#define INVALID_FIELD -17
#define PARSE_ERROR -18
#define RC_ROLLBACK -19
#define RC_ACCEPT -20
#define NO_SUCH_KEYLET -21
#define NOT_AN_ARRAY -22
#define NOT_AN_OBJECT -23
#define INVALID_FLOAT -10024
#define DIVISION_BY_ZERO -25
#define MANTISSA_OVERSIZED -26
#define MANTISSA_UNDERSIZED -27
#define EXPONENT_OVERSIZED -28
#define EXPONENT_UNDERSIZED -29
#define OVERFLOW -30
#define NOT_IOU_AMOUNT -31
#define NOT_AN_AMOUNT -32
#define CANT_RETURN_NEGATIVE -33
#define NOT_AUTHORIZED -34
#define PREVIOUS_FAILURE_PREVENTS_RETRY -35
#define TOO_MANY_PARAMS -36
#define INVALID_TXN -37
#define RESERVE_INSUFFICIENT -38
#define COMPLEX_NOT_SUPPORTED -39
#define DOES_NOT_MATCH -40
#define HOOK_ERROR_CODES


#include <stdint.h>

extern int32_t __attribute__((noduplicate))
_g(uint32_t guard_id, uint32_t maxiter);

extern int64_t
accept(uint32_t read_ptr, uint32_t read_len, int64_t error_code);

extern int64_t
emit(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
etxn_burden(void);

extern int64_t
etxn_details(uint32_t write_ptr, uint32_t write_len);

extern int64_t
etxn_fee_base(uint32_t read_ptr, uint32_t read_len);

extern int64_t
etxn_generation(void);

extern int64_t
etxn_nonce(uint32_t write_ptr, uint32_t write_len);

extern int64_t
etxn_reserve(uint32_t count);

extern int64_t
fee_base(void);

extern int64_t
float_compare(int64_t float1, int64_t float2, uint32_t mode);

extern int64_t
float_divide(int64_t float1, int64_t float2);

extern int64_t
float_exponent(int64_t float1);

extern int64_t
float_exponent_set(int64_t float1, int32_t exponent);

extern int64_t
float_int(int64_t float1, uint32_t decimal_places, uint32_t abs);

extern int64_t
float_invert(int64_t float1);

extern int64_t
float_log(int64_t float1);

extern int64_t
float_mantissa(int64_t float1);

extern int64_t
float_mantissa_set(int64_t float1, int64_t mantissa);

extern int64_t
float_mulratio(
    int64_t float1,
    uint32_t round_up,
    uint32_t numerator,
    uint32_t denominator);

extern int64_t
float_multiply(int64_t float1, int64_t float2);

extern int64_t
float_negate(int64_t float1);

extern int64_t
float_one(void);

extern int64_t
float_root(int64_t float1, uint32_t n);

extern int64_t
float_set(int32_t exponent, int64_t mantissa);

extern int64_t
float_sign(int64_t float1);

extern int64_t
float_sign_set(int64_t float1, uint32_t negative);

extern int64_t
float_sto(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t cread_ptr,
    uint32_t cread_len,
    uint32_t iread_ptr,
    uint32_t iread_len,
    int64_t float1,
    uint32_t field_code);

extern int64_t
float_sto_set(uint32_t read_ptr, uint32_t read_len);

extern int64_t
float_sum(int64_t float1, int64_t float2);

extern int64_t
hook_account(uint32_t write_ptr, uint32_t write_len);

extern int64_t
hook_again(void);

extern int64_t
hook_hash(uint32_t write_ptr, uint32_t write_len, int32_t hook_no);

extern int64_t
hook_param(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
otxn_param(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
hook_param_set(
    uint32_t read_ptr,
    uint32_t read_len,
    uint32_t kread_ptr,
    uint32_t kread_len,
    uint32_t hread_ptr,
    uint32_t hread_len);

extern int64_t
hook_pos(void);

extern int64_t
hook_skip(uint32_t read_ptr, uint32_t read_len, uint32_t flags);

extern int64_t
ledger_keylet(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t lread_ptr,
    uint32_t lread_len,
    uint32_t hread_ptr,
    uint32_t hread_len);

extern int64_t
ledger_last_hash(uint32_t write_ptr, uint32_t write_len);

extern int64_t
ledger_last_time(void);

extern int64_t
ledger_nonce(uint32_t write_ptr, uint32_t write_len);

extern int64_t
ledger_seq(void);

extern int64_t
meta_slot(uint32_t slot_no);

extern int64_t
otxn_burden(void);

extern int64_t
otxn_field(uint32_t write_ptr, uint32_t write_len, uint32_t field_id);

extern int64_t
otxn_field_txt(uint32_t write_ptr, uint32_t write_len, uint32_t field_id);

extern int64_t
otxn_generation(void);

extern int64_t
otxn_id(uint32_t write_ptr, uint32_t write_len, uint32_t flags);

extern int64_t
otxn_slot(uint32_t slot_no);

extern int64_t
otxn_type(void);

extern int64_t
rollback(uint32_t read_ptr, uint32_t read_len, int64_t error_code);

extern int64_t
slot(uint32_t write_ptr, uint32_t write_len, uint32_t slot);

extern int64_t
slot_clear(uint32_t slot);

extern int64_t
slot_count(uint32_t slot);

extern int64_t
slot_float(uint32_t slot_no);

extern int64_t
slot_id(uint32_t write_ptr, uint32_t write_len, uint32_t slot);

extern int64_t
slot_set(uint32_t read_ptr, uint32_t read_len, uint32_t slot);

extern int64_t
slot_size(uint32_t slot);

extern int64_t
slot_subarray(uint32_t parent_slot, uint32_t array_id, uint32_t new_slot);

extern int64_t
slot_subfield(uint32_t parent_slot, uint32_t field_id, uint32_t new_slot);

extern int64_t
slot_type(uint32_t slot_no, uint32_t flags);

extern int64_t
state(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t kread_ptr,
    uint32_t kread_len);

extern int64_t
state_foreign(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t kread_ptr,
    uint32_t kread_len,
    uint32_t nread_ptr,
    uint32_t nread_len,
    uint32_t aread_ptr,
    uint32_t aread_len);

extern int64_t
state_foreign_set(
    uint32_t read_ptr,
    uint32_t read_len,
    uint32_t kread_ptr,
    uint32_t kread_len,
    uint32_t nread_ptr,
    uint32_t nread_len,
    uint32_t aread_ptr,
    uint32_t aread_len);

extern int64_t
state_set(
    uint32_t read_ptr,
    uint32_t read_len,
    uint32_t kread_ptr,
    uint32_t kread_len);

extern int64_t
sto_emplace(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t sread_ptr,
    uint32_t sread_len,
    uint32_t fread_ptr,
    uint32_t fread_len,
    uint32_t field_id);

extern int64_t
sto_erase(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len,
    uint32_t field_id);

extern int64_t
sto_subarray(uint32_t read_ptr, uint32_t read_len, uint32_t array_id);

extern int64_t
sto_subfield(uint32_t read_ptr, uint32_t read_len, uint32_t field_id);

extern int64_t
sto_validate(uint32_t tread_ptr, uint32_t tread_len);

extern int64_t
trace(
    uint32_t mread_ptr,
    uint32_t mread_len,
    uint32_t dread_ptr,
    uint32_t dread_len,
    uint32_t as_hex);

extern int64_t
trace_float(uint32_t read_ptr, uint32_t read_len, int64_t float1);

extern int64_t
trace_num(uint32_t read_ptr, uint32_t read_len, int64_t number);

extern int64_t
trace_slot(uint32_t read_ptr, uint32_t read_len, uint32_t slot);

extern int64_t
util_accid(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
util_keylet(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t keylet_type,
    uint32_t a,
    uint32_t b,
    uint32_t c,
    uint32_t d,
    uint32_t e,
    uint32_t f);

extern int64_t
util_raddr(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
util_sha512h(
    uint32_t write_ptr,
    uint32_t write_len,
    uint32_t read_ptr,
    uint32_t read_len);

extern int64_t
util_verify(
    uint32_t dread_ptr,
    uint32_t dread_len,
    uint32_t sread_ptr,
    uint32_t sread_len,
    uint32_t kread_ptr,
    uint32_t kread_len);


#define sfCloseResolution ((16U << 16U) + 1U)
#define sfMethod ((16U << 16U) + 2U)
#define sfTransactionResult ((16U << 16U) + 3U)
#define sfTickSize ((16U << 16U) + 16U)
#define sfUNLModifyDisabling ((16U << 16U) + 17U)
#define sfHookResult ((16U << 16U) + 18U)
#define sfLedgerEntryType ((1U << 16U) + 1U)
#define sfTransactionType ((1U << 16U) + 2U)
#define sfSignerWeight ((1U << 16U) + 3U)
#define sfTransferFee ((1U << 16U) + 4U)
#define sfVersion ((1U << 16U) + 16U)
#define sfHookStateChangeCount ((1U << 16U) + 17U)
#define sfHookEmitCount ((1U << 16U) + 18U)
#define sfHookExecutionIndex ((1U << 16U) + 19U)
#define sfHookApiVersion ((1U << 16U) + 20U)
#define sfNetworkID ((2U << 16U) + 1U)
#define sfFlags ((2U << 16U) + 2U)
#define sfSourceTag ((2U << 16U) + 3U)
#define sfSequence ((2U << 16U) + 4U)
#define sfPreviousTxnLgrSeq ((2U << 16U) + 5U)
#define sfLedgerSequence ((2U << 16U) + 6U)
#define sfCloseTime ((2U << 16U) + 7U)
#define sfParentCloseTime ((2U << 16U) + 8U)
#define sfSigningTime ((2U << 16U) + 9U)
#define sfExpiration ((2U << 16U) + 10U)
#define sfTransferRate ((2U << 16U) + 11U)
#define sfWalletSize ((2U << 16U) + 12U)
#define sfOwnerCount ((2U << 16U) + 13U)
#define sfDestinationTag ((2U << 16U) + 14U)
#define sfHighQualityIn ((2U << 16U) + 16U)
#define sfHighQualityOut ((2U << 16U) + 17U)
#define sfLowQualityIn ((2U << 16U) + 18U)
#define sfLowQualityOut ((2U << 16U) + 19U)
#define sfQualityIn ((2U << 16U) + 20U)
#define sfQualityOut ((2U << 16U) + 21U)
#define sfStampEscrow ((2U << 16U) + 22U)
#define sfBondAmount ((2U << 16U) + 23U)
#define sfLoadFee ((2U << 16U) + 24U)
#define sfOfferSequence ((2U << 16U) + 25U)
#define sfFirstLedgerSequence ((2U << 16U) + 26U)
#define sfLastLedgerSequence ((2U << 16U) + 27U)
#define sfTransactionIndex ((2U << 16U) + 28U)
#define sfOperationLimit ((2U << 16U) + 29U)
#define sfReferenceFeeUnits ((2U << 16U) + 30U)
#define sfReserveBase ((2U << 16U) + 31U)
#define sfReserveIncrement ((2U << 16U) + 32U)
#define sfSetFlag ((2U << 16U) + 33U)
#define sfClearFlag ((2U << 16U) + 34U)
#define sfSignerQuorum ((2U << 16U) + 35U)
#define sfCancelAfter ((2U << 16U) + 36U)
#define sfFinishAfter ((2U << 16U) + 37U)
#define sfSignerListID ((2U << 16U) + 38U)
#define sfSettleDelay ((2U << 16U) + 39U)
#define sfTicketCount ((2U << 16U) + 40U)
#define sfTicketSequence ((2U << 16U) + 41U)
#define sfNFTokenTaxon ((2U << 16U) + 42U)
#define sfMintedNFTokens ((2U << 16U) + 43U)
#define sfBurnedNFTokens ((2U << 16U) + 44U)
#define sfHookStateCount ((2U << 16U) + 45U)
#define sfEmitGeneration ((2U << 16U) + 46U)
#define sfLockCount ((2U << 16U) + 47U)
#define sfRewardTime ((2U << 16U) + 98U)
#define sfRewardLgrFirst ((2U << 16U) + 99U)
#define sfRewardLgrLast ((2U << 16U) + 100U)
#define sfIndexNext ((3U << 16U) + 1U)
#define sfIndexPrevious ((3U << 16U) + 2U)
#define sfBookNode ((3U << 16U) + 3U)
#define sfOwnerNode ((3U << 16U) + 4U)
#define sfBaseFee ((3U << 16U) + 5U)
#define sfExchangeRate ((3U << 16U) + 6U)
#define sfLowNode ((3U << 16U) + 7U)
#define sfHighNode ((3U << 16U) + 8U)
#define sfDestinationNode ((3U << 16U) + 9U)
#define sfCookie ((3U << 16U) + 10U)
#define sfServerVersion ((3U << 16U) + 11U)
#define sfNFTokenOfferNode ((3U << 16U) + 12U)
#define sfEmitBurden ((3U << 16U) + 13U)
#define sfHookInstructionCount ((3U << 16U) + 17U)
#define sfHookReturnCode ((3U << 16U) + 18U)
#define sfReferenceCount ((3U << 16U) + 19U)
#define sfRewardAccumulator ((3U << 16U) + 100U)
#define sfEmailHash ((4U << 16U) + 1U)
#define sfTakerPaysCurrency ((10U << 16U) + 1U)
#define sfTakerPaysIssuer ((10U << 16U) + 2U)
#define sfTakerGetsCurrency ((10U << 16U) + 3U)
#define sfTakerGetsIssuer ((10U << 16U) + 4U)
#define sfLedgerHash ((5U << 16U) + 1U)
#define sfParentHash ((5U << 16U) + 2U)
#define sfTransactionHash ((5U << 16U) + 3U)
#define sfAccountHash ((5U << 16U) + 4U)
#define sfPreviousTxnID ((5U << 16U) + 5U)
#define sfLedgerIndex ((5U << 16U) + 6U)
#define sfWalletLocator ((5U << 16U) + 7U)
#define sfRootIndex ((5U << 16U) + 8U)
#define sfAccountTxnID ((5U << 16U) + 9U)
#define sfNFTokenID ((5U << 16U) + 10U)
#define sfEmitParentTxnID ((5U << 16U) + 11U)
#define sfEmitNonce ((5U << 16U) + 12U)
#define sfEmitHookHash ((5U << 16U) + 13U)
#define sfBookDirectory ((5U << 16U) + 16U)
#define sfInvoiceID ((5U << 16U) + 17U)
#define sfNickname ((5U << 16U) + 18U)
#define sfAmendment ((5U << 16U) + 19U)
#define sfHookOn ((5U << 16U) + 20U)
#define sfDigest ((5U << 16U) + 21U)
#define sfChannel ((5U << 16U) + 22U)
#define sfConsensusHash ((5U << 16U) + 23U)
#define sfCheckID ((5U << 16U) + 24U)
#define sfValidatedHash ((5U << 16U) + 25U)
#define sfPreviousPageMin ((5U << 16U) + 26U)
#define sfNextPageMin ((5U << 16U) + 27U)
#define sfNFTokenBuyOffer ((5U << 16U) + 28U)
#define sfNFTokenSellOffer ((5U << 16U) + 29U)
#define sfHookStateKey ((5U << 16U) + 30U)
#define sfHookHash ((5U << 16U) + 31U)
#define sfHookNamespace ((5U << 16U) + 32U)
#define sfHookSetTxnID ((5U << 16U) + 33U)
#define sfOfferID ((5U << 16U) + 34U)
#define sfEscrowID ((5U << 16U) + 35U)
#define sfURITokenID ((5U << 16U) + 36U)
#define sfAmount ((6U << 16U) + 1U)
#define sfBalance ((6U << 16U) + 2U)
#define sfLimitAmount ((6U << 16U) + 3U)
#define sfTakerPays ((6U << 16U) + 4U)
#define sfTakerGets ((6U << 16U) + 5U)
#define sfLowLimit ((6U << 16U) + 6U)
#define sfHighLimit ((6U << 16U) + 7U)
#define sfFee ((6U << 16U) + 8U)
#define sfSendMax ((6U << 16U) + 9U)
#define sfDeliverMin ((6U << 16U) + 10U)
#define sfMinimumOffer ((6U << 16U) + 16U)
#define sfRippleEscrow ((6U << 16U) + 17U)
#define sfDeliveredAmount ((6U << 16U) + 18U)
#define sfNFTokenBrokerFee ((6U << 16U) + 19U)
#define sfHookCallbackFee ((6U << 16U) + 20U)
#define sfLockedBalance ((6U << 16U) + 21U)
#define sfPublicKey ((7U << 16U) + 1U)
#define sfMessageKey ((7U << 16U) + 2U)
#define sfSigningPubKey ((7U << 16U) + 3U)
#define sfTxnSignature ((7U << 16U) + 4U)
#define sfURI ((7U << 16U) + 5U)
#define sfSignature ((7U << 16U) + 6U)
#define sfDomain ((7U << 16U) + 7U)
#define sfFundCode ((7U << 16U) + 8U)
#define sfRemoveCode ((7U << 16U) + 9U)
#define sfExpireCode ((7U << 16U) + 10U)
#define sfCreateCode ((7U << 16U) + 11U)
#define sfMemoType ((7U << 16U) + 12U)
#define sfMemoData ((7U << 16U) + 13U)
#define sfMemoFormat ((7U << 16U) + 14U)
#define sfFulfillment ((7U << 16U) + 16U)
#define sfCondition ((7U << 16U) + 17U)
#define sfMasterSignature ((7U << 16U) + 18U)
#define sfUNLModifyValidator ((7U << 16U) + 19U)
#define sfValidatorToDisable ((7U << 16U) + 20U)
#define sfValidatorToReEnable ((7U << 16U) + 21U)
#define sfHookStateData ((7U << 16U) + 22U)
#define sfHookReturnString ((7U << 16U) + 23U)
#define sfHookParameterName ((7U << 16U) + 24U)
#define sfHookParameterValue ((7U << 16U) + 25U)
#define sfBlob ((7U << 16U) + 26U)
#define sfAccount ((8U << 16U) + 1U)
#define sfOwner ((8U << 16U) + 2U)
#define sfDestination ((8U << 16U) + 3U)
#define sfIssuer ((8U << 16U) + 4U)
#define sfAuthorize ((8U << 16U) + 5U)
#define sfUnauthorize ((8U << 16U) + 6U)
#define sfRegularKey ((8U << 16U) + 8U)
#define sfNFTokenMinter ((8U << 16U) + 9U)
#define sfEmitCallback ((8U << 16U) + 10U)
#define sfHookAccount ((8U << 16U) + 16U)
#define sfIndexes ((19U << 16U) + 1U)
#define sfHashes ((19U << 16U) + 2U)
#define sfAmendments ((19U << 16U) + 3U)
#define sfNFTokenOffers ((19U << 16U) + 4U)
#define sfHookNamespaces ((19U << 16U) + 5U)
#define sfPaths ((18U << 16U) + 1U)
#define sfTransactionMetaData ((14U << 16U) + 2U)
#define sfCreatedNode ((14U << 16U) + 3U)
#define sfDeletedNode ((14U << 16U) + 4U)
#define sfModifiedNode ((14U << 16U) + 5U)
#define sfPreviousFields ((14U << 16U) + 6U)
#define sfFinalFields ((14U << 16U) + 7U)
#define sfNewFields ((14U << 16U) + 8U)
#define sfTemplateEntry ((14U << 16U) + 9U)
#define sfMemo ((14U << 16U) + 10U)
#define sfSignerEntry ((14U << 16U) + 11U)
#define sfNFToken ((14U << 16U) + 12U)
#define sfEmitDetails ((14U << 16U) + 13U)
#define sfHook ((14U << 16U) + 14U)
#define sfSigner ((14U << 16U) + 16U)
#define sfMajority ((14U << 16U) + 18U)
#define sfDisabledValidator ((14U << 16U) + 19U)
#define sfEmittedTxn ((14U << 16U) + 20U)
#define sfHookExecution ((14U << 16U) + 21U)
#define sfHookDefinition ((14U << 16U) + 22U)
#define sfHookParameter ((14U << 16U) + 23U)
#define sfHookGrant ((14U << 16U) + 24U)
#define sfSigners ((15U << 16U) + 3U)
#define sfSignerEntries ((15U << 16U) + 4U)
#define sfTemplate ((15U << 16U) + 5U)
#define sfNecessary ((15U << 16U) + 6U)
#define sfSufficient ((15U << 16U) + 7U)
#define sfAffectedNodes ((15U << 16U) + 8U)
#define sfMemos ((15U << 16U) + 9U)
#define sfNFTokens ((15U << 16U) + 10U)
#define sfHooks ((15U << 16U) + 11U)
#define sfMajorities ((15U << 16U) + 16U)
#define sfDisabledValidators ((15U << 16U) + 17U)
#define sfHookExecutions ((15U << 16U) + 18U)
#define sfHookParameters ((15U << 16U) + 19U)
#define sfHookGrants ((15U << 16U) + 20U)


#include <stdint.h>


#define DONEEMPTY()\
    accept(0,0,__LINE__)

#define DONEMSG(msg)\
    accept(msg, sizeof(msg),__LINE__)

#define DONE(x)\
    accept(SVAR(x),(uint32_t)__LINE__);


#define SVAR(x) &x, sizeof(x)

#define ASSERT(x)\
{\
    if (!(x))\
        rollback(0,0,__LINE__);\
}

#define FLIP_ENDIAN(n) ((uint32_t) (((n & 0xFFU) << 24U) | \
                                   ((n & 0xFF00U) << 8U) | \
                                 ((n & 0xFF0000U) >> 8U) | \
                                ((n & 0xFF000000U) >> 24U)))


#ifdef NDEBUG
#define DEBUG 0
#else
#define DEBUG 1
#endif

#define TRACEVAR(v) if (DEBUG) trace_num((uint32_t)(#v), (uint32_t)(sizeof(#v) - 1), (int64_t)v);
#define TRACEHEX(v) if (DEBUG) trace((uint32_t)(#v), (uint32_t)(sizeof(#v) - 1), (uint32_t)(v), (uint32_t)(sizeof(v)), 1);
#define TRACEXFL(v) if (DEBUG) trace_float((uint32_t)(#v), (uint32_t)(sizeof(#v) - 1), (int64_t)v);
#define TRACESTR(v) if (DEBUG) trace((uint32_t)(#v), (uint32_t)(sizeof(#v) - 1), (uint32_t)(v), sizeof(v), 0);

// hook developers should use this guard macro, simply GUARD(<maximum iterations>)
#define GUARD(maxiter) _g((1ULL << 31U) + __LINE__, (maxiter)+1)
#define GUARDM(maxiter, n) _g(( (1ULL << 31U) + (__LINE__ << 16) + n), (maxiter)+1)

#define SBUF(str) (uint32_t)(str), sizeof(str)

#define REQUIRE(cond, str)\
{\
    if (!(cond))\
        rollback(SBUF(str), __LINE__);\
}

// make a report buffer as a c-string
// provide a name for a buffer to declare (buf)
// provide a static string
// provide an integer to print after the string
#define RBUF(buf, out_len, str, num)\
unsigned char buf[sizeof(str) + 21];\
int out_len = 0;\
{\
    int i = 0;\
    for (; GUARDM(sizeof(str),1),i < sizeof(str); ++i)\
        (buf)[i] = str[i];\
    if ((buf)[sizeof(str)-1] == 0) i--;\
    if ((num) < 0) (buf)[i++] = '-';\
    uint64_t unsigned_num = (uint64_t)( (num) < 0 ? (num) * -1 : (num) );\
    uint64_t j = 10000000000000000000ULL;\
    int start = 1;\
    for (; GUARDM(20,2), unsigned_num > 0 && j > 0; j /= 10)\
    {\
        unsigned char digit = ( unsigned_num / j ) % 10;\
        if (digit == 0 && start)\
            continue;\
        start = 0;\
        (buf)[i++] = '0' + digit;\
    }\
    (buf)[i] = '\0';\
    out_len = i;\
}

#define RBUF2(buff, out_len, str, num, str2, num2)\
unsigned char buff[sizeof(str) + sizeof(str2) + 42];\
int out_len = 0;\
{\
    unsigned char* buf = buff;\
    int i = 0;\
    for (; GUARDM(sizeof(str),1),i < sizeof(str); ++i)\
        (buf)[i] = str[i];\
    if ((buf)[sizeof(str)-1] == 0) i--;\
    if ((num) < 0) (buf)[i++] = '-';\
    uint64_t unsigned_num = (uint64_t)( (num) < 0 ? (num) * -1 : (num) );\
    uint64_t j = 10000000000000000000ULL;\
    int start = 1;\
    for (; GUARDM(20,2), unsigned_num > 0 && j > 0; j /= 10)\
    {\
        unsigned char digit = ( unsigned_num / j ) % 10;\
        if (digit == 0 && start)\
            continue;\
        start = 0;\
        (buf)[i++] = '0' + digit;\
    }\
    buf += i;\
    out_len += i;\
    i = 0;\
    for (; GUARDM(sizeof(str2),3),i < sizeof(str2); ++i)\
        (buf)[i] = str2[i];\
    if ((buf)[sizeof(str2)-1] == 0) i--;\
    if ((num2) < 0) (buf)[i++] = '-';\
    unsigned_num = (uint64_t)( (num2) < 0 ? (num2) * -1 : (num2) );\
    j = 10000000000000000000ULL;\
    start = 1;\
    for (; GUARDM(20,4), unsigned_num > 0 && j > 0; j /= 10)\
    {\
        unsigned char digit = ( unsigned_num / j ) % 10;\
        if (digit == 0 && start)\
            continue;\
        start = 0;\
        (buf)[i++] = '0' + digit;\
    }\
    (buf)[i] = '\0';\
    out_len += i;\
}

#define CLEARBUF(b)\
{\
    for (int x = 0; GUARD(sizeof(b)), x < sizeof(b); ++x)\
        b[x] = 0;\
}

// returns an in64_t, negative if error, non-negative if valid drops
#define AMOUNT_TO_DROPS(amount_buffer)\
     (((amount_buffer)[0] >> 7) ? -2 : (\
     ((((uint64_t)((amount_buffer)[0])) & 0xb00111111) << 56) +\
      (((uint64_t)((amount_buffer)[1])) << 48) +\
      (((uint64_t)((amount_buffer)[2])) << 40) +\
      (((uint64_t)((amount_buffer)[3])) << 32) +\
      (((uint64_t)((amount_buffer)[4])) << 24) +\
      (((uint64_t)((amount_buffer)[5])) << 16) +\
      (((uint64_t)((amount_buffer)[6])) <<  8) +\
      (((uint64_t)((amount_buffer)[7])))))

#define SUB_OFFSET(x) ((int32_t)(x >> 32))
#define SUB_LENGTH(x) ((int32_t)(x & 0xFFFFFFFFULL))

#define BUFFER_EQUAL_20(buf1, buf2)\
    (\
        *(((uint64_t*)(buf1)) + 0) == *(((uint64_t*)(buf2)) + 0) &&\
        *(((uint64_t*)(buf1)) + 1) == *(((uint64_t*)(buf2)) + 1) &&\
        *(((uint32_t*)(buf1)) + 4) == *(((uint32_t*)(buf2)) + 4))

#define BUFFER_EQUAL_32(buf1, buf2)\
    (\
        *(((uint64_t*)(buf1)) + 0) == *(((uint64_t*)(buf2)) + 0) &&\
        *(((uint64_t*)(buf1)) + 1) == *(((uint64_t*)(buf2)) + 1) &&\
        *(((uint64_t*)(buf1)) + 2) == *(((uint64_t*)(buf2)) + 2) &&\
        *(((uint64_t*)(buf1)) + 3) == *(((uint64_t*)(buf2)) + 3) &&\
        *(((uint64_t*)(buf1)) + 4) == *(((uint64_t*)(buf2)) + 4) &&\
        *(((uint64_t*)(buf1)) + 5) == *(((uint64_t*)(buf2)) + 5) &&\
        *(((uint64_t*)(buf1)) + 6) == *(((uint64_t*)(buf2)) + 6) &&\
        *(((uint64_t*)(buf1)) + 7) == *(((uint64_t*)(buf2)) + 7))


// when using this macro buf1len may be dynamic but buf2len must be static
// provide n >= 1 to indicate how many times the macro will be hit on the line of code
// e.g. if it is in a loop that loops 10 times n = 10

#define BUFFER_EQUAL_GUARD(output, buf1, buf1len, buf2, buf2len, n)\
{\
    output = ((buf1len) == (buf2len) ? 1 : 0);\
    for (int x = 0; GUARDM( (buf2len) * (n), 1 ), output && x < (buf2len);\
         ++x)\
        output = *(((uint8_t*)(buf1)) + x) == *(((uint8_t*)(buf2)) + x);\
}

#define BUFFER_SWAP(x,y)\
{\
    uint8_t* z = x;\
    x = y;\
    y = z;\
}

#define ACCOUNT_COMPARE(compare_result, buf1, buf2)\
{\
    compare_result = 0;\
    for (int i = 0; GUARD(20), i < 20; ++i)\
    {\
        if (buf1[i] > buf2[i])\
        {\
            compare_result = 1;\
            break;\
        }\
        else if (buf1[i] < buf2[i])\
        {\
            compare_result = -1;\
            break;\
        }\
    }\
}

#define BUFFER_EQUAL_STR_GUARD(output, buf1, buf1len, str, n)\
    BUFFER_EQUAL_GUARD(output, buf1, buf1len, str, (sizeof(str)-1), n)

#define BUFFER_EQUAL_STR(output, buf1, buf1len, str)\
    BUFFER_EQUAL_GUARD(output, buf1, buf1len, str, (sizeof(str)-1), 1)

#define BUFFER_EQUAL(output, buf1, buf2, compare_len)\
    BUFFER_EQUAL_GUARD(output, buf1, compare_len, buf2, compare_len, 1)

#define UINT16_TO_BUF(buf_raw, i)\
{\
    unsigned char* buf = (unsigned char*)buf_raw;\
    buf[0] = (((uint64_t)i) >> 8) & 0xFFUL;\
    buf[1] = (((uint64_t)i) >> 0) & 0xFFUL;\
}

#define UINT16_FROM_BUF(buf)\
    (((uint64_t)((buf)[0]) <<  8) +\
     ((uint64_t)((buf)[1]) <<  0))

#define UINT32_TO_BUF(buf_raw, i)\
{\
    unsigned char* buf = (unsigned char*)buf_raw;\
    buf[0] = (((uint64_t)i) >> 24) & 0xFFUL;\
    buf[1] = (((uint64_t)i) >> 16) & 0xFFUL;\
    buf[2] = (((uint64_t)i) >>  8) & 0xFFUL;\
    buf[3] = (((uint64_t)i) >>  0) & 0xFFUL;\
}


#define UINT32_FROM_BUF(buf)\
    (((uint64_t)((buf)[0]) << 24) +\
     ((uint64_t)((buf)[1]) << 16) +\
     ((uint64_t)((buf)[2]) <<  8) +\
     ((uint64_t)((buf)[3]) <<  0))

#define UINT64_TO_BUF(buf_raw, i)\
{\
    unsigned char* buf = (unsigned char*)buf_raw;\
    buf[0] = (((uint64_t)i) >> 56) & 0xFFUL;\
    buf[1] = (((uint64_t)i) >> 48) & 0xFFUL;\
    buf[2] = (((uint64_t)i) >> 40) & 0xFFUL;\
    buf[3] = (((uint64_t)i) >> 32) & 0xFFUL;\
    buf[4] = (((uint64_t)i) >> 24) & 0xFFUL;\
    buf[5] = (((uint64_t)i) >> 16) & 0xFFUL;\
    buf[6] = (((uint64_t)i) >>  8) & 0xFFUL;\
    buf[7] = (((uint64_t)i) >>  0) & 0xFFUL;\
}


#define UINT64_FROM_BUF(buf)\
    (((uint64_t)((buf)[0]) << 56) +\
     ((uint64_t)((buf)[1]) << 48) +\
     ((uint64_t)((buf)[2]) << 40) +\
     ((uint64_t)((buf)[3]) << 32) +\
     ((uint64_t)((buf)[4]) << 24) +\
     ((uint64_t)((buf)[5]) << 16) +\
     ((uint64_t)((buf)[6]) <<  8) +\
     ((uint64_t)((buf)[7]) <<  0))


#define INT64_FROM_BUF(buf)\
   ((((uint64_t)((buf)[0] & 0x7FU) << 56) +\
     ((uint64_t)((buf)[1]) << 48) +\
     ((uint64_t)((buf)[2]) << 40) +\
     ((uint64_t)((buf)[3]) << 32) +\
     ((uint64_t)((buf)[4]) << 24) +\
     ((uint64_t)((buf)[5]) << 16) +\
     ((uint64_t)((buf)[6]) <<  8) +\
     ((uint64_t)((buf)[7]) <<  0)) * (buf[0] & 0x80U ? -1 : 1))

#define INT64_TO_BUF(buf_raw, i)\
{\
    unsigned char* buf = (unsigned char*)buf_raw;\
    buf[0] = (((uint64_t)i) >> 56) & 0x7FUL;\
    buf[1] = (((uint64_t)i) >> 48) & 0xFFUL;\
    buf[2] = (((uint64_t)i) >> 40) & 0xFFUL;\
    buf[3] = (((uint64_t)i) >> 32) & 0xFFUL;\
    buf[4] = (((uint64_t)i) >> 24) & 0xFFUL;\
    buf[5] = (((uint64_t)i) >> 16) & 0xFFUL;\
    buf[6] = (((uint64_t)i) >>  8) & 0xFFUL;\
    buf[7] = (((uint64_t)i) >>  0) & 0xFFUL;\
    if (i < 0) buf[0] |= 0x80U;\
}

#define ttPAYMENT 0
#define ttESCROW_CREATE 1
#define ttESCROW_FINISH 2
#define ttACCOUNT_SET 3
#define ttESCROW_CANCEL 4
#define ttREGULAR_KEY_SET 5
#define ttOFFER_CREATE 7
#define ttOFFER_CANCEL 8
#define ttTICKET_CREATE 10
#define ttSIGNER_LIST_SET 12
#define ttPAYCHAN_CREATE 13
#define ttPAYCHAN_FUND 14
#define ttPAYCHAN_CLAIM 15
#define ttCHECK_CREATE 16
#define ttCHECK_CASH 17
#define ttCHECK_CANCEL 18
#define ttDEPOSIT_PREAUTH 19
#define ttTRUST_SET 20
#define ttACCOUNT_DELETE 21
#define ttHOOK_SET 22
#define ttNFTOKEN_MINT 25
#define ttNFTOKEN_BURN 26
#define ttNFTOKEN_CREATE_OFFER 27
#define ttNFTOKEN_CANCEL_OFFER 28
#define ttNFTOKEN_ACCEPT_OFFER 29
#define ttURITOKEN_MINT 45
#define ttURITOKEN_BURN 46
#define ttURITOKEN_BUY 47
#define ttURITOKEN_CREATE_SELL_OFFER 48
#define ttURITOKEN_CANCEL_SELL_OFFER 49
#define ttCLAIM_REWARD 98
#define ttINVOKE 99
#define ttAMENDMENT 100
#define ttFEE 101
#define ttUNL_MODIFY 102
#define ttEMIT_FAILURE 103
#define tfCANONICAL 0x80000000UL

#define atACCOUNT 1U
#define atOWNER 2U
#define atDESTINATION 3U
#define atISSUER 4U
#define atAUTHORIZE 5U
#define atUNAUTHORIZE 6U
#define atTARGET 7U
#define atREGULARKEY 8U
#define atPSEUDOCALLBACK 9U

#define amAMOUNT 1U
#define amBALANCE 2U
#define amLIMITAMOUNT 3U
#define amTAKERPAYS 4U
#define amTAKERGETS 5U
#define amLOWLIMIT 6U
#define amHIGHLIMIT 7U
#define amFEE 8U
#define amSENDMAX 9U
#define amDELIVERMIN 10U
#define amMINIMUMOFFER 16U
#define amRIPPLEESCROW 17U
#define amDELIVEREDAMOUNT 18U

/**
 * RH NOTE -- PAY ATTENTION
 *
 * ALL 'ENCODE' MACROS INCREMENT BUF_OUT
 * THIS IS TO MAKE CHAINING EASY
 * BUF_OUT IS A SACRIFICIAL POINTER
 *
 * 'ENCODE' MACROS WITH CONSTANTS HAVE
 * ALIASING TO ASSIST YOU WITH ORDER
 * _TYPECODE_FIELDCODE_ENCODE_MACRO
 * TO PRODUCE A SERIALIZED OBJECT
 * IN CANONICAL FORMAT YOU MUST ORDER
 * FIRST BY TYPE CODE THEN BY FIELD CODE
 *
 * ALL 'PREPARE' MACROS PRESERVE POINTERS
 *
 **/


#define ENCODE_TL_SIZE 49
#define ENCODE_TL(buf_out, tlamt, amount_type)\
{\
        uint8_t uat = amount_type; \
        buf_out[0] = 0x60U +(uat & 0x0FU ); \
        for (int i = 1; GUARDM(48, 1), i < 49; ++i)\
            buf_out[i] = tlamt[i-1];\
        buf_out += ENCODE_TL_SIZE;\
}
#define _06_XX_ENCODE_TL(buf_out, drops, amount_type )\
    ENCODE_TL(buf_out, drops, amount_type );
#define ENCODE_TL_AMOUNT(buf_out, drops )\
    ENCODE_TL(buf_out, drops, amAMOUNT );
#define _06_01_ENCODE_TL_AMOUNT(buf_out, drops )\
    ENCODE_TL_AMOUNT(buf_out, drops );


// Encode drops to serialization format
// consumes 9 bytes
#define ENCODE_DROPS_SIZE 9
#define ENCODE_DROPS(buf_out, drops, amount_type ) \
    {\
        uint8_t uat = amount_type; \
        uint64_t udrops = drops; \
        buf_out[0] = 0x60U +(uat & 0x0FU ); \
        buf_out[1] = 0b01000000 + (( udrops >> 56 ) & 0b00111111 ); \
        buf_out[2] = (udrops >> 48) & 0xFFU; \
        buf_out[3] = (udrops >> 40) & 0xFFU; \
        buf_out[4] = (udrops >> 32) & 0xFFU; \
        buf_out[5] = (udrops >> 24) & 0xFFU; \
        buf_out[6] = (udrops >> 16) & 0xFFU; \
        buf_out[7] = (udrops >>  8) & 0xFFU; \
        buf_out[8] = (udrops >>  0) & 0xFFU; \
        buf_out += ENCODE_DROPS_SIZE; \
    }

#define _06_XX_ENCODE_DROPS(buf_out, drops, amount_type )\
    ENCODE_DROPS(buf_out, drops, amount_type );

#define ENCODE_DROPS_AMOUNT(buf_out, drops )\
    ENCODE_DROPS(buf_out, drops, amAMOUNT );
#define _06_01_ENCODE_DROPS_AMOUNT(buf_out, drops )\
    ENCODE_DROPS_AMOUNT(buf_out, drops );

#define ENCODE_DROPS_FEE(buf_out, drops )\
    ENCODE_DROPS(buf_out, drops, amFEE );
#define _06_08_ENCODE_DROPS_FEE(buf_out, drops )\
    ENCODE_DROPS_FEE(buf_out, drops );

#define ENCODE_TT_SIZE 3
#define ENCODE_TT(buf_out, tt )\
    {\
        uint8_t utt = tt;\
        buf_out[0] = 0x12U;\
        buf_out[1] =(utt >> 8 ) & 0xFFU;\
        buf_out[2] =(utt >> 0 ) & 0xFFU;\
        buf_out += ENCODE_TT_SIZE; \
    }
#define _01_02_ENCODE_TT(buf_out, tt)\
    ENCODE_TT(buf_out, tt);


#define ENCODE_ACCOUNT_SIZE 22
#define ENCODE_ACCOUNT(buf_out, account_id, account_type)\
    {\
        uint8_t uat = account_type;\
        buf_out[0] = 0x80U + uat;\
        buf_out[1] = 0x14U;\
        *(uint64_t*)(buf_out +  2) = *(uint64_t*)(account_id +  0);\
        *(uint64_t*)(buf_out + 10) = *(uint64_t*)(account_id +  8);\
        *(uint32_t*)(buf_out + 18) = *(uint32_t*)(account_id + 16);\
        buf_out += ENCODE_ACCOUNT_SIZE;\
    }
#define _08_XX_ENCODE_ACCOUNT(buf_out, account_id, account_type)\
    ENCODE_ACCOUNT(buf_out, account_id, account_type);

#define ENCODE_ACCOUNT_SRC_SIZE 22
#define ENCODE_ACCOUNT_SRC(buf_out, account_id)\
    ENCODE_ACCOUNT(buf_out, account_id, atACCOUNT);
#define _08_01_ENCODE_ACCOUNT_SRC(buf_out, account_id)\
    ENCODE_ACCOUNT_SRC(buf_out, account_id);

#define ENCODE_ACCOUNT_DST_SIZE 22
#define ENCODE_ACCOUNT_DST(buf_out, account_id)\
    ENCODE_ACCOUNT(buf_out, account_id, atDESTINATION);
#define _08_03_ENCODE_ACCOUNT_DST(buf_out, account_id)\
    ENCODE_ACCOUNT_DST(buf_out, account_id);

#define ENCODE_ACCOUNT_OWNER_SIZE 22
#define ENCODE_ACCOUNT_OWNER(buf_out, account_id) \
    ENCODE_ACCOUNT(buf_out, account_id, atOWNER);
#define _08_02_ENCODE_ACCOUNT_OWNER(buf_out, account_id) \
    ENCODE_ACCOUNT_OWNER(buf_out, account_id);

#define ENCODE_UINT32_COMMON_SIZE 5U
#define ENCODE_UINT32_COMMON(buf_out, i, field)\
    {\
        uint32_t ui = i; \
        uint8_t uf = field; \
        buf_out[0] = 0x20U +(uf & 0x0FU); \
        buf_out[1] =(ui >> 24 ) & 0xFFU; \
        buf_out[2] =(ui >> 16 ) & 0xFFU; \
        buf_out[3] =(ui >>  8 ) & 0xFFU; \
        buf_out[4] =(ui >>  0 ) & 0xFFU; \
        buf_out += ENCODE_UINT32_COMMON_SIZE; \
    }
#define _02_XX_ENCODE_UINT32_COMMON(buf_out, i, field)\
    ENCODE_UINT32_COMMON(buf_out, i, field)\

#define ENCODE_UINT32_UNCOMMON_SIZE 6U
#define ENCODE_UINT32_UNCOMMON(buf_out, i, field)\
    {\
        uint32_t ui = i; \
        uint8_t uf = field; \
        buf_out[0] = 0x20U; \
        buf_out[1] = uf; \
        buf_out[2] =(ui >> 24 ) & 0xFFU; \
        buf_out[3] =(ui >> 16 ) & 0xFFU; \
        buf_out[4] =(ui >>  8 ) & 0xFFU; \
        buf_out[5] =(ui >>  0 ) & 0xFFU; \
        buf_out += ENCODE_UINT32_UNCOMMON_SIZE; \
    }
#define _02_XX_ENCODE_UINT32_UNCOMMON(buf_out, i, field)\
    ENCODE_UINT32_UNCOMMON(buf_out, i, field)\

#define ENCODE_LLS_SIZE 6U
#define ENCODE_LLS(buf_out, lls )\
    ENCODE_UINT32_UNCOMMON(buf_out, lls, 0x1B );
#define _02_27_ENCODE_LLS(buf_out, lls )\
    ENCODE_LLS(buf_out, lls );

#define ENCODE_FLS_SIZE 6U
#define ENCODE_FLS(buf_out, fls )\
    ENCODE_UINT32_UNCOMMON(buf_out, fls, 0x1A );
#define _02_26_ENCODE_FLS(buf_out, fls )\
    ENCODE_FLS(buf_out, fls );

#define ENCODE_TAG_SRC_SIZE 5
#define ENCODE_TAG_SRC(buf_out, tag )\
    ENCODE_UINT32_COMMON(buf_out, tag, 0x3U );
#define _02_03_ENCODE_TAG_SRC(buf_out, tag )\
    ENCODE_TAG_SRC(buf_out, tag );

#define ENCODE_TAG_DST_SIZE 5
#define ENCODE_TAG_DST(buf_out, tag )\
    ENCODE_UINT32_COMMON(buf_out, tag, 0xEU );
#define _02_14_ENCODE_TAG_DST(buf_out, tag )\
    ENCODE_TAG_DST(buf_out, tag );

#define ENCODE_SEQUENCE_SIZE 5
#define ENCODE_SEQUENCE(buf_out, sequence )\
    ENCODE_UINT32_COMMON(buf_out, sequence, 0x4U );
#define _02_04_ENCODE_SEQUENCE(buf_out, sequence )\
    ENCODE_SEQUENCE(buf_out, sequence );

#define ENCODE_FLAGS_SIZE 5
#define ENCODE_FLAGS(buf_out, tag )\
    ENCODE_UINT32_COMMON(buf_out, tag, 0x2U );
#define _02_02_ENCODE_FLAGS(buf_out, tag )\
    ENCODE_FLAGS(buf_out, tag );

#define ENCODE_SIGNING_PUBKEY_SIZE 35
#define ENCODE_SIGNING_PUBKEY(buf_out, pkey )\
    {\
        buf_out[0] = 0x73U;\
        buf_out[1] = 0x21U;\
        *(uint64_t*)(buf_out +  2) = *(uint64_t*)(pkey +  0);\
        *(uint64_t*)(buf_out + 10) = *(uint64_t*)(pkey +  8);\
        *(uint64_t*)(buf_out + 18) = *(uint64_t*)(pkey + 16);\
        *(uint64_t*)(buf_out + 26) = *(uint64_t*)(pkey + 24);\
        buf[34] = pkey[32];\
        buf_out += ENCODE_SIGNING_PUBKEY_SIZE;\
    }

#define _07_03_ENCODE_SIGNING_PUBKEY(buf_out, pkey )\
    ENCODE_SIGNING_PUBKEY(buf_out, pkey );

#define ENCODE_SIGNING_PUBKEY_NULL_SIZE 35
#define ENCODE_SIGNING_PUBKEY_NULL(buf_out )\
    {\
        buf_out[0] = 0x73U;\
        buf_out[1] = 0x21U;\
        *(uint64_t*)(buf_out+2) = 0;\
        *(uint64_t*)(buf_out+10) = 0;\
        *(uint64_t*)(buf_out+18) = 0;\
        *(uint64_t*)(buf_out+25) = 0;\
        buf_out += ENCODE_SIGNING_PUBKEY_NULL_SIZE;\
    }

#define _07_03_ENCODE_SIGNING_PUBKEY_NULL(buf_out )\
    ENCODE_SIGNING_PUBKEY_NULL(buf_out );


#define _0E_0E_ENCODE_HOOKOBJ(buf_out, hhash)\
{\
        uint8_t* hook0 = (hhash);\
        *buf_out++ = 0xEEU;   /* hook obj start */ \
        if (hook0 == 0) /* noop */\
        {\
            /* do nothing */ \
        }\
        else\
        {\
            *buf_out++ = 0x22U; /* flags = override */\
            *buf_out++ = 0x00U;\
            *buf_out++ = 0x00U;\
            *buf_out++ = 0x00U;\
            *buf_out++ = 0x01U;\
            if (hook0 == 0xFFFFFFFFUL) /* delete operation */ \
            {\
                *buf_out++ = 0x7BU; /* empty createcode */ \
                *buf_out++ = 0x00U;\
            }\
            else\
            {\
                *buf_out++ = 0x1FU; /* HookHash */\
                uint64_t* d = (uint64_t*)buf_out;\
                uint64_t* s = (uint64_t*)hook0;\
                *d++ = *s++;\
                *d++ = *s++;\
                *d++ = *s++;\
                *d++ = *s++;\
                buf_out+=32;\
            }\
        }\
        *buf_out++ = 0xE1U;\
}

#define PREPARE_HOOKSET(buf_out_master, maxlen, h, sizeout)\
    {\
        uint8_t* buf_out = (buf_out_master);                                            \
        uint8_t acc[20];                                                                \
        uint32_t cls = (uint32_t)ledger_seq();                                          \
        hook_account(SBUF(acc));                                                        \
        _01_02_ENCODE_TT                   (buf_out, ttHOOK_SET                     );  \
        _02_02_ENCODE_FLAGS                (buf_out, tfCANONICAL                    );  \
        _02_04_ENCODE_SEQUENCE             (buf_out, 0                              );  \
        _02_26_ENCODE_FLS                  (buf_out, cls + 1                        );  \
        _02_27_ENCODE_LLS                  (buf_out, cls + 5                        );  \
        uint8_t* fee_ptr = buf_out;                                                     \
        _06_08_ENCODE_DROPS_FEE            (buf_out, 0                              );  \
        _07_03_ENCODE_SIGNING_PUBKEY_NULL  (buf_out                                 );  \
        _08_01_ENCODE_ACCOUNT_SRC          (buf_out, acc                            );  \
        uint32_t remaining_size = (maxlen) - (buf_out - (buf_out_master));              \
        int64_t edlen = etxn_details((uint32_t)buf_out, remaining_size);                \
        buf_out += edlen;                                                               \
        *buf_out++ = 0xFBU;   /* hook array start */                                    \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[0]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[1]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[2]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[3]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[4]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[5]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[6]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[7]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[8]);                           \
        _0E_0E_ENCODE_HOOKOBJ               (buf_out, h[9]);                           \
        *buf_out++ = 0xF1U;  /* hook array end */                                       \
        sizeout = (buf_out - (buf_out_master));                                         \
        int64_t fee = etxn_fee_base(buf_out_master, sizeout);                           \
        _06_08_ENCODE_DROPS_FEE            (fee_ptr, fee                            );  \
    }

#ifdef HAS_CALLBACK
#define PREPARE_PAYMENT_SIMPLE_SIZE 270U
#else
#define PREPARE_PAYMENT_SIMPLE_SIZE 248U
#endif

#define PREPARE_PAYMENT_SIMPLE(buf_out_master, drops_amount_raw, to_address, dest_tag_raw, src_tag_raw)\
    {\
        uint8_t* buf_out = buf_out_master;\
        uint8_t acc[20];\
        uint64_t drops_amount = (drops_amount_raw);\
        uint32_t dest_tag = (dest_tag_raw);\
        uint32_t src_tag = (src_tag_raw);\
        uint32_t cls = (uint32_t)ledger_seq();\
        hook_account(SBUF(acc));\
        _01_02_ENCODE_TT                   (buf_out, ttPAYMENT                      );      /* uint16  | size   3 */ \
        _02_02_ENCODE_FLAGS                (buf_out, tfCANONICAL                    );      /* uint32  | size   5 */ \
        _02_03_ENCODE_TAG_SRC              (buf_out, src_tag                        );      /* uint32  | size   5 */ \
        _02_04_ENCODE_SEQUENCE             (buf_out, 0                              );      /* uint32  | size   5 */ \
        _02_14_ENCODE_TAG_DST              (buf_out, dest_tag                       );      /* uint32  | size   5 */ \
        _02_26_ENCODE_FLS                  (buf_out, cls + 1                        );      /* uint32  | size   6 */ \
        _02_27_ENCODE_LLS                  (buf_out, cls + 5                        );      /* uint32  | size   6 */ \
        _06_01_ENCODE_DROPS_AMOUNT         (buf_out, drops_amount                   );      /* amount  | size   9 */ \
        uint8_t* fee_ptr = buf_out;\
        _06_08_ENCODE_DROPS_FEE            (buf_out, 0                              );      /* amount  | size   9 */ \
        _07_03_ENCODE_SIGNING_PUBKEY_NULL  (buf_out                                 );      /* pk      | size  35 */ \
        _08_01_ENCODE_ACCOUNT_SRC          (buf_out, acc                            );      /* account | size  22 */ \
        _08_03_ENCODE_ACCOUNT_DST          (buf_out, to_address                     );      /* account | size  22 */ \
        int64_t edlen = etxn_details((uint32_t)buf_out, PREPARE_PAYMENT_SIMPLE_SIZE);       /* emitdet | size 1?? */ \
        int64_t fee = etxn_fee_base(buf_out_master, PREPARE_PAYMENT_SIMPLE_SIZE);                                    \ 
        _06_08_ENCODE_DROPS_FEE            (fee_ptr, fee                            );                               \
    }

#ifdef HAS_CALLBACK
#define PREPARE_PAYMENT_SIMPLE_TRUSTLINE_SIZE 309
#else
#define PREPARE_PAYMENT_SIMPLE_TRUSTLINE_SIZE 287
#endif
#define PREPARE_PAYMENT_SIMPLE_TRUSTLINE(buf_out_master, tlamt, to_address, dest_tag_raw, src_tag_raw)\
    {\
        uint8_t* buf_out = buf_out_master;\
        uint8_t acc[20];\
        uint32_t dest_tag = (dest_tag_raw);\
        uint32_t src_tag = (src_tag_raw);\
        uint32_t cls = (uint32_t)ledger_seq();\
        hook_account(SBUF(acc));\
        _01_02_ENCODE_TT                   (buf_out, ttPAYMENT                      );      /* uint16  | size   3 */ \
        _02_02_ENCODE_FLAGS                (buf_out, tfCANONICAL                    );      /* uint32  | size   5 */ \
        _02_03_ENCODE_TAG_SRC              (buf_out, src_tag                        );      /* uint32  | size   5 */ \
        _02_04_ENCODE_SEQUENCE             (buf_out, 0                              );      /* uint32  | size   5 */ \
        _02_14_ENCODE_TAG_DST              (buf_out, dest_tag                       );      /* uint32  | size   5 */ \
        _02_26_ENCODE_FLS                  (buf_out, cls + 1                        );      /* uint32  | size   6 */ \
        _02_27_ENCODE_LLS                  (buf_out, cls + 5                        );      /* uint32  | size   6 */ \
        _06_01_ENCODE_TL_AMOUNT            (buf_out, tlamt                          );      /* amount  | size  48 */ \
        uint8_t* fee_ptr = buf_out;\
        _06_08_ENCODE_DROPS_FEE            (buf_out, 0                              );      /* amount  | size   9 */ \
        _07_03_ENCODE_SIGNING_PUBKEY_NULL  (buf_out                                 );      /* pk      | size  35 */ \
        _08_01_ENCODE_ACCOUNT_SRC          (buf_out, acc                            );      /* account | size  22 */ \
        _08_03_ENCODE_ACCOUNT_DST          (buf_out, to_address                     );      /* account | size  22 */ \
        etxn_details((uint32_t)buf_out, PREPARE_PAYMENT_SIMPLE_TRUSTLINE_SIZE);             /* emitdet | size 1?? */  \
        int64_t fee = etxn_fee_base(buf_out_master, PREPARE_PAYMENT_SIMPLE_TRUSTLINE_SIZE);                          \ 
        _06_08_ENCODE_DROPS_FEE            (fee_ptr, fee                            );                               \
    }

#define SETUP_CURRENT_MONTH()\
uint16_t current_month = 0;\
{\
    int64_t s = ledger_last_time() + 946684800;\
    int64_t z = s / 86400 + 719468;\
    int64_t era = (z >= 0 ? z : z - 146096) / 146097;\
    uint64_t doe = (uint64_t)(z - era * 146097);\
    uint64_t yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;\
    int64_t y = (int64_t)(yoe) + era * 400;\
    uint64_t doy = doe - (365*yoe + yoe/4 - yoe/100);\
    uint64_t mp = (5*doy + 2)/153;\
    uint64_t d = doy - (153*mp+2)/5 + 1;\
    uint64_t m = mp + (mp < 10 ? 3 : -9);\
    y += (m <= 2);\
    current_month = y * 12 + m;\
    if (DEBUG) \
    {\
        TRACEVAR(y);\
        TRACEVAR(m);\
        TRACEVAR(d);\
        TRACEVAR(current_month);\
    }\
}

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
