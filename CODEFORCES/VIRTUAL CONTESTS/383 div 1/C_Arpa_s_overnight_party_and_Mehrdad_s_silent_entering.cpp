#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int,int>
#define int LL 
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
int n;
vector<int> g[200002];

bool bipartite(int src, vector<int> &colors, vector<int> &visited, int currColor){
        visited[src] = 1;
        colors[src] = currColor;

        for(auto nbr : g[src]){
            if(visited[nbr] && colors[nbr] == currColor) return false;
            if(visited[nbr]) continue;
            if(!bipartite(nbr,colors,visited,!currColor)) return false;
        }

        return true;
}

signed main(){
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pii> query(n); 
        for(int i = 0; i < n; i++){
            int boy, girl;
            cin >> boy >> girl;
            query[i].F = boy;
            query[i].S = girl;
            g[boy].emplace_back(girl);
            g[girl].emplace_back(boy);
            if(i) {
                g[2*i].emplace_back(2*i+1);
                g[2*i+1].emplace_back(2*i); 
            }
        }
        g[2*n].emplace_back(1);
        g[1].emplace_back(2*n+1); 
        n *= 2;

        vector<int> colors(n+1,-1), visited(n+1,0);

        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;

            if(bipartite(i,colors,visited,1)){
                for(auto &c : colors) if(c == 0) c+=2;
            } else {
                cout << -1 << "\n"; 
                continue;
            }
        }
        for(auto pr : query) cout << colors[pr.F] << " " << colors[pr.S] << "\n";
        
     }
    return 0;
}
