#include <iostream>
#include <string>
using namespace std;
//for this implementation I used suffix arrays (a helpful hint from timus forum)
int* suffix(string s){
    static int a [5000];
    bool chk;
    int id;
    for (int i = 1; i < s.size(); i++){
        id = a[i - 1];
        while (id > 0 && s[id] != s[i]){
            id = a[id - 1];
        }
        chk = (s[id] == s[i]) ? true : false;
        a[i] = id + chk;
    }
    return a;
}

int maximum(int a, int b)
{
    if (a>b) return a;
    else return b;
}

int main()
{
    string input;
    cin>>input;
    string temp;
    int out=0;
    int* sf;
    int max;
    for (int i = 0; i < input.size(); i++){
        temp += input[i];
        reverse(temp.begin(), temp.end());
        sf = suffix(temp);
        reverse(temp.begin(), temp.end());
        max = 0;
        for (int j = 0; j < i + 1; ++j){
            max = maximum(max, sf[j]);
        }
        out += i + 1 - max;
    }
    cout<<out;
    return 0;
}