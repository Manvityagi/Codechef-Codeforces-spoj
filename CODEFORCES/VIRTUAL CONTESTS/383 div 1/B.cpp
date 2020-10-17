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
    // cin >> t;
    while (t--)
    {
        LL n, m, cap;
        cin >> n >> m >> cap;
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(int i = 1; i <= n; i++) cin >> wts[i]; 
        for(int i = 1; i <= n; i++) cin >> bts[i]; 
        
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

        vector<vector<int>> dp(n+1,vector<int>(cap+1));

        for(int i = 1; i <= n; i++){
            for(int w = 0; w <= cap; w++){
                int op1 = dp[i-1][w];
                int op2 = INT_MIN; 
                
                for(auto p : mp[i]){
                    if(w-p.F >= 0) op2 = max(op2,dp[i-1][w-p.F]+p.S);
                }

                dp[i][w] = max({dp[i][w],op1,op2});
            }
        }
        cout << dp[n][cap];
     }
    return 0;
}
