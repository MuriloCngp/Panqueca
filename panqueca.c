#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->data[stack->top];
}

void sortStack(Stack* stack) {
    Stack* tempStack = createStack(stack->capacity);
    while (!isEmpty(stack)) {
        int temp = pop(stack);
        while (!isEmpty(tempStack) && peek(tempStack) > temp) {
            push(stack, pop(tempStack));
        }
        push(tempStack, temp);
    }
    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }
    free(tempStack->data);
    free(tempStack);
}

void printStack(Stack* stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    int n = 5; // Substitua pelo valor desejado
    Stack* stack = createStack(n);

    // Preenchendo a pilha com valores de 1 a n
    for (int i = 1; i <= n; i++) {
        push(stack, i);
    }

    printf("Pilha original:\n");
    printStack(stack);

    sortStack(stack);

    printf("Pilha ordenada:\n");
    printStack(stack);

    free(stack->data);
    free(stack);

    return 0;
}
