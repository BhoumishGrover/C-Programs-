//cicular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextaddress;
};

struct Node* head;

void insert_start();
void insert_end();
void insert_between();
void delete(int search_val);
void display();

void insert_start(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    
    if(head == NULL){
        ptr->nextaddress=ptr;
        head=ptr;
    }
    else{
        struct Node* temp = head;
        while(temp->nextaddress != head){
            temp = temp->nextaddress;
        }//temp now points to last node

        ptr->nextaddress = head;
        head = ptr;
        temp->nextaddress = head;
    }
}//end of insert at start

void insert_end(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;

    struct Node* temp = head;
    while(temp->nextaddress != head){
        temp = temp->nextaddress;
    }//at end, temp points to the last node

    temp->nextaddress = ptr;
    ptr->nextaddress = head;
}//end of insert at end

void insert_between(){
    printf("Enter value you want to add\n");
    int value;
    scanf("%d",&value);

    printf("Enter value after which you want to add\n");
    int search;
    scanf("%d",&search);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;

    struct Node* temp = head;
    while(temp->nextaddress != head){
        if(temp->data == search){
            ptr->nextaddress = temp->nextaddress;
            temp->nextaddress = ptr;
            printf("Added! \n");
            break;
        }
        temp = temp->nextaddress;
    }
    
    if(temp->nextaddress == NULL){
        printf("couldn't find the value, pls try again\n");
    }
}//end of insert between

void delete(int search_val){
    struct Node* temp;
    temp=head;
    int index=0;
    int count=0;
    //finding the index of the node that has to be deleted
    while(temp->nextaddress != head){
        if(temp->data==search_val){
            printf("Index found\n");
            index = count;
        }
        count=count+1;
        temp=temp->nextaddress;
    }//end of index while
    if(temp->data == search_val){
        printf("Index found /n");
        index = count;
    }

    count=0;//resetting counter variable
    temp=head;//resetting temp pointer to the start of linked list.

    if(index==0){
        printf("deleting the very first element\n");
                head=temp->nextaddress;
                struct Node* temp2 = head;
                while(temp2->nextaddress != head){
                    temp2 = temp2->nextaddress;
                }//at end, temp2 points to the last node
    
                temp2->nextaddress = head;
                free(temp);
                free(temp2);
    }//deleting first element
    else{
        while(count<index){
            if(count==(index-1)){
                struct Node* ptr = temp->nextaddress;
                temp->nextaddress = ptr->nextaddress;
                free(ptr);
                break;
            }
            count++;
            temp=temp->nextaddress;
        }//end of while
    }//middle element 
}//end of delete

void display(){
    struct Node* ptr = head;
    printf("Printing....\n");
    while(ptr->nextaddress != head){
        printf("%d \n",ptr->data);
        ptr=ptr->nextaddress;
    }//end of while
    printf("%d \n",ptr->data);
}//end of display

int main(){
    int choice,ch;
    do{
        printf("Enter 1 to add at START\nEnter 2 to add at END\nEnter 3 to add BETWEEN nodes\nEnter 4 to delete\nEnter 5 to display list\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_start();
                    display();
                    break;
            case 2: insert_end();
                    display();
                    break;
            case 3: insert_between();
                    display();
                    break;
            case 4: display();
                    printf("Enter number you want to delete \n");
                    int src;
                    scanf("%d",&src);
                    delete(src);
                    break;
            case 5: display();
                    break;
            default: printf("Invalid choice,try again\n");
                     break;
        }//end of switch
        printf("Enter 1 to continue \n");
        scanf("%d",&ch);
    }while(ch>0);
    return 0;
}//end of main