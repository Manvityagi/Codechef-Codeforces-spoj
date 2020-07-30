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
#define pii pair<int, int>
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
const int N = 110;
char maxchar;
int dp[N][N];
vector<vector<pii>> g;

int solve(int i, int j, char prev)
{
    //base case
    if(i < 0 || j < 0 || i > n || j > n) return 0;
    if(prev == maxchar){
        dp[i][j] = 0;
        return 0;
    }

    for(auto u : g[i]){
        int k = u.F;
        if(solve(k,j,u.S)){
            dp[i][j] = 1;
        }
    }

    dp[i][j] = 0;
    return 0;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    while (t--){
        cin >> n >> m;
        g.resize(n + 1);
        vector<vector<int>> ans(n + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++){
            int src, dest;
            char c;
            cin >> src >> dest >> c;
            maxchar = max(maxchar, c);
            g[src].emplace_back(dest, c);
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(solve(i, j, 'a')) cout << 'A';
                else cout << 'B';
            }
            cout << "\n";
        }
    }
    return 0;
}
