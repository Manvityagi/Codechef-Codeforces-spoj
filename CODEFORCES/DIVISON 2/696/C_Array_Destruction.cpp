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
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

vector<pii> ans;
int mx;
int solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());

    unordered_map<int, int> mp;
    for (int k = 0; k < n - 1; k++)
    {
        mp.clear();
        for (auto j : a)
            mp[j]++;
        int x = a[n - 1] + a[k];
        int p1 = a[n - 1], p2 = a[k];
        mp[p1]--, mp[p2]--;
        mx = x;
        int idx = n - 2, flag = 1;
        ans.clear();
        ans.emplace_back(p1, p2);
        for (int i = 0; i < (n - 2) / 2; i++)
        {
            int y = max(p1, p2);
            while (mp[a[idx]] == 0)
                idx--;
            p1 = a[idx];
            mp[p1]--;
            p2 = y - p1;
            if (mp.find(p2) == mp.end() || mp[p2] == 0)
            {
                flag = 0;
                break;
            }
            ans.emplace_back(p1, p2);
            mp[p2]--;
        }
        if (flag)
            return 1;
    }
    return 0;
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
        if (solve())
        {
            cout << "YES\n"
                 << mx << "\n";
            for (auto p : ans)
                cout << p.F << " " << p.S << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}