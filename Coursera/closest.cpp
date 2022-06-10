#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct pnt{
    float x;
    float y;
} point;
float absolute(float a){
    if (a<0){
        return -1*a;
    }
    return a;
}
void swap(point *pntr1,point*pntr2){
    point temp= *pntr1;
    *pntr1=*pntr2;
    *pntr2=temp;
}
float strip(point p[],int mid,int high,float d){
    point strip_pnts[100];
    int j=0;
    for (int i=0;i<=high;i++){
        if (absolute(p[i].x-p[mid].x)<d){
            strip_pnts[j]=p[i];
            j++;
        }
    }
    float min=INFINITY;
    for (int i=0;i<=j;i++){
        for (int k=0;k<=j;k++){
            if (i!=k){
                if(min>sqrt((strip_pnts[i].x-strip_pnts[k].x)*(strip_pnts[i].x-strip_pnts[k].x)+(strip_pnts[i].y-strip_pnts[k].y)*(strip_pnts[i].y-strip_pnts[k].y))){
                    min=sqrt((strip_pnts[i].x-strip_pnts[k].x)*(strip_pnts[i].x-strip_pnts[k].x)+(strip_pnts[i].y-strip_pnts[k].y)*(strip_pnts[i].y-strip_pnts[k].y));
                }
            }

        }
    }
    return min;
}
float closest_point(point p[],int low,int high){
    int size=high-low+1;
    if (size==1){
        return INFINITY;
    }
    if (size==2){
        return sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y));
    }
    if (size==3){
        float d1,d2,d3;
        d1=sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y));
        d2=sqrt((p[1].x-p[2].x)*(p[1].x-p[2].x)+(p[1].y-p[2].y)*(p[1].y-p[2].y));
        d3=sqrt((p[0].x-p[2].x)*(p[0].x-p[2].x)+(p[0].y-p[2].y)*(p[0].y-p[2].y));
        if (d1<d2){
            if (d3<d1){
                return d3;
            }
            return d1;
        }
        if(d3<d2){
            return d3;
        }
        return d2;
    }
    float dl,dr,d_s,d;
    int mid=low+((high-low)/2);
    dl=closest_point(p,low,mid);
    dr=closest_point(p,mid+1,high);
    if (dl<dr){
        d=dl;
    }
    else{
        d=dr;
    }
    d_s=strip(p,mid,high,d);
    if (d_s<d){
        return d_s;
    }
    return d;
}
int partition( point p[],int l,int r){
    float pivot=p[r].x;
    int i=l-1;
    for (int j=l;j<r;j++){
        if(p[j].x<=pivot){
            i++;
            swap(&p[i],&p[j]);
        }
    }
    swap(&p[i+1],&p[r]);
    return(i+1);
}
void quick_sort(point p[],int l,int r){
    if (l<r){
        int pi=partition(p,l,r);
        quick_sort(p,l,pi-1);
        quick_sort(p,pi+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    point p[n]={};
    for (int i=0;i<n;i++){
        cin>>p[i].x;
        cin>>p[i].y;
    }
    quick_sort(p,0,n-1);
    cout<<closest_point(p,0,n-1);
}