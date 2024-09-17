
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(const char *vivodtext, const char *zapis) {
    
    char text[] = "для временного хранения.txt";
    FILE *file1, *file2;
    
    char buffer[256];

    file1 = fopen(vivodtext, "r");
    
    file2 = fopen(text, "w");
    
    fputs(zapis, file2);

    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        fputs(buffer, file2);
    }

    
    fclose(file1);
    fclose(file2);

    remove(vivodtext);
    rename(text, vivodtext);
}

int main() {
    const char *vivodtext = "вывод.txt"; 
    char zapis[256]; 

    printf("Введите строку: ");
    fgets(zapis, sizeof(zapis), stdin);
    
    zapis[strcspn(zapis, "\n")] = '\0';

    func(vivodtext, zapis);

    printf("Строка записана");
    return 0;
}
