#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p;
    p = (int*) calloc(100,sizeof(int));
    for(int i=0;i<100;i++){
        *(p+i)=i*i;
    }
    for(int i=0;i<100;i++){
        printf("%d,",*(p+i));
    }    


}