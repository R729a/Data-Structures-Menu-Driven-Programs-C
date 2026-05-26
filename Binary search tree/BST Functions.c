#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Create Node
struct node* createNode(int data){
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Traversals
void inOrder(struct node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Insert
struct node* insert(struct node *root, int key){
    if(root == NULL){
        return createNode(key);
    }

    struct node *prev = NULL;
    struct node *ptr = root;

    while(ptr != NULL){
        prev = ptr;
        if(key == ptr->data){
            printf("Cannot insert %d, already in BST\n", key);
            return root;
        }
        else if(key < ptr->data){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }

    struct node* newNode = createNode(key);
    if(key < prev->data){
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }

    return root;
}

// Search
struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

// Inorder Predecessor
struct node* inOrderPredecessor(struct node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

// Delete Node
struct node* deleteNode(struct node* root, int value){
    struct node* iPre;

    if(root == NULL){
        return NULL;
    }

    // Leaf node
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else{
        // Node found

        if(root->left != NULL){
            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
        else{
            struct node* temp = root->right;
            free(root);
            return temp;
        }
    }

    return root;
}

// Main Function
int main(){
    struct node *root = NULL;
    int choice, value;

    while(1){
        printf("\n----MENU----\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display (Inorder)\n");
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
                printf("Enter the element to search: ");
                scanf("%d", &value);

                struct node* found = searchIter(root, value);
                if(found != NULL){
                    printf("Element found: %d\n", found->data);
                }
                else{
                    printf("Element not found\n");
                }
                break;
                
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
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
