#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};
struct Node* root;

void add_BST();
void Inorder_print(struct Node* find);
void Postorder_print(struct Node* find);
void Preorder_print(struct Node* find);
void search_BST(int num);

void add_BST(){
    int new;
    printf("Enter number you want to add\n");
    scanf("%d",&new);

    struct Node* find = root;   //pointer to iterate through the tree
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));   //the new node which has to be added to the tree

    if(find == NULL){
        ptr->data = new;
        ptr->right = NULL;
        ptr->left = NULL;
        root = ptr;
        printf("Created the root\n");
    }//new node is first node
    else{
        while(find != NULL){
            if(new > find->data){
                if(find->right == NULL){
                    ptr->data = new;
                    ptr->right = NULL;
                    ptr->left = NULL;
                    find-> right = ptr;
                    printf("Node successfully added at Right \n");
                    break;
                }
                else{
                    find = find->right;
                }
            }
            else if(new < find->data){
                if(find->left == NULL){
                    ptr->data = new;
                    ptr->right = NULL;
                    ptr->left = NULL;
                    find->left = ptr;
                    printf("Node successfully added at Left\n");
                    break;
                }
                else{
                    find = find->left;
                }
            }
            else{
                printf("Same number can't be added twice in a BST \n");
                break;
            }
        }//end of while
    }//new node is not first node 
}//end of add

void Inorder_print(struct Node* find){   
    if(find != NULL){
        Inorder_print(find->left);
        printf("%d ",find->data);
        Inorder_print(find->right);
    } 
}//end of Inorder

void Postorder_print(struct Node* find){
    if(find != NULL){
        Postorder_print(find->left);
        Postorder_print(find->right);
        printf("%d ",find->data);
    }
}//end of Postorder

void Preorder_print(struct Node* find){
    if(find != NULL){
        printf("%d ",find->data);
        Preorder_print(find->left);
        Preorder_print(find->right);
    }
}//end of Preorder

void search_BST(int num){
    struct Node* find = root;
    while(find != NULL){
        if(num > find->data){
            find = find->right;
        }
        else if(num < find->data){
            find = find->left;
        }
        else{
            printf("%d was found in the tree \n",num);
            break;
        }
    }
    if(find == NULL) printf("%d was NOT found!",num);
}//end of search in tree

int main(){
    int ch, choice;
    do{
        printf("Enter 1 to add a new leaf \nEnter 2 to Traverse the tree \nEnter 3 to search for an element\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_BST();
                    break;
            case 2: printf("In-order: ");
                    Inorder_print(root);
                    printf("\nPre-order: ");
                    Preorder_print(root);
                    printf("\nPost-order: ");
                    Postorder_print(root);
                    printf("\n");
                    break;
            case 3: printf("Enter the element you want to search for \n");
                    int src;
                    scanf("%d",&src);
                    search_BST(src);
                    break;
            default: printf("Try again\n");
                    break;
        }//end of switch
        printf("Enter 1 to continue, 0 to exit\n");
        scanf("%d",&ch);
    }while(ch>0);
    return 0;
}//end of main