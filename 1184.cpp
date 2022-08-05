#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,K,a,b;
    char dot;
    cin>>N>>K;
    int *arr=new int [N];
    for (int i=0;i<N;i++){
        cin>>a>>dot>>b;
        arr[i]=a*100+b;//integers are faster than float
    }
    //binary search
    int LB=1;
    int RB=10000000;
    int mid,temp,maxlength=0;
    while (LB<=RB){
        mid=(LB+RB)/2;
        temp=0;
        for (int i=0;i<N;i++){
            temp+=arr[i]/mid;
        }
        if (temp<K){
            RB=mid-1;
        }
        else{
            LB=mid+1;
            maxlength=mid;
        }
    }
    //output
    cout<<maxlength/100<<".";
    printf("%02d",maxlength%100);
    cout<<endl;
    //exit
    delete[] arr;
    return 0;
}