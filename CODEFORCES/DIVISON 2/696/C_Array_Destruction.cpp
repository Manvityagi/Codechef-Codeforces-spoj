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
vector<int> a;
vector<pii> ans;
int mx;
int solve()
{
    int n;
    cin >> n;
    a.clear();
    a.resize(2 * n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    vector<int> orig = a; 
    int x = a[n - 1];
    for (int k = 0; k < n - 1; k++)
    {
        a = orig;
        x = a[n - 1] + a[k];
        mx = x;
        int removed = 0; 
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == INT_MIN)
                    continue;
                int search = x - a[i];
                int i2 = lower_bound(a.begin(), a.end(), search) - a.begin();
                if (i == i2)
                { //edge case
                    if (a[i + 1] == a[i])
                    { //okay
                        ans.emplace_back(a[i], a[i2]);
                        a[i] = INT_MIN;
                        a[i2] = INT_MIN;
                        removed += 2; 
                        x = max(a[i], a[i2]);
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (a[i2] != search)
                {
                    //cant remove
                    continue;
                }
                else
                {
                    //removing
                    ans.emplace_back(a[i], a[i2]);
                    a[i] = INT_MIN;
                    a[i2] = INT_MIN;
                    removed += 2; 
                    x = max(a[i], a[i2]);
                    break;
                }
            }
            if(removed == n) break;
        }
        if(removed == n) break;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != INT_MIN)
            return 0;
    }
    return 1;
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