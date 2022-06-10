#include<iostream>
#include<limits>
#include<vector>
using namespace std;
/*
ALgorithm
pseudo-code:
max=a[0]
sec_max;
for i in range 0 to n-1
    if a[i]>max
        sec_max=max
        max=a[i]
print(max*sec_max)
*/
long long max(const vector<long long> &vec){
    long long max,sec_max;
    max=-1*numeric_limits<int>::infinity();
    sec_max=-1*numeric_limits<int>::infinity();
    for (int i=0;i<vec.size();i++){
        if(vec[i]>max){
            sec_max=max;
            max=vec[i];
        }
        else if (vec[i]>sec_max ){
            sec_max=vec[i];
        }
    }
    return sec_max*max;
}
int main(){
    vector <long long> test;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        test.push_back(a);
    }
    cout<<max(test);
    return 0;
}