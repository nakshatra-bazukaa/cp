#include<bits/stdc++.h>
using namespace std;

void toposort(vector<vector<int> > &adj , vector<bool> &visited , vector<int> &result , int x)
{
    visited[x] = true;
    for(int i = 0 ; i < adj[x].size() ; i++)
    {
        if(!visited[adj[x][i]])
        {
            toposort(adj , visited , result , adj[x][i]);
        }
    }
    result.insert(result.begin() , x);
}

int main()
{
    int n , m;
    cin>>n>>m;
    vector<vector<int> >  adj(n , vector<int>());
    for(int i = 0 ; i < m ; i++)
    {
        int x , y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    vector<int> result;
    vector<bool> visited(adj.size() , false);
    for(int i = 0 ; i < adj.size() ; i++)
    {
        if(!visited[i])
        {
            toposort(adj , visited , result , i);
        }
    }
    for(int i = 0 ; i < result.size() ; i++)
    {
        cout<<result[i]+1<<" ";
    }
    return 0;
}
