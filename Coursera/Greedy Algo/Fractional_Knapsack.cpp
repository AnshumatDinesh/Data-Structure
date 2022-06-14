#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;
double knapsack(vector<double> weight,vector<double> value,double max){
    vector<double> valperw;
    int l=weight.size();
    for(int i=0;i<=l;i++){
        valperw.push_back(value[i]/weight[i]);
    }
    double val=0;
    while(max!=0 && weight.size()!=0){
        int max_per=0;
        l=weight.size();
        for(int i=0;i<l;i++){
            if(valperw[i]>valperw[max_per]){
                max_per=i;
            }
        }
        if (weight[max_per]<max){
            max-=weight[max_per];
            weight.erase(weight.begin()+max_per);
            val+=value[max_per];
            value.erase(value.begin()+max_per);
            valperw.erase(valperw.begin()+max_per);
        }
        else{
            val+=valperw[max_per]*max;
            max=0;
        }

    }
    return val;
}
int main(){
    vector<double>value;
    vector<double>weight;
    double max;
    int n;
    cin>>n;
    cin>>max;
    for(int i=0;i<n;i++){
        double a;
        double b;
        cin>>a>>b;
        value.push_back(a);
        weight.push_back(b);
    }
    printf("%.4lf\n",knapsack(weight,value,max));

}