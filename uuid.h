#ifndef _UUID_H_
#define _UUID_H_

#include <stdlib.h>
#include <time.h>

#define UUID_NUM_BITS   128
#define UUID_NUM_BYTES  UUID_NUM_BITS / 8
#define UUID_NUM_UINTS  UUID_NUM_BYTES / 2

#define UUID_STR_LEN            2 * UUID_NUM_BYTES + 4 + 1
#define UUID_NUM_CHAR_GROUPS    5

typedef struct uuid_t {
    unsigned int parts[UUID_NUM_UINTS];
} uuid_t;

char* random_uuid_string(unsigned int seed);

uuid_t generate_uuid(unsigned int seed);
void uuid_to_string(char* uuid_string, uuid_t uuid);

// internals

void write_uuid_byte(
    char* uuid_string,
    unsigned short int value,
    unsigned short int position
);
void write_uuid_uint(
    char* uuid_string,
    unsigned int value,
    unsigned short int position
);

#endif // UUID_H
