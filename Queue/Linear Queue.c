#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

// Initialize Queue
void initializeQueue() {
    f = r = NULL;
    printf("Queue initialized\n");
}

// Traverse
void linkedlisttraversal(struct Node *ptr) 
{
    if(ptr == NULL){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// isEmpty
int isempty(){
    return (f == NULL);
}

// isFull
int isfull(){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if(n == NULL)
        return 1;
    free(n);
    return 0;
}

// Enqueue (Insert)
void enqueue(int val){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    
    if(n == NULL){
        printf("Queue is full\n");
    } 
    else{
        n->data = val;
        n->next = NULL;

        if(f == NULL){	
            f = r = n;
        } 
        else{
            r->next = n;
            r = n;
        }
    }
}

// Dequeue (Delete)
int dequeue(){
    int val = -1;

    if(f == NULL){
        printf("Queue is empty\n");
    }
    else{
        struct Node *ptr = f;
        val = ptr->data;				// same address not equal to same pointer
        f = f->next;
        free(ptr);

        if(f == NULL){
            r = NULL;
        }
    }
    return val;
}
/*
Condition
Kab execute hota hai
if(f == NULL) (top wala)
Jab queue already empty ho
if(f == NULL) r = NULL
Jab last node delete ho raha ho 
//rear reset
*/


// Main Program
int main() {

    int option, val;

    while(1) {
        printf("\n------MENU------\n");
        printf("1. Initialize Queue\n");
        printf("2. Display Queue\n");
        printf("3. Enqueue (Insert)\n");
        printf("4. Dequeue (Delete)\n");
        printf("5. IsEmpty\n");
        printf("6. IsFull\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                initializeQueue();
                break;

            case 2:
                linkedlisttraversal(f);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 4:
                val = dequeue();
                if(val != -1)
                    printf("Dequeued element: %d\n", val);
                break;

            case 5:
                if(isempty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 6:
                if(isfull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
