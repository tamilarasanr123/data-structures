#include<stdio.h>
#include<ctype.h>
#define MAX 100
int top=-1;
char stack[MAX];
void push(char value){
    if(top==MAX-1){
        printf("stack is in overflow\n");
    }
    else{
        top++;
        stack[top]=value;
        
    }
}
char pop(){
    if(top==-1){
        printf("stack is in underflow\n");
    }
    else{
        char value=stack[top];
        top--;
        return value;
    }
}
int precedence(char op){
    if(op='^')
        return 3;
    if(op=='*'||op=='/'||op=='%'){
        return 2;
    }
    if(op=='+'||op=='-'){
        return 1;
    }
    return 0;
}
void infixtopostfix(char infix[]){
    int i=0;
    char ch;
    while (infix[i]!='\0'){
        ch=infix[i];
        if(isalnum(ch)){
            printf("%c",ch);
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && stack[top]!='('){
                printf("%c", pop());
            }
            if(top!=-1){
                pop();
            }
        }
        else{
            while(top!=-1 && stack[top]!='(' && precedence(stack[top]>=precedence(ch))){
                printf("%c", pop());
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
        printf("%c", pop());
    }
}
int main(){
    char infix[MAX];
    printf("enter the infix expression\n");
    scanf("%s",infix);
    printf("postfix expression\n");
    infixtopostfix(infix);
    return 0;
}
