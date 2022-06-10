#include <bits/stdc++.h>
using namespace std;
int count(int n)
{
    return int((-1 + sqrt(1 + 8 * n)) / 2);
}
int val(int n){
    int cnt=count(n);
    if (cnt==1){
        return n;
    }
    while(cnt>1){
        int i=1;
        cout<<i;
        cnt-=i;
        
    }
}
int main()
{
    int n ;
    cin>>n;
    cout << count(n);
 
    return 0;
}