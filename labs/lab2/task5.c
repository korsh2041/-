#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PRODUCTS 100

// Структура для хранения данных о товаре
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Product;

// Функция для сравнения двух товаров (для сортировки)
int compareProducts(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return (productA->price > productB->price) - (productA->price < productB->price);
}

// Функция для чтения данных о товарах из файла
int readProductsFromFile(const char *filename, Product *products) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Ошибка открытия файла %s для чтения.\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %f", products[count].name, &products[count].price) == 2) {
        count++;
        if (count >= MAX_PRODUCTS) {
            break; // Проверка на переполнение массива
        }
    }

    fclose(file);
    return count;
}

// Функция для записи отсортированных данных в файл
void writeProductsToFile(const char *filename, Product *products, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Ошибка открытия файла %s для записи.\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f\n", products[i].name, products[i].price);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    // Проверка количества аргументов
    if (argc != 3) {
        printf("Используйте: %s <входной файл> <выходной файл>\n", argv[0]);
        return 1;
    }

    Product products[MAX_PRODUCTS];
    int count = readProductsFromFile(argv[1], products);

    if (count == 0) {
        printf("Нет данных для сортировки.\n");
        return 1;
    }

    // Сортировка товаров по цене
    qsort(products, count, sizeof(Product), compareProducts);

    // Запись отсортированных данных в выходной файл
    writeProductsToFile(argv[2], products, count);

    printf("Данные успешно отсортированы и записаны в файл %s.\n", argv[2]);
    return 0;
}
