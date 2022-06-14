#include"stack.c"
char * infix(char expression[]){
    Stack order;
    initialize(&order);
    int j=0,i=0;
    char *postfix;
    postfix=(char*)malloc(100*sizeof(char));
    while(*(expression+j)!='\0'){
        if (*(expression+j)>=0x30 AND *(expression+j)<=0x39){
            *(postfix+i)=*(expression+j);
            i++;
        }
        else{
            switch(*(expression+j)){
                case '-':
                    if(isempty(&order)){
                        push(&order,2);
                    }
                    else{
                        int a=pop(&order);
                        if(a<1){
                            push(&order,a);
                            push(&order,1);
                        }
                        else{
                            push(&order,1);
                            if(a==1){
                                *(postfix+i)='-';
                                i++;
                            }
                            else if(a==2){
                                *(postfix+i)='+';
                                i++;
                            }
                            else if(a==3){
                                *(postfix+i)='*';
                                i++;
                            }
                            else if(a==4){
                                *(postfix+i)='/';
                                i++;
                            }
                        }
                    }

                    break;
                case '+':
                    if(isempty(&order)){
                        push(&order,2);
                    }
                    else{
                        int a=pop(&order);
                        if(a<2){
                            push(&order,a);
                            push(&order,2);
                        }
                        else{
                            push(&order,2);
                            if(a==1){
                                *(postfix+i)='-';
                                i++;
                            }
                            else if(a==2){
                                *(postfix+i)='+';
                                i++;
                            }
                            else if(a==3){
                                *(postfix+i)='*';
                                i++;
                            }
                            else if(a==4){
                                *(postfix+i)='/';
                                i++;
                            }
                        }
                    }

                    break;
                case '*':
                    if(isempty(&order)){
                        push(&order,3);
                    }
                    else{
                        int a=pop(&order);
                        if(a<3){
                            push(&order,a);
                            push(&order,3);
                        }
                        else{
                            push(&order,3);
                            if(a==1){
                                *(postfix+i)='-';
                                i++;
                            }
                            else if(a==2){
                                *(postfix+i)='+';
                                i++;
                            }
                            else if(a==3){
                                *(postfix+i)='*';
                                i++;
                            }
                            else if(a==4){
                                *(postfix+i)='/';
                                i++;
                            }
                        }
                    }

                    break;
                case '/':
                    if(isempty(&order)){
                        push(&order,2);
                    }
                    else{
                        int a=pop(&order);
                        if(a<4){
                            push(&order,a);
                            push(&order,4);
                        }
                        else{
                            push(&order,4);
                            if(a==1){
                                *(postfix+i)='-';
                                i++;
                            }
                            else if(a==2){
                                *(postfix+i)='+';
                                i++;
                            }
                            else if(a==3){
                                *(postfix+i)='*';
                                i++;
                            }
                            else if(a==4){
                                *(postfix+i)='/';
                                i++;
                            }
                        }
                    }

                    break;
                default:
                    break;
            }
        }
        j++;
    }
    while(isempty(&order)==0){
        int a=pop(&order);
        if(a==1){
            *(postfix+i)='-';
            i++;
        }
        else if(a==2){
            *(postfix+i)='+';
            i++;
        }
        else if(a==3){
            *(postfix+i)='*';
            i++;
        }
        else if(a==4){
            *(postfix+i)='/';
            i++;
        }

    }
    *(postfix+i)='\0';
    int q=0;
    while(*(postfix+q)!='\0'){
        printf("%c",*(postfix+q));
        q++;
    }
    return postfix;
}
int main(){
    char expressn[100];
    printf("Enter the expression:\n");
    scanf("%s",expressn);
    char * out=infix(expressn);
    return 1;
}