#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    const char *filename = "text.txt";
    char *str = "привет";
    file = fopen(filename, "a");
    fputs(str, file);
    fclose(file);
    printf("Записано");
    return 0;
}
