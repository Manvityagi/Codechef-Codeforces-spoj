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
const int N = 1e6 + 10;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
int parent[N], arr[N];

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

map<int, vector<int>> mp;

int main()
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
        LL n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            union_sets(a, b);
        }

        for (int i = 1; i <= n; i++)
        {
            mp[find_set(i)].emplace_back(arr[i]);
        }

        for (auto &i : mp)
        {
            sort(i.second.begin(), i.second.end());
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            int groupi = find_set(i);
            int curr = mp[groupi].back();
            ans.push_back(curr);
            mp[groupi].pop_back();
        }

        for (auto a : ans)
            cout << a << " ";
    }
    return 0;
}
