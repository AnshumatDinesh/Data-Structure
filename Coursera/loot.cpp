#include <iostream>
using namespace std;
void rem(int wght[],int cst[],int ind,int *n){
    for (int i=ind;i<*(n)-1;i++){
        wght[i]=wght[i+1];
        cst[i]=cst[i+1];
    }
    wght[*(n)-1]=0;
    cst[*(n)-1]=0;
}
int loot(int max_wt,int n,int wght[],int cst[]){
    int wight=0;
    int val=0;
    while(wight<=max_wt)
    {    int index=0,max=cst[0];
        for(int i=i;i<n;i++){
            if(cst[i]>max){
                max=cst[i];
                index=i;
            }
        }
        if( wght[index]+wight<max_wt){
            val+=cst[index];
            wight+=wght[index];

        }
        rem(wght,cst,index,&n);}
    return val;
}
int main(){
    int n,w;
    cin>>n>>w;
    int wght[n],cst[n];
    for(int i=0;i<n;i++){
        cin>>wght[i]>>cst[i];
    }
    cout<<loot(w,n,wght,cst);
}