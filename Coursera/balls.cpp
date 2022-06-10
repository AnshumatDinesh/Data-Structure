#include <iostream>
using namespace std;
void boxes_balls(int balls,int boxes){
    int *p;
    p=(int*) calloc(boxes,sizeof(int));
    int i=0;
    while (balls>0){
        for(i;i<boxes;i++){
            *(p+i)+=i;
            balls-=i;
    }
    i++;
    }
    int check=0;
    for(int j=0;j<boxes;j++){
       check+=*(p+ij;
    
    }
    printf("%d,",check);

}
int main(){
    boxes_balls(60,10);
}