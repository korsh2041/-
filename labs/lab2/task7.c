#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    if (!isFull(s)) {
        s->items[++(s->top)] = item;
    } else {
        printf("Стек переполнен\n");
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Стек пуст\n");
        exit(EXIT_FAILURE);
    }
}

int evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack);
    char* token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } else {
            int rightOperand = pop(&stack);
            int leftOperand = pop(&stack);
            switch (token[0]) {
                case '+':
                    push(&stack, leftOperand + rightOperand);
                    break;
                case '-':
                    push(&stack, leftOperand - rightOperand);
                    break;
                case '*':
                    push(&stack, leftOperand * rightOperand);
                    break;
                case '/':
                    if (rightOperand == 0) {
                        printf("Ошибка: Деление на ноль\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, leftOperand / rightOperand);
                    break;
                default:
                    printf("Недопустимый оператор: %s\n", token);
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char expression[256];
    while (fgets(expression, sizeof(expression), file)) {
        printf("Результат выражения: %d\n", evaluatePostfix(expression));
    }

    fclose(file);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 256

typedef struct {
    int items[N];
    int top;
} Stack;

void inStack(Stack* s) {
    s->top = -1;
}

int full(Stack* s) {
    return s->top == N - 1;
}

int pust(Stack* s) {
    return s->top == -1;
}

void stackfull(Stack* s, int sch) {
    if (!full(s)) {
        s->items[++(s->top)] = sch;
    } else {
        printf("Стек переполнен\n");
    }
}

int stackpust(Stack* s) {
    if (!pust(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Стек пуст\n");
        exit(EXIT_FAILURE);
    }
}

int preobraz(char* str) {
    Stack stack;
    inStack(&stack);
    char *text = strtok(atoi(str), " ");

    while (text != NULL) {
        if (isdigit(text[0])) {
            stackfull(&stack, atoi(text));
        } else {
            int prav = stackpust(&stack);
            int levo = stackpust(&stack);
            switch (text[0]) {
                case '+':
                    stackfull(&stack, levo + prav);
                    break;
                case '-':
                    stackfull(&stack, levo - prav);
                    break;
                case '*':
                    stackfull(&stack, levo * prav);
                    break;
                case '/':
                    if (prav == 0) {
                        printf("Ошибка: Деление на ноль\n");
                        exit(EXIT_FAILURE);
                    }
                    stackfull(&stack, levo / prav);
                    break;
                default:
                    printf("Недопустимый оператор: %s\n", text);
                    exit(EXIT_FAILURE);
            }
        }
        text =(int *) strtok(NULL, " ");
    }
    return stackpust(&stack);
}

int main() {
    FILE* file = fopen("input.txt", "r");

    char str[N];
    while (fgets(str, sizeof(str), file)) {
        printf("Результат выражения: %d\n", preobraz(str));
    }

    fclose(file);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 256

typedef struct {
    int items[N];
    int top;
} Stack;

void inStack(Stack *s) {
    s->top = -1;
}

int full(Stack *s) {
    return s->top == N - 1;
}

int pust(Stack *s) {
    return s->top == -1;
}

void stackfull(Stack *s, int sch) {
    if (!full(s)) {
        s->items[++(s->top)] = sch;
    } else {
        printf("Стек переполнен\n");
    }
}

int stackpust(Stack *s) {
    if (!pust(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Стек пуст\n");
        exit(EXIT_FAILURE);
    }
}

int preobraz(char *str) {
    Stack stack;
    inStack(&stack);
    
    char *text = strtok(str, " ");
    
    
    while (text != NULL) {
        for(int i = 0; text[i]; i++){
            if (isdigit(text[i])) {
                stackfull(&stack, atoi(text));
            } else {
                int prav = stackpust(&stack);
                int levo = stackpust(&stack);
                switch (text[i]) {
                    case '+':
                        stackfull(&stack, levo + prav);
                        break;
                    case '-':
                        stackfull(&stack, levo - prav);
                        break;
                    case '*':
                        stackfull(&stack, levo * prav);
                        break;
                    case '/':
                        if (prav == 0) {
                            printf("Ошибка: Деление на ноль\n");
                            exit(EXIT_FAILURE);
                        }
                        stackfull(&stack, levo / prav);
                        break;
                    default:
                        printf("Недопустимый оператор: %s\n", text);
                        exit(EXIT_FAILURE);
                }
            }
            text = strtok(NULL, " ");
        }
    }
    
    return stackpust(&stack);
}

int main() {
    FILE* file = fopen("input.txt", "r");

    char str[N];
    while (fgets(str, sizeof(str), file)) {
        printf("Результат выражения: %d\n", preobraz(str));
    }

    fclose(file);
    return 0;
}
