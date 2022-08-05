#include <iostream>
#include <vector>
using namespace std;

const short N = 32000;
bool IsPrime[N],checker[N];
vector <unsigned int> prime;

bool CheckPrime(int n) {//Checks whether number is prime
    for (int i=0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int GrComDivisor(int a, int b) {//find greatest common divisor of a and b
    if (a % b){
        return GrComDivisor(b, a % b);
    }
    else {
        return b;
    }
}

int main(){
    //precalculating with sieve of Eratosthenes to find prime numbers and add them to vector primes
    for (int i = 1; i < N; i++) {
        IsPrime[i] = true;
        checker[i] = false;
    }
    IsPrime[1] = false;//1 isn't prime number
    prime.push_back(2);//2 is a prime number
    checker[2] = true;
    for (int i = 3; i*i < N; i += 2) {
        if (IsPrime[i]) {
            for (int j = i * i; j < N; j += 2 * i) {
                IsPrime[j] = false;
            }
        }
    }
    for (int i = 3; i < N; i += 2) {
        if (IsPrime[i]) {
            prime.push_back(i);
            checker[i] = true;
        }
    }

    //start
    int T, n;
    bool flag;
    cin >> T;
    while (T--) {
        cin>>n;
        if (CheckPrime(n)) {
            cout<<n<<endl;
            continue;
        }
        flag = false;
        for (int i = 0; i < prime.size() && prime[i] < n; i++) {
            if (checker[prime[i]] && CheckPrime(n - prime[i])) {
                cout << prime[i] << " " << n - prime[i] << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout<<"3";
            n = n - 3;
            for (int i = 0; i < prime.size() && prime[i] < n; i++) {
                if (checker[prime[i]] && CheckPrime(n - prime[i])) {
                    cout << " " << prime[i] << " " << n - prime[i] << endl;
                    break;
                }
            }
        }
    }
}