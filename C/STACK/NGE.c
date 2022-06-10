#include"stack.c"
int nge(int *arr,int n){
    Stack nge;
    initialize(&nge);
    for(int i=0;i<n;i++){
        if (isempty(&nge)){
            push(&nge,*(arr+i));
        }
        else{
            int a=pop(&nge);
            if(*(arr+i)>a){
                push(&nge,*(arr+i));
            }
            else{
                push(&nge,a);
            }
        }
    }
    if(isempty(&nge)){
        return -1;
    }
    return pop(&nge);
}
int main(){
    int a[10]={0,9,1,8,2,7,3,6,4,5};
    printf("%d",nge(a,10));
}