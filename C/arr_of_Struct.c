#include<stdio.h>
#include<stdlib.h>
struct patient
{
    int id;
    char name[100];
    int age;
};

int main(){
    struct patient *h1;
    h1= (struct patient*) malloc(100*sizeof(struct patient));
    for(int i=0;i<2;i++){
        scanf("%d",&(h1[i].id));
        scanf("%d",&(h1[i].age));
        scanf("%s",h1[i].name);
    }
    for(int i=0;i<2;i++){
        printf("%d %d %s\n",h1[i].id,h1[i].age,h1[i].name);
    }
}