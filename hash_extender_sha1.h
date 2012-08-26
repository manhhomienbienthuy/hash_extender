#ifndef __HASH_EXTENDER_SHA1_H__
#define __HASH_EXTENDER_SHA1_H__

#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <openssl/sha.h>

#include "util.h"

#define SHA1_BLOCK 64

int sha1_check_signature(uint8_t *secret, size_t secret_length, uint8_t *data, size_t data_length, uint8_t *signature);
uint8_t *sha1_append_data(uint8_t *data, size_t data_length, size_t secret_length, uint8_t *append, size_t append_length, size_t *new_length);
void sha1_gen_signature(uint8_t *secret, size_t secret_length, uint8_t *data, size_t data_length, uint8_t signature[SHA_DIGEST_LENGTH]);
void sha1_gen_signature_evil(size_t secret_length, size_t data_length, uint8_t original_signature[SHA_DIGEST_LENGTH], uint8_t *append, size_t append_length, uint8_t new_signature[SHA_DIGEST_LENGTH]);



/* Test code */
void sha1_test_normal_signture_generation();
void sha1_test_evil_signature_generation();
void sha1_test_basic_extension();
void sha1_test_different_length_secret();
void sha1_test_different_length_data();
void sha1_test_different_length_append();

#endif
