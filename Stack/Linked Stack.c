#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("stack overflow");
        ;
    }
    n->data = x;
    n->next = top;
    top = n;
    return top;
}

int pop()
{
    if (isEmpty(top))
    {
        printf("stack underflow\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int length(struct Node *top)
{
    int count = 0;
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int peek(int pos)
{
    struct Node *ptr = top;
    int count = 1;
    for (int i = 1; (i < pos && ptr != NULL); i++)
    {
        ptr = ptr->next;
        count++;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int choice, val, pos;
    int len;

    // printf("length %d",len);
    while (1)
    {
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

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            top = push(top, val);

            break;

        case 2:
            val = pop();
            if (val != -1)
                printf(" Popped: %d\n", val);
            break;

        case 3:
            printf("Enter position: ");

            if (scanf("%d", &pos) == 1)
            {
                if (pos >= 1 && pos <= len)
                {
                    val = peek(pos);
                    printf("%d element at position %d\n", val, pos);
                }
                else
                {
                    printf("Invalid position!\n");
                }
            }
            break;

        case 4:
            linkedlisttraversal(top);
            len = length(top);
            break;

        case 5:
            if (isEmpty(top))
                printf("Stack is Empty\n");
            else
                printf("Stack is NOT Empty\n");
            break;

        case 6:
            if (isFull(top))
                printf(" Stack is Full\n");
            else
                printf(" Stack is NOT Full\n");
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf(" Invalid choice!\n");
        }
    }

    return 0;
}
