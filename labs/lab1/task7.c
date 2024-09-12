#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    const char *text = "text.txt";
    char *str = "привет";
    file = fopen(text, "a");
    fputs(str, file);
    fclose(file);
    printf("Записано");
    return 0;
}
