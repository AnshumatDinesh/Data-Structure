#include"stack.c"
int postfix(char *expression){
    Stack order;
    initialize(&order);
    int j=0;
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
                c=b/a;
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
