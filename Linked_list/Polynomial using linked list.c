#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coef;
    int expo;
    struct Node* next;
};


struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}


struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

if (head == NULL || head->expo < e) {	
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != NULL && temp->next->expo > e) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->expo);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}


struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo == p2->expo) {
            result = insert(result, p1->coef + p2->coef, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo) {
            result = insert(result, p1->coef, p1->expo);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coef, p2->expo);
            p2 = p2->next;
        }
    }

    
    while (p1 != NULL) {
        result = insert(result, p1->coef, p1->expo);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insert(result, p2->coef, p2->expo);
        p2 = p2->next;
    }

    return result;
}


int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, c, e, n;

    while (1) {
        printf("\n--- Polynomial Menu ---\n");
        printf("1. Insert in Polynomial 1\n");
        printf("2. Insert in Polynomial 2\n");
        printf("3. Display Polynomial 1\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Display Result\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter coef and expo: ");
                    scanf("%d %d", &c, &e);
                    poly1 = insert(poly1, c, e);
                }
                break;

            case 2:
                printf("Enter number of terms: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter coef and expo: ");
                    scanf("%d %d", &c, &e);
                    poly2 = insert(poly2, c, e);
                }
                break;

            case 3:
                printf("Polynomial 1: ");
                display(poly1);
                break;

            case 4:
                printf("Polynomial 2: ");
                display(poly2);
                break;

            case 5:
                result = addPoly(poly1, poly2);
                printf("Polynomials added successfully!\n");
                break;

            case 6:
                printf("Resultant Polynomial: ");
                display(result);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
