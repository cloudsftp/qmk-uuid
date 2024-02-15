#include <stdio.h>
#include <time.h>

#include "uuid.h"

int main(void) {
    time_t* t;
    unsigned int seed = time(t);

    printf(
        "random uuid: %s\n\n",
        random_uuid_string(seed)
    );

    return 0;
}

