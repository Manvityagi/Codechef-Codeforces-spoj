#include<bits/stdc++.h>
using namespace std;
 
int v, e;
const int N = 100;
vector<pair<int,int>> g[N];
 
vector<int> bfs(){
    set<pair<int,int>> q; //distance, vertex  
    vector<int> distance(e,0); 
    vector<int> vis(v,0); 

    q.emplace(0,0); 

    while (!q.empty())
    {
        auto src = q.begin()->second;
        q.erase(q.begin());
        if(vis[src]) continue;
        vis[src] = 1; 

        for(auto u : g[src]){
            int dest = u.second, wt = u.first; 
            if(vis[dest]) continue;
            if(distance[dest] > distance[src] + wt) {
                distance[dest] = distance[src] + wt; 
                q.emplace(distance[dest],dest);
            }
        }

    }
    return distance; 
}


int main(){
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int src,dest,wt;
        cin >> src >> dest >> wt;
        g[src].emplace_back(dest,wt);
        g[dest].emplace_back(src,wt);
    }
 
    auto shortestPaths = bfs();
    for(auto u : shortestPaths) cout << u << " "; 
    return 0; 
}