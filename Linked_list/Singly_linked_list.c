#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Traversal function
void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Insert after given position
struct Node *insertAtMiddle(struct Node *head, int data, int pos)
{
    struct Node *newNode = createNode(data);

    struct Node *temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete begining node
struct Node *deleteBeginningNode(struct Node *head)
{
    if (head == NULL)
{
    printf("List is empty!\n");
    return head;
}
    struct Node *temp = head;
    int deletedValue = temp->data;
	printf("%d element deleted\n", deletedValue);
    head = head->next;
    free(temp);
    return head;
}

//Delete Last node
struct Node *deleteEndNode(struct Node *head)
{
    struct Node *temp = head;
    struct Node *q = temp->next;
    
    if (head == NULL)
{
    printf("List is empty!\n");
    return head;
}

        if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    while (q->next != NULL)
    {
        temp = temp->next;
        q = q->next;
    }
    temp->next = NULL;
    int deletedValue = q->data;
	printf("%d element deleted\n", deletedValue);
	
    free(q);
    return head;
}

//CASE DELETE AT GIVEN INDEX
struct Node *deleteinbetween(struct Node *head, int index)
{
    struct Node *temp = head;
    struct Node *q = head->next;
    
    if (head == NULL)
{
    printf("List is empty!\n");
    return head;
}

    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        q = q->next;
        i++;
    }
	
	
	printf("%d element deleted\n", q->data);
	
    temp->next = q->next;
    free(q);
    return head;
}

// Main Menu Program
int main()
{
    struct Node *head = NULL;
    int choice, q, data, pos, index, temp;
	
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle\n");
        printf("3. Insert at End\n");
        printf("4. Traverse\n");
        printf("5.Delete first node\n");
        printf("6.Delete Last Node\n");
        printf("7.Delete by index\n");
        
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position (after which to insert): ");
            scanf("%d", &pos);
            head = insertAtMiddle(head, data, pos);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;

        case 4:
            traverse(head);
            break;

        case 5:
            head = deleteBeginningNode(head);
            break;

        case 6:
            head = deleteEndNode(head);
            break;

        case 7:
            printf("Enter the index:");
            scanf("%d",&index);
            head = deleteinbetween(head, index);
            break;

        case 8:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
