#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

// Only logic (no printing)
int isEmpty(struct stack *ptr) {
    return (ptr-> == -1);
}

int isFull(struct stack *ptr) {
    return (ptr->top == ptr->size - 1);
}

void push(struct stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } else {
        s->top++;
        s->arr[s->top] = val;
        printf(" %d pushed successfully\n", val);
    }
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf(" Stack Underflow!\n");
        return -1;
    } else {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(struct stack *s, int i) {
    int index = s->top - i + 1;

    if (index < 0 || index > s->top) {
        printf("Invalid position\n");
        return -1;
    } else {
        return s->arr[index];
    }
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf(" Stack is empty\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int choice, val, pos;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            push(s, val);
            break;

        case 2:
            val = pop(s);
            if (val != -1)
                printf(" Popped: %d\n", val);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            val = peek(s, pos);
            if (val != -1)
                printf("Value at position %d: %d\n", pos, val);
            break;

        case 4:
            display(s);
            break;

        case 5:
            if (isEmpty(s))
                printf("Stack is Empty\n");
            else
                printf("Stack is NOT Empty\n");
            break;

        case 6:
            if (isFull(s))
                printf(" Stack is Full\n");
            else
                printf(" Stack is NOT Full\n");
            break;
 
        case 7:
            printf("Exiting...\n");
            free(s->arr);
            free(s);
            exit(0);

        default:
            printf(" Invalid choice!\n");
        }
    }

    return 0;
}
