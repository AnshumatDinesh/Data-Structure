#include"stack.c"//Importing the stack ADT
/*
The following function evaluates an expression written in postfix
And returns its integer value
It employs a stack to Evaluate the expression
*/
int postfix(char *expression){
    Stack order;//Declaring a stack to store the numbers
    initialize(&order);//initializing the stack
    int j=0;//
    while(*(expression+j)!='\0'){
        int a,b,c;
        if (*(expression+j)>=0x30 AND *(expression+j)<=0x39){
            push(&order,*(expression+j)-0x30);
        }
        else{
            switch (*(expression+j)){
            case '+':
                a=pop(&order);
                b=pop(&order);
                c=b+a;
                push(&order,c);
                break;
            case '-':
                a=pop(&order);
                b=pop(&order);
                c=b-a;
                push(&order,c);
                break;
            case '*':
                a=pop(&order);
                b=pop(&order);
                c=b*a;
                push(&order,c);
                break;
            case '/':
                a=pop(&order);
                b=pop(&order);
                c=b/(float)a;
                push(&order,c);
                break;
            
            default:
                break;
            }
        }
        
        j++;
    }
    return pop(&order);
}
int main(){
    char exp[100];
    printf("Enter the Expression: \n");
    scanf("%s",exp);
    printf("%d",postfix(exp));
}