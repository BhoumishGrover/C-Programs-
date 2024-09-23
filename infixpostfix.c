//convert infix expression to postfix
#include<stdio.h>
#include<string.h>
#define max 100

int push(char stack[max],int top,char data){
    if (top==max-1){
        printf("Stack Overflow");
        return top;
    }
    else{
        top=top+1;
        stack[top]=data;
    }

    return top;
}

int pop(int top){
    if (top==-1){
        printf("Stack Underflow");
        return top;
    }
    else{
        top=top-1;
    }

    return top;
}

int priority(char op){
    if(op=='*' || op=='/'){
        return 3;
    }
    else if(op=='+' || op=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isop(char op){
    if(op=='*' || op=='/' || op=='+' || op=='-'){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    char str[max]="A+B/C";
    char stack[max];
    int top=-1;
    int i=0;

    str[strcspn(str,"\n")]='\0';

    for(i=0;str[i]!='\0';i++)
    {
        if(!isop(str[i])){
            printf("%c",str[i]);
        }
        else {
            while(top!=-1 && priority(stack[top])>=priority(str[i])){
                printf("%c",stack[top]);
                top=pop(top);
            }
        top=push(stack,top,str[i]);
        }

    }
    while(top!=-1){
        printf("%c",stack[top]);
        top=pop(top);
    }
return 0;
}
