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
int t, k, n, from, to, cost;
int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};
vector<int> visited, depth;
string word;
int leafWithMaxDepth = 1, maxDepth;
int ans = 0, vertexCount = 0;
map<char, int> mp;

void dfs(int st, int &vertexCount, vector<int> g[200002])
{
    vertexCount++;
    mp[word[st - 1]]++;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
        {
            dfs(u, vertexCount, g);
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
    ans = 0;
    vector<int> g[200002];
    cin >> n >> k;
    visited.resize(n + 1);
    std::fill(visited.begin(), visited.end(), 0);
    cin >> word;

    for (int i = 0; i < n - k; i++)
    {
        if (i != (k + i))
        {
            g[i].PB(k + i);

            g[k + i].PB(i);
        }
        if (n - i - 1 != i)
        {
            g[n - i - 1].PB(i);
            g[i].PB(n - i - 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            mp.clear();
            vertexCount = 0;
            dfs(i, vertexCount, g);
            vector<pair<char, int>> vec;
            vec.clear();
            for (auto it2 = mp.begin(); it2 != mp.end(); it2++)
            {
                vec.push_back(make_pair(it2->first, it2->second));
            }
            sort(vec.begin(), vec.end(), sortByVal);

            int mostfreq = vec[vec.size() - 1].second;
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

    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
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
int t, k, n, from, to, cost;
int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};
vector<int> visited, depth;
string word;
int leafWithMaxDepth = 1, maxDepth;
int ans = 0, vertexCount = 0;
map<char, int> mp;

void dfs(int st, int &vertexCount, vector<int> g[200002])
{
    vertexCount++;
    mp[word[st - 1]]++;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
        {
            dfs(u, vertexCount, g);
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
    ans = 0;
    vector<int> g[200002];
    cin >> n >> k;
    visited.resize(n + 5);
    std::fill(visited.begin(), visited.end(), 0);
    cin >> word;

    //making graph
    for (int i = 0; i < n - k; i++)
    {
        if (i != (k + i))
        {
            g[i].PB(k + i);

            g[k + i].PB(i);
        }
        if (n - i - 1 != i)
        {
            g[n - i - 1].PB(i);
            g[i].PB(n - i - 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            mp.clear();
            vertexCount = 0;
            dfs(i, vertexCount, g);
            // cout << "vc " << vertexCount << "\n";
            vector<pair<char, int>> vec;
            vec.clear();
            for (auto it2 = mp.begin(); it2 != mp.end(); it2++)
            {
                vec.push_back(make_pair(it2->first, it2->second));
            }
            sort(vec.begin(), vec.end(), sortByVal);

            int mostfreq = vec[vec.size() - 1].second;
            ans += vertexCount - mostfreq;
        }
    }
    mp.clear();
    word.clear();
    for (int i = 0; i < n; i++)
        g[i].clear();
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

    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
