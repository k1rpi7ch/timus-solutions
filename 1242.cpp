#include <vector>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

vector <vector<int>> children;
vector <vector<int>> parents;
vector <int> colour;
vector <int> victims;
set <int> suspects; //set is used to sort automatically

void dfs_child(int a)
{
    colour[a] = 1;
    suspects.insert(a);

    for(int i = 0; i < children[a].size(); i++)
    {
        if(colour[children[a][i]] == 0 )
        {
            dfs_child(children[a][i]);
        }
    }
}

void dfs_prnts(int a)
{
    colour[a] = 1;
    suspects.insert(a);

    for(int i = 0; i < parents[a].size(); i++)
    {
        if(colour[parents[a][i]] == 0 )
        {
            dfs_prnts(parents[a][i]);
        }
    }
}

int main()
{
    int N;
    string line;
    stringstream input;

    cin >> N;
    children.resize(N);
    parents.resize(N);
    colour.resize(N);

    //read citizens in tree
    getline(cin, line);
    while(true)
    {
        int child,parent;
        getline(cin, line);

        if(line == "BLOOD") break;
        input.clear();
        input.str(line);
        input >> child >> parent;

        children[parent - 1].push_back(child - 1);
        parents[child - 1].push_back(parent - 1);
    }
    //read victims
    while(getline(cin, line))
    {
        int v;
        input.clear();
        input.str(line);
        input >> v;
        victims.push_back(v - 1);
    }

    //search
    for(int i = 0; i < victims.size(); i++)
    {
        dfs_child(victims[i]);
    }
    //after first search we should reset colouring
    colour.clear();
    colour.resize(N);
    for(int i = 0; i < victims.size(); i++)
    {
        dfs_prnts(victims[i]);
    }

    //exception
    if(suspects.size() == N){
        cout << 0;
    }

    //output
    for(int i = 0; i < N; i++)
    {
        if(suspects.find(i) == suspects.end())
            cout << i+1 << " ";
    }

    return 0;
}