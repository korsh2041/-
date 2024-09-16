
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prependToFile(const char *filename, const char *strToPrepend) {
    // Временный файл для хранения содержимого
    char tempFilename[] = "temp.txt";
    FILE *file, *tempFile;
    char buffer[256];

    
    file = fopen(filename, "r");
    

    // Открываем временный файл в режиме записи
    tempFile = fopen(tempFilename, "w");
    

    // Записываем новую строку в начало временного файла
    fputs(strToPrepend, tempFile);

    // Копируем содержимое оригинального файла во временный файл
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        fputs(buffer, tempFile);
    }

    // Закрываем файлы
    fclose(file);
    fclose(tempFile);

    // Заменяем оригинальный файл временным
    remove(filename);
    rename(tempFilename, filename);
}

int main() {
    const char *filename = "output.txt"; // Имя файла, куда будем добавлять строку
    char strToPrepend[256]; // Массив для строки, которую будем добавлять

    // Запрашиваем у пользователя строку для добавления
    printf("Введите строку для добавления в начало файла: ");
    fgets(strToPrepend, sizeof(strToPrepend), stdin);

    // Убираем символ новой строки, если он есть
    strToPrepend[strcspn(strToPrepend, "\n")] = '\0';

    // Вызываем функцию для добавления строки в начало файла
    prependToFile(filename, strToPrepend);

    printf("Строка записана");
    return 0;
}
