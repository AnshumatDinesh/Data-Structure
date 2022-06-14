#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

int knapsack(int w[],int v[],int max,int n){
    int value[max+1][n+1];
    for(int i=0;i<=max;i++){
        for(int j=0;j<=n;j++){
            value[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=max;j++){
            value[j][i]=value[j][i-1];
            if(w[j]<=j){
                int val;
                val=value[j-w[j]][i-1]+v[i];
                if(value[j][i]<val){
                    value[j][i]=val;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=max;j++){
            cout<<"|"<<value[j][i]<<"|";
        }
        cout<<endl;
    }
    return value[max][n];
}
int main(){
    int n;
    cin>>n;
    int value[n];
    int weight[n];
    int max;
    cin>>max;
    for(int i=0;i<n;i++){
        cin>>value[i]>>weight[i];
    }
   cout<<knapsack(weight,value,max,n);

}