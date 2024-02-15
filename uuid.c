#include "uuid.h"

char* random_uuid_string(void) {
    uuid_t uuid = generate_uuid();

    char* result = malloc(UUID_STR_LEN);
    uuid_to_string(result, uuid);

    return result;
}

uuid_t generate_uuid(void) {
    time_t t;
    srand((unsigned) time(&t));

    uuid_t uuid;
    for (int i = 0; i < UUID_NUM_UINTS; i++) {
        uuid.parts[i] = rand();
    }

    // version 4
    uuid.parts[3] &= 0x0fff;
    uuid.parts[3] |= 0x4000;

    // variant 1
    uuid.parts[4] &= 0x3fff;
    uuid.parts[4] |= 0x8000;

    return uuid;
}

void write_uuid_byte(
    char* uuid_string,
    unsigned short int value,
    unsigned short int position
) {
    unsigned short int first = value & 0xf;
    uuid_string[position] = hex_symbols[first];

    unsigned short int second = value >> 4;
    uuid_string[position + 1] = hex_symbols[second];
}

void write_uuid_uint(
    char* uuid_string,
    unsigned int value,
    unsigned short int position
) {
    unsigned short int first = value & 0xff;
    write_uuid_byte(uuid_string, first, position);

    unsigned short int second = value >> 8;
    write_uuid_byte(uuid_string, second, position + 2);
}

void uuid_to_string(char* uuid_string, uuid_t uuid) {
    unsigned short int current = 0;
    unsigned short int string_pos = 0;
    for (int group = 0; group < UUID_NUM_CHAR_GROUPS; group++) {
        char chars = uuid_char_groups[group];

        for (int i = 0; i < chars; i += 4) {
            write_uuid_uint(
                uuid_string,
                uuid.parts[current],
                string_pos
            );

            current += 1;
            string_pos += 4;
        }

        uuid_string[++string_pos] = '-';
    }
    uuid_string[++string_pos] = 0;
}

