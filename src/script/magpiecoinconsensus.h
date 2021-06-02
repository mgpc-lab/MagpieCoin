// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <stdint.h>

#if defined(BUILD_MAGPIECOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/magpiecoin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBMAGPIECOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAGPIECOINCONSENSUS_API_VER 1

using magpiecoinconsensus_error = enum magpiecoinconsensus_error_t
{
    magpiecoinconsensus_ERR_OK = 0,
    magpiecoinconsensus_ERR_TX_INDEX,
    magpiecoinconsensus_ERR_TX_SIZE_MISMATCH,
    magpiecoinconsensus_ERR_TX_DESERIALIZE,
    magpiecoinconsensus_ERR_AMOUNT_REQUIRED,
    magpiecoinconsensus_ERR_INVALID_FLAGS,
};

/** Script verification flags */
enum
{
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_NONE = 0,
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH = (1U << 0),                  // evaluate P2SH (BIP16) subscripts
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_ALL = magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | magpiecoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int magpiecoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen, unsigned int nIn, unsigned int flags, magpiecoinconsensus_error* err);

EXPORT_SYMBOL int magpiecoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen, unsigned int nIn, unsigned int flags, magpiecoinconsensus_error* err);

EXPORT_SYMBOL unsigned int magpiecoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

