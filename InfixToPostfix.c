#include <stdio.h>
#include <stdio.h>
#include <string.h>

int top = -1;

void push(char stack[],char ch,int *top){
    (*top)++;
    stack[*top] = ch;
}//no need to check for stack full cause it will never happen

void pop(char stack[],int *top){
    if(*top==-1){}
    else{
        printf("%c ",stack[*top]);
        (*top)--;
    }
}//do nothing if the stack is empty

void peek(char stack[],int top){
    if(top==-1){}
    else{
        printf("%c ",stack[top]);
    }
}//end of peek

void main(){
    printf("Enter the size of your expression\n");
    int size;
    scanf("%d",&size);
    char str[20];
    printf("Enter the expression\n");
    scanf("\n");//need this for the next scanf() to work
    scanf("%[^\n]s",str);
    int length = strlen(str);
    char stack[size];
    for(int i=0;i<length;i++){
        if(isalpha(str[i]) || str[i]==" "){
            printf("%c ",str[i]);
        }//printing alphabet
        else{//if it is an operator
            if(top==-1 || stack[top]=="("){        //if stack is empty or contains "("
                push(stack,str[i],&top);               //push the incoming operator into the stack
            }
            else if(str[i]=="("){       //if incoming opertor is "("
                push(stack,str[i],&top);           //push it into the stack
            }
            else if(str[i]==")"){           //if the incoming symbol is ")"
                char check = peek(stack,top);        //pop the stack and print the operators until a "(" is found
                while(check!=")"){
                    pop(stack,&top);
                    check=peek(stack,top);
                }//popping all elements of stack till a "(" is found
                pop(stack,&top);//popping the "(" at the end
            }
            else if((str[i]=="^") && (stack[top]=="*" || stack[top]=="/" || stack[top]=="+" || stack[top]=="-")){
                push(stack,str[i],&top);
            }
            else if((str[i]=="*" || str[i]=="/") && (stack[top]=="+" || stack[top]=="-")){
                push(stack,str[i],&top);
            }
            else if((str[i]=="+" || str[i]=="-") && (stack[top]=="*" || stack[top]=="/" || stack[top]=="^")){
                pop(stack,&top);
                i=i-1;//again checking the input against the stack[top] of the stack
            }
            else if((str[i]=="*" || str[i]=="/") && stack[top]=="^"){
                pop(stack,&top);
                i=i-1;//again checking the input against the stack[top] of the stack
            }
            else if(stack[top]==-1){       //if stack is empty
                push(stack,str[i],&top);       //push incoming operator into the stack
            }
            else{
                if((str[i]=="*" || str[i]=="/") && (stack[top]=="/" || stack[top]=="*")){       
                    pop(stack,&top);      //associativity rule: L to R -> 
                    push(stack,str[i],&top);
                }
                else if((str[i]=="+" || str[i]=="-") && (stack[top]=="+" || stack[top]=="-")){       
                    pop(stack,&top);      //associativity rule: L to R -> 
                    push(stack,str[i],&top);
                }
                else if(str[i]=="^" && stack[top]=="^"){       //associativity rule: R to L->
                    push(stack,str[i],&top);
                }
            }
        }//checking operatos
    }//end of loop
}//end of main