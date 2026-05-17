#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
    char test[6] = "";
    fgets(test, sizeof test, stdin);
    printf("%s", test);
    return 0;
}
