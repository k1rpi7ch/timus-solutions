#include <iostream>
using namespace std;

bool square1(int N){//binsearch
    int l=0,r=245,mid;//245^2 is 60 025, max N is 60 000
    while (r>l+1) {
        mid = (l + r) / 2;
        if (mid * mid >= N)
            r = mid;
        else
            l = mid;
    }
    if (r*r==N) return true;
    else return false;
}

bool square2(int N){
    int a=1,x;
    while (a*a<N){
        x= square1(N-a*a);
        if (x)
            return true;
        a++;
    }
    return false;
}

bool square3(int N){
    int a=1,x;
    while (a*a<N){
        x=square2(N-a*a);
        if (x)
            return true;
        a++;
    }
    return false;
}
int main()
{
    int N;
    bool flag;
    cin>>N;
    flag = square1(N);
    if (flag)
        cout<<1;
    else {
        flag = square2(N);
        if (flag)
            cout<<2;
        else{
            flag = square3(N);
            if (flag)
                cout<<3;
            else
                cout<<4;//according to Lagrange theorem, every natural number can be represented by sum of 4 squares(or less) 
        }
    }
    return 0;
}