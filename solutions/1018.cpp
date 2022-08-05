#include <vector>
#include <utility>
#include <iostream>
using namespace std;

//global variables
vector <vector <pair <int,int>> > tree1,tree2;
int max_arr[200][200] = {0};
bool paint[200] = {false};

int maximum(int a, int b)
{
    if (a>b) return a;
    else return b;
}

void dfs(int u)//Deep-first search
{
    paint[u] = true;
    for(int i = 0; i < tree1[u].size(); i++)
    {
        int v = tree1[u][i].first;
        if(!paint[v])//if we weren't in this node (not painted node)
        {
            dfs(v);
            tree2[u].emplace_back(v, tree1[u][i].second);
        }
    }
}

int maxApples(int u, int k)
{
    if(max_arr[u][k] != -1) return max_arr[u][k];

    int r = 0;
    int cv = (int)tree2[u].size();

    if(k == 0)
    {
        r = 0;
    }
    else
    {
        for(auto & i : tree2[u])//for every element in tree2 do:
        {
            int v = i.first;
            int d = i.second;
            r = maximum(maxApples(v, k - 1) + d, r);
        }

        if(cv > 1)
        {
            int dd = tree2[u][0].second + tree2[u][1].second;

            for(int i = 0; i <= k-2; i++)
            {
                r = maximum(r, dd + maxApples(tree2[u][0].first, i) + maxApples(tree2[u][1].first, k - 2 - i));
            }
        }
    }
    max_arr[u][k] = r;
    return r;
}

int main()
{
    int N,Q;
    cin >> N >> Q;
    tree1.resize(N + 1);//making N branches+root
    tree2.resize(N + 1);

    for(int i = 0; i < N-1; i++)
    {
        int x,y,apples;
        cin >> x >> y >> apples;
        tree1[x].emplace_back(y, apples);
        tree1[y].emplace_back(x, apples);
    }

    dfs(1);//starting DFS from root

    for(auto & i : max_arr)//for every line in double array max_arr
    {
        for(int & j : i)//make second key = -1
            j = -1;
    }

    cout << maxApples(1, Q);
    return 0;
}