//Solution uses Fenwick (binary-indexed tree) (helpful hint from Timus Forum) https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/
#include <iostream>
#include <cmath>
using namespace std;
#define N 300001
long long b[N], a[N];
int n, q;
long long Sum(int start) {//long is WA9
    long long out = 0;
    for(int i = start; i; i -= i & (-i))//i-last nonzero bit
        out += b[i];
    return out;
}

int main() {
    //input
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;

    //actions in experiment
    while(q--) {
        short action,temp;
        int l, r, d;
        long long divisor;
        cin >> action;
        if(action == 1) {
            cin >> d;
            temp = sqrt(d);
            divisor = 0;
            for(int i = 1; i <= temp; i++) {
                if(d % i == 0) {
                    divisor += Sum(i);
                    if(i != d / i){
                        divisor += Sum(d / i);
                    }
                }
            }
            cout << divisor + a[d] << '\n';
        } else {
            cin >> l >> r >> d;
            for(int i = l; i <= n; i += i & (-i)){//i+last nonzero bit
                b[i] += d;
            }
            for(int i = ++r; i <= n; i += i & (-i)) {//i+last nonzero bit
                b[i] += -d;
            }
        }
    }
    return 0;
}