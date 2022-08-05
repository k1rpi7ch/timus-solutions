#include <iostream>
using namespace std;

int main(){
    int N;
    float a0, aN,c,sum=0;
    cin>>N>>a0>>aN;
    for(int i=N;i>0;i--){
        cin>>c;
        sum+=2*i*c;
    }
    float output=(N*a0+aN-sum)/(N+1);//formula calculated by hand
    //cout<<round(output*100)/100<<endl;
    //cout<<setprecision(4)<<output<<endl;//I don't know why it doesn't work
    printf("%.2f\n", output);
    return 0;
}