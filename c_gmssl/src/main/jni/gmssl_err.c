

#include <stdio.h>
#include <openssl/err.h>
#include "gmssl_err.h"

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(0,func,0)
# define ERR_REASON(reason) ERR_PACK(0,0,reason)

static ERR_STRING_DATA JNI_str_functs[] = {
    {ERR_FUNC(JNI_F_JAVA_GMSSL_DERIVEKEY), "Java_GmSSL_deriveKey"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_DIGEST), "Java_GmSSL_digest"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GENERATERANDOM), "Java_GmSSL_generateRandom"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETCIPHERBLOCKSIZE),
     "Java_GmSSL_getCipherBlockSize"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETCIPHERIVLENGTH),
     "Java_GmSSL_getCipherIVLength"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETCIPHERKEYLENGTH),
     "Java_GmSSL_getCipherKeyLength"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETCIPHERS), "Java_GmSSL_getCiphers"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETDERIVEKEYALGORITHMS),
     "Java_GmSSL_getDeriveKeyAlgorithms"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETDIGESTBLOCKSIZE),
     "Java_GmSSL_getDigestBlockSize"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETDIGESTLENGTH),
     "Java_GmSSL_getDigestLength"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETDIGESTS), "Java_GmSSL_getDigests"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETERRORSTRINGS),
     "Java_GmSSL_getErrorStrings"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETMACS), "Java_GmSSL_getMacs"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETPUBLICKEYENCRYPTIONS),
     "Java_GmSSL_getPublicKeyEncryptions"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETSIGNALGORITHMS),
     "Java_GmSSL_getSignAlgorithms"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_GETVERSIONS), "Java_GmSSL_getVersions"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_MAC), "Java_GmSSL_mac"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_PUBLICKEYDECRYPT),
     "Java_GmSSL_publicKeyDecrypt"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_PUBLICKEYENCRYPT),
     "Java_GmSSL_publicKeyEncrypt"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_SIGN), "Java_GmSSL_sign"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_SYMMETRICDECRYPT),
     "Java_GmSSL_symmetricDecrypt"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_SYMMETRICENCRYPT),
     "Java_GmSSL_symmetricEncrypt"},
    {ERR_FUNC(JNI_F_JAVA_GMSSL_VERIFY), "Java_GmSSL_verify"},
    {ERR_FUNC(JNI_F_PRINT_ERRORS_CB), "print_errors_cb"},
    {0, NULL}
};

static ERR_STRING_DATA JNI_str_reasons[] = {
    {ERR_REASON(JNI_R_BAD_ARGUMENT), "bad argument"},
    {ERR_REASON(JNI_R_CMAC_ERROR), "cmac error"},
    {ERR_REASON(JNI_R_ERRORS_STACK_ERROR), "errors stack error"},
    {ERR_REASON(JNI_R_GMSSL_RNG_ERROR), "gmssl rng error"},
    {ERR_REASON(JNI_R_HMAC_ERROR), "hmac error"},
    {ERR_REASON(JNI_R_INVALID_CIPHER), "invalid cipher"},
    {ERR_REASON(JNI_R_INVALID_DERIVE_KEY_ALGOR), "invalid derive key algor"},
    {ERR_REASON(JNI_R_INVALID_DIGEST), "invalid digest"},
    {ERR_REASON(JNI_R_INVALID_IV_LENGTH), "invalid iv length"},
    {ERR_REASON(JNI_R_INVALID_KEY_LENGTH), "invalid key length"},
    {ERR_REASON(JNI_R_INVALID_LENGTH), "invalid length"},
    {ERR_REASON(JNI_R_INVALID_PRIVATE_KEY), "invalid private key"},
    {ERR_REASON(JNI_R_INVALID_PUBLIC_KEY), "invalid public key"},
    {ERR_REASON(JNI_R_INVALID_PUBLIC_KEY_ENCRYPTION_ALGOR),
     "invalid public key encryption algor"},
    {ERR_REASON(JNI_R_INVALID_SIGN_ALGOR), "invalid sign algor"},
    {ERR_REASON(JNI_R_IV_LENGTH), "iv length"},
    {ERR_REASON(JNI_R_JNI_MALLOC_FAILURE), "jni malloc failure"},
    {ERR_REASON(JNI_R_KEY_LENGTH), "key length"},
    {ERR_REASON(JNI_R_NONSUPPORTED_CIPHER), "nonsupported cipher"},
    {0, NULL}
};

#endif

#ifdef JNI_LIB_NAME
static ERR_STRING_DATA JNI_lib_name[] = {
    {0, JNI_LIB_NAME},
    {0, NULL}
};
#endif

static int JNI_lib_error_code = 0;
static int JNI_error_init = 1;

static int ERR_load_JNI_strings(void)
{
    if (JNI_lib_error_code == 0)
        JNI_lib_error_code = ERR_get_next_error_library();

    if (JNI_error_init) {
        JNI_error_init = 0;
#ifndef OPENSSL_NO_ERR
        ERR_load_strings(JNI_lib_error_code, JNI_str_functs);
        ERR_load_strings(JNI_lib_error_code, JNI_str_reasons);
#endif

#ifdef JNI_LIB_NAME
        JNI_lib_name->error = ERR_PACK(JNI_lib_error_code, 0, 0);
        ERR_load_strings(0, JNI_lib_name);
#endif
    }
    return 1;
}

static void ERR_unload_JNI_strings(void)
{
    if (JNI_error_init == 0) {
#ifndef OPENSSL_NO_ERR
        ERR_unload_strings(JNI_lib_error_code, JNI_str_functs);
        ERR_unload_strings(JNI_lib_error_code, JNI_str_reasons);
#endif

#ifdef JNI_LIB_NAME
        ERR_unload_strings(0, JNI_lib_name);
#endif
        JNI_error_init = 1;
    }
}

static void ERR_JNI_error(int function, int reason, char *file, int line)
{
    if (JNI_lib_error_code == 0)
        JNI_lib_error_code = ERR_get_next_error_library();
    ERR_PUT_error(JNI_lib_error_code, function, reason, file, line);
}
