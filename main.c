#include <stdio.h>

#include "uuid.h"

int main(void) {
    printf(
        "random uuid: %s\n\n",
        random_uuid_string()
    );

    return 0;
}

