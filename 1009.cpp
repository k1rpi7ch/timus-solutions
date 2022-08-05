#include <iostream>
using namespace std;
int main()
{
    int N,K;
    cin>>N;
    cin>>K;
    int nol=0;
    int nnol=K-1;
    int temp1,temp2;
    for (int i=0;i<N-1;i++){
        temp1=nol;
        temp2=nnol;
        nol=temp2;
        nnol=(temp1+temp2)*(K-1);
    }
    cout<<nol+nnol;
    return 0;
}