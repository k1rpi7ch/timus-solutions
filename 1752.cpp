#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int id, deep, max_deep, deep_position;
    node *gr_uncle, *deep_child[2];
    vector<node*> prnt, child;
};
//global variables
node tree[20001];
node* long_path[20001]; //Array of the longest paths
int a = 0;

void dfs1(node* const n)//deep-first search for every node
{
    n->deep_child[0] = n->deep_child[1] = &tree[0];
    node* p = n->prnt[0];//Fill the depth array
    for(int i = 0; p && p->prnt.size() > i; i++)
    {
        p = p->prnt[i];
        n->prnt.push_back(p);
    }
    if(n->prnt[0])// Finds children depths and remove the parent from neighbor arrays
        n->child.erase(find(n->child.begin(), n->child.end(), n->prnt[0]));
    for(int i = 0; i < n->child.size(); i++)//finds two deepest children
    {
        node* const child = n->child[i];
        child->deep = n->deep + 1;
        child->prnt.push_back(n);
        dfs1(child);
        if(child->max_deep > n->deep_child[1]->max_deep)
        {
            if(child->max_deep > n->deep_child[0]->max_deep)
            {
                n->deep_child[1] = n->deep_child[0];
                n->deep_child[0] = child;
            }
            else
                n->deep_child[1] = child;
        }
    }
    n->max_deep = max(n->deep, max(n->deep_child[0]->max_deep,n->deep_child[1]->max_deep));
}

void dfs2(node* const n)//counts deep arr positions and grandUncles
{
    // part of the longest path extended to arr
    if(n->prnt[0] && n->prnt[0]->deep_child[0] == n)
    {
        n->deep_position = n->prnt[0]->deep_position + 1;
        long_path[n->deep_position] = n;
    }
    else // make new array and longest path
    {
        n->deep_position = a;
        long_path[a] = n;
        a += 1 + n->max_deep - n->deep;
    }
    if(n->prnt[0])
    {   // Assign our "granduncle" tree
        node* candidate = n->prnt[0]->deep_child[0] == n ? n->prnt[0]->deep_child[1] : n->prnt[0]->deep_child[0];
        if(candidate->id == 0 || n->prnt[0]->gr_uncle != nullptr && candidate->max_deep - candidate->deep < n->prnt[0]->gr_uncle->max_deep - n->prnt[0]->gr_uncle->deep + n->deep - n->prnt[0]->gr_uncle->deep)
            n->gr_uncle = n->prnt[0]->gr_uncle;
        else
            n->gr_uncle = candidate;
    }
    for(auto & i : n->child)
        dfs2(i);
}

int search(int n, int dist)
{
    const node* node = &tree[n];
    if(dist <= node->max_deep - node->deep) // Node may be below our start node
        return long_path[node->deep_position + dist]->id;
    else if(dist < node->deep) // Node may be above our start node
    {
        for(int i = 0; dist; i++, dist >>= 1)
            if(dist & 1)
                node = node->prnt[i];
        return node->id;
    }

    else if(node->gr_uncle != nullptr && dist <= node->deep - node->gr_uncle->deep + 2 + node->gr_uncle->max_deep - node->gr_uncle->deep)
        return long_path[dist - (node->deep - node->gr_uncle->deep + 2) + node->gr_uncle->deep_position]->id;
    else
        return 0;
}

int main()
{
    int v,u,d,n,q;
    cin>>n>>q;
    for (int i = 0; i < n-1; i++)
    {
        cin >> v >> u;
        tree[v].child.push_back(&tree[u]);
        tree[u].child.push_back(&tree[v]);
    }
    //initialisation of our tree
    for(int i = 1; i <= n; i++)
        tree[i].id = i;
    tree[1].prnt.push_back(0);
    tree[1].deep = 1;
    tree[1].deep_position = a;
    tree[1].gr_uncle = nullptr;
    dfs1(&tree[1]);
    dfs2(&tree[1]);
    for (int i = 0; i < q; i++)
    {
        cin >> v >> d;
        cout<<search(v, d)<<endl;
    }
}