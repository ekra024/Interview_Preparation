#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&parent) {
    visited[src] = true;
    parent[src] = -1;
    queue<int>q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto &child: adj[node]) {
            if(!visited[child]) {
                visited[child] = true;
                parent[child] = node;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>>adjComputer(n+1);
    vector<int>parent(n+1, -1);
    vector<bool>visited(n+1, false);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adjComputer[u].push_back(v);
        adjComputer[v].push_back(u);
    }

    bfs(1, adjComputer, visited, parent);


    if(visited[n]) {
        vector<int>path;
        int node = n;

        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }

        cout<<path.size() <<'\n';
        reverse(path.begin(), path.end());
        for(auto &p: path) cout << p <<' ';
        cout<<'\n';
    }
    else cout<<"IMPOSSIBLE\n";
}
