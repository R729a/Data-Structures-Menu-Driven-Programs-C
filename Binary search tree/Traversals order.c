#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorder(struct node* root){
    if(root != NULL){    
        printf(" %d", root->data);
        preorder(root->left);    
        preorder(root->right);    
    } 
}

void postorder(struct node* root){
    if(root != NULL){    
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->data);
    } 
}

void inorder(struct node* root){
    if(root != NULL){    
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    } 
}

struct node* insert(struct node* root, int data){
    if(root == NULL){
        return createNode(data);
    } 

    if(data < root->data) 
        root->left = insert(root->left, data);
    else if(data > root->data) 
        root->right = insert(root->right, data);

    return root;
}

int main(){

    struct node *root = NULL;
    int choice, value;

    while(1){
        printf("\n----MENU----\n");
        printf("1.Insert\n");
        printf("2.Preorder Traversal\n");
        printf("3.Inorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch(choice){

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
                
            case 2:
                printf("Preorder:");
                preorder(root);
                printf("\n") ;
                break;
                
            case 3:
                printf("Inorder:");
                inorder(root);
                printf("\n") ;
                break;

            case 4:
                printf("Postorder:");
                postorder(root);
                printf("\n") ;
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        } 
    }  

    return 0;
}
