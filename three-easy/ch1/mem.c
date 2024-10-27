#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void Spin(int seconds) {
    sleep(seconds); 
}

int main(int argc, char *argv[]) {
    int *p = malloc(sizeof(int));
    assert(p != NULL);

    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0;

    while (1) {
        Spin(1); // Waits for 1 second
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }

    free(p); 
    return 0;
}
