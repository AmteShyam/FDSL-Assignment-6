#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("Pushed %d to stack\n", value);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        int popped = s->items[(s->top)--];
        printf("Popped %d from stack\n", popped);
        return popped;
    }
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

int main() {
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    display(&myStack);

    printf("Top element is: %d\n", peek(&myStack));

    pop(&myStack);
    display(&myStack);

    return 0;
}
