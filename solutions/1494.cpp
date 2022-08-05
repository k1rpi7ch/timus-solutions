#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    int ball;
    int max_ball=0;
    bool cheat = false;
    vector <int> stack;
    cin>>N;
    cin>>ball;
    for (int i=max_ball+1; i<=ball-1; i++)
        stack.push_back(i);
    max_ball=ball;

    for (int i=1;i<N;i++){
        cin>>ball;
        if (ball>max_ball){
            for (int j=max_ball+1; j<=ball-1; j++)
                stack.push_back(j);
            max_ball=ball;
        }
        else if (ball==stack[stack.size()-1]) stack.pop_back();
        else if (ball<stack[stack.size()-1]){
                cout<<"Cheater";
                cheat=true;
                break;
            }
    }
    if (cheat==false) cout<<"Not a proof";
    stack.clear();
	return 0;
}