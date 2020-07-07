// https://codeforces.com/gym/278148/problem/C
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
int m, n, from, to, cost;
int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};
vector<int> visited, cat, CAM; //consecutive cats above me including me
vector<int> g[100001];
int ans = 0;

void dfs(int st)
{
    //if st != 1 && st is a leaf node, ans++
    // cout << "\n dfs " << st << "\n";
    if (st != 1 && g[st].size() == 1)
    {
        // cout << "answers " << st << ' ';
        ans++;
    }
    visited[st] = 1;
    // cout << st << " se upar " << st << " ko chodd ke, kitne consecutve cats hai " << CAM[st] << "\n";
    if (cat[st] == 1)
    {
    
        CAM[st] = 1;
        	// cout << st << " " << CAM[st] << " bhenchi\n" ;
    }
   
    

    for (auto u : g[st])
    {
    	// cout << "hello" << u << " ";
        if (!visited[u])
        {
            // cout << st << ":" << u << "   ";

            //dfs to hi contimue karege
            //1. cat[u] = 0
            //2. cat[u] = 1 but CAM[u] < m

            if (cat[u] == 1)
            {
                CAM[u] = 1 + CAM[st];
                if (CAM[u] > m)
                {
                    continue;
                }
            }

            dfs(u);
        }
    }
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n >> m;
    visited.resize(n + 1), cat.resize(n + 1), CAM.resize(n + 1);
    std::fill(visited.begin(), visited.end(), 0);
    std::fill(CAM.begin(), CAM.end(), 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " : ";
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
  

    dfs(1);
    //   for(int i = 1; i <= n; i++){
    // 	cout << i << " : " << CAM[i] << endl;
    // } 
    cout << ans;
    return 0;
}
