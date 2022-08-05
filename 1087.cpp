//typical Task from "EGE" about game theory
#include <iostream>
using namespace std;

int main()
{
    short n, m, winner, id, stones[10000], k[50];//stones is an array where [i] is number of stones and value is winner
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        cin>>k[i];
    }
	//soulution:
    for (int i = 1; i <= n; i++)
    {
        winner = 2;
        for (int j = 0; j < m; j++)
        {
            id = i - k[j];
            if (id < 0){
                continue;
            }
            //formula
            if (3 - stones[id] == 1) {
                winner = 1, j = m;
            }
        }
        stones[i] = winner;
    }
    cout << stones[n];
    return 0;
}