// https://codeforces.com/gym/278148/problem/C
#include <bits/stdc++.h>
using namespace std;

#define PB push_back

void dfs(int st, int &vertexCount, vector<int> g[100001], map<char, int> mp, string word, vector<int> visited)
{
    vertexCount++;
    mp[word[st - 1]]++;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
        {
            dfs(u, vertexCount, g, mp, word, visited);
        }
    }
}
static bool sortByVal(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}
void solve()
{
    int n, k, from, to, ans = 0;
    vector<int> g[100001];
    cin >> n >> k;
    vector<int> visited(n + 1, 0);
    string word;
    cin >> word;

    //making graph
    for (int i = 1; i <= n / 2; i++)
    {
        //palindromes
        from = i, to = n + 1 - i;
        g[from].PB(to);
        g[to].PB(from);
    }

    for (int i = 1; i <= n - k; i++)
    {
        from = i; //periods
        to = k + i;
        g[from].PB(to);
        g[to].PB(from);
    }

    //travel all connected components,
    //in each dfs, check which alphabet occurs the most, - mostfreq
    //ans += totalVertcies - mostfreq

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            map<char, int> mp;
            mp.clear();
            int vertexCount = 0;
            dfs(i, vertexCount, g,mp,word,visited);
            // cout << "vc " << vertexCount << "\n";
            vector<pair<char, int>> vec;
            vec.clear();
            for (auto it2 = mp.begin(); it2 != mp.end(); it2++)
            {
                vec.push_back(make_pair(it2->first, it2->second));
            }
            sort(vec.begin(), vec.end(), sortByVal);
            //   for(auto it = vec.begin(); it != vec.end(); it++){
            // 	cout << it->first << " " << it->second << "\n";
            // }

            int mostfreq = vec[vec.size() - 1].second;
            // cout << "mf " << mostfreq << "\n";
            ans += vertexCount - mostfreq;
        }
    }

    cout << ans << "\n";
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
