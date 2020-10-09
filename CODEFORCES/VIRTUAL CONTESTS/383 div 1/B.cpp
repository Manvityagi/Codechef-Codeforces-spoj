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
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
#define int LL
int wts[1001], bts[1001];
int parent[1001];

int find_parent(int u){
    if(parent[u] == u) return u;
    return parent[u] = find_parent(parent[u]);
}

void union_set(int u, int v){
    u = find_parent(u);
    v = find_parent(v); 
    if(u != v) {
        parent[u] = v;
    }
}


signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n, m, w;
        cin >> n >> m >> w;
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(auto &i : wts) cin >> i; 
        for(auto &i : bts) cin >> i; 
        
        for(int i = 0; i < m; i++){
            int x,y;
            cin >> x >> y; 
            union_set(x,y);
        }

        map<int,vector<pair<int,int>>> mp; //hosh - vector<weight,beauty> 

        for(int i = 1; i <= n; i++){
            int p = find_parent(i);
            mp[p].emplace_back(wts[i],bts[i]);
        }
         
        for(auto e : mp){
            int beautySum = 0, weightSum = 0; 
            for(auto h : e.S){
                beautySum += h.S; 
                weightSum += h.F;
            }
            mp[e.F].emplace_back(weightSum,beautySum);
        }

     }
    return 0;
}
