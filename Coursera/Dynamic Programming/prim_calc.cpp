#include<iostream>
#include<vector>
using namespace std;
int min2(int arr[],int a,int b){
    if(arr[a]<arr[b]){
        return a;
    }
    return b;

}
int min3(int arr[],int a,int b,int c){
    if(arr[min2(arr,a,b)]<arr[c]){
        return min2(arr,a,b);
    }
    return c;
}
vector <int> change(int n){
    int change_arr[n+1];
    change_arr[1]=0;
    vector <int> arr;
    if(n==1){
        arr.push_back(1);
        cout<<0<<endl;
        cout<<1<<endl;
        return arr;
    }
    for(int i=2;i<=n;i++){
        if (i%2==0){
            if (i%3==0){
                int n1=min3(change_arr,i-1,i/2,i/3);
                change_arr[i]=change_arr[n1]+1;
                arr.push_back(n1);
            }
            else{
                int n1=min2(change_arr,i-1,i/2);
                change_arr[i]=change_arr[n1]+1;
                arr.push_back(n1);
            }
            
        }
        else if(i%3==0){
            int n1=min2(change_arr,i-1,i/3);
            change_arr[i]=change_arr[n1]+1;
            arr.push_back(n1);
        }
        else{
            arr.push_back(i-1);
            change_arr[i]=change_arr[i-1]+1;
        }
    }
    arr.push_back(n);
    cout<<change_arr[n]<<endl;
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr1;
    arr1=change(n);
    for(int i=1;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
}