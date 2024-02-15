#include <stdio.h>

#include "uuid.h"

void main(void) {
    printf(
        "random uuid: %s\n\n",
        random_uuid_string()
    );
}

