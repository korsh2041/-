#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Стек для хранения операторов
char stack[MAX];
int top = -1;

// Функция для добавления элемента в стек
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Функция для удаления элемента из стека
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // Возврат пустого символа, если стек пуст
}

// Функция для проверки, является ли символ оператором
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Функция для возврата приоритета оператора
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

// Функция для преобразования инфиксной записи в постфиксную
void infixToPostfix(const char *infix, char *postfix) {
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i]; // Добавляем цифры в постфиксное выражение
        } else if (infix[i] == '(') {
            push(infix[i]); // Добавляем открывающую скобку в стек
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Удаляем '(' из стека
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop(); // Добавляем операторы из стека
            }
            push(infix[i]); // Добавляем текущий оператор в стек
        }
    }
    // Добавляем оставшиеся элементы из стека в постфиксное выражение
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Завершаем строку
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    // Примеры выражений
    const char *expressions[] = {
        "3+(5*2)",
        "(8/4)-(6+2)",
        "7*3+(9-1)/2"
    };

    for (int i = 0; i < 3; i++) {
        strcpy(infix, expressions[i]);
        infixToPostfix(infix, postfix);
        printf("Infix: %s\nPostfix: %s\n\n", infix, postfix);
    }

    return 0;
}
