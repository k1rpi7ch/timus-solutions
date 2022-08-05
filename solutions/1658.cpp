#include<iostream>
#include<cstring>
using namespace std;

#define MAX 101//nums in dp are not bigger than 100
char dp[910][8110][2];//all numbers here are less than 100, so to save space in memory I used char 
int result[101];

int minimum(int a, int b)
{
    if (a<b) return a;
    else return b;
}

int main()
{
    short t;
    int m,n,count;
    //initialisation
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=900;i++) {
        for (int j = 1; j <= 8100; j++) {
            dp[i][j][1] = MAX;
        }
    }
    for(int k=1;k<10;k++) {
        for (int i = k; i <= 900; i++) {
            for (int j = k * k; j <= 8100; j++)
                if (dp[i - k][j - k * k][0]) {
                    dp[i][j][0] = 1;
                    dp[i][j][1] = minimum(dp[i - k][j - k * k][1] + 1, dp[i][j][1]);
                }
        }
    }

    //input
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if((n>900 || m>8100) || dp[n][m][0]==0 || dp[n][m][1]>100)
        {
            cout<<"No solution"<<endl;
            continue;
        }

        //calculating
        int i=n, j=m, count=0;
        while(i>0 && j>0)
        {
            for(int k=1;k<10;k++)
                if(i-k>=0 && j-k*k>=0 && dp[i-k][j-k*k][0] && dp[i][j][1]==dp[i-k][j-k*k][1]+1)
                {
                    result[count++] = k;
                    i = i - k;
                    j = j - k * k;
                    break;
                }
        }
        //output
        for(int i=0;i<=count-1;i++)
            cout<<result[i];
        cout<<endl;
    }
    return 0;
}

