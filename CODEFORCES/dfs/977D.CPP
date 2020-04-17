#include <bits/stdc++.h>
using namespace std;
const long long N = 500;
#define LL long long
vector<LL> g[N], vis(N);
LL n, root;
vector<LL> arr, ans;
unordered_map<LL, LL> mp;
vector<int> indegree;
void prLL()
{
    for (auto a : ans)
    {
        cout << a << " ";
    }
}
void dfs(LL v)
{

    if (vis[v])
    {
        return;
    }

    vis[v] = 1;

    ans.push_back(arr[v]);

    for (auto u : g[v])
    {
        if (!vis[u])
        {
            dfs(u);
        }
    }
}
main()
{
    cin >> n;
    arr.resize(n);
    indegree.resize(n);
    for (LL i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vis.resize(n);
    fill(vis.begin(), vis.end(), 0);
    fill(indegree.begin(),indegree.end(),0);

    sort(arr.begin(), arr.end());

    for (LL i = 0; i < n; i++)
    {
        if (mp.find(2 * arr[i]) != mp.end())
        {
            auto ptr = lower_bound(arr.begin(), arr.end(), 2 * arr[i]);
            LL idx = ptr - arr.begin();
            g[i].push_back(idx);
            indegree[idx]++;
        }
		else
        if ((arr[i] % 3 == 0) && (mp.find(arr[i] / 3) != mp.end()))
        {
            auto ptr = lower_bound(arr.begin(), arr.end(), arr[i]/3);
            LL idx = ptr - arr.begin();
            g[i].push_back(idx);
            indegree[idx]++;
        }
    }

    for(int i = 0; i < n; i++){
        if((indegree[i] == 0)){
            root = i;
            break;
        }
    }

    dfs(root);
        prLL();
    
}