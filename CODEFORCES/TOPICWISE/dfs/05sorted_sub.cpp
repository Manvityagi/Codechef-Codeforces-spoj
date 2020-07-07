#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int n;
vector<int> vec;
vector<int> G[100001];
int idx = 0;
vector<int> vis, ans[100001];
map<int,int> pos;
void dfs(int vx)
{
    if (vis[vx])
    {
        return;
    }
    vis[vx] = 1;
    // cout << "DFS ON " << vx << endl;
    // cout << "IDX " << idx << "\n";
    ans[idx].push_back(vx + 1);
    for (auto vy : G[vx])
    {
        dfs(vy);
    }
}

int main()
{
    cin >> n;
    vec.resize(n);
    vis.resize(n);
    vector<int> svec(n);
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        vec[i] = e;
        svec[i] = vec[i];
    }

    sort(svec.begin(), svec.end());

    for(int i = 0; i < n; i++)
    {
        pos[svec[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        auto sortidx = pos[vec[i]];
        G[i].push_back(sortidx);
    }
    
    // for(int i = 0; i < n; i++){
    // 	cout << i << " : " ;
    // 	for(int j = 0; j < G[i].size(); j++){
    // 		cout << G[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            idx++;
        }
    }

    cout << idx << "\n";
    for (int i = 0; i < idx; i++)
    {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}