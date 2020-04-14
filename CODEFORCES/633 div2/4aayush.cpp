//https://codeforces.com/contest/1338/problem/B
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int n, a, b, lev[N], leaves, edges, leaf_parent, mn = 1;

int cnt = 0;
int dfs(int s = 1, int p = 0)
{
    cout << "Call " << cnt++ << " for node : " << s << "with parent p :" << p << "\n";

    int l = (int)g[p].size() == 1;
    cout << "Parent ke child ka size l: " << l << "\n";
    cout << "Inside loop of children of s : " << s << "\n";
    for (int &i : g[s]) 
    {
        cout << "childnode " << i << "\n";
        lev[i] = lev[s] + 1;
        cout << "lev[" << i << "] " << lev[i] << "\n";
        if (i == p)
            continue;
        l += dfs(i, s);

        cout << "l after dfs " << l << "\n";
    }
    leaves += ((int)g[s].size() == 1);
    cout << "leaves : " << leaves << "\n";
    cout << "l after the loop " << l << "\n";
    cout << "lev[" << s << "] after loop " << lev[s] << "\n"; 
    if (l)
        leaf_parent++;
    if ((int)g[s].size() == 1 && lev[s] % 2)
        mn = 3;
    
    cout << "\n\n\n";

    return ((int)g[s].size() == 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((int)g[i].size() == 1)
        {
            dfs(i);
            break;
        }
    }
    printf("%d %d", mn, n - 1 + leaf_parent - leaves);
    return 0;
}