#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long int
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define inn                     \
    ll arr[n];                  \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define fora(i, n) \
    ;              \
    for (ll i = 0; i < n; i++)
#define forb(i, a, n) \
    ;                 \
    for (int i = a; i < n; i++)
#define mod 1000000007
#define endl "\n"
#define F first
#define S second
#define vi vector<ll>
#define pii pair<ll, ll>
int main()
{
    tc
    {

        int n, k;
        cin >> n >> k;
        inn;
        set<int> s;
        for (auto it : arr)
            s.insert(it);
        if (s.size() > k)
        {
            cout << -1 << "\n";
        }
        else
        {

            vector<int> v;
            for (auto it : s)
                v.push_back(it);
            for (int i = v.size(); i < k; i++)
            {
                v.push_back(v[0]);
            }
            int ans[n * n];
            for (int i = 0; i < n * n; i++)
            {
                ans[i] = v[i % k];
            }
            cout << n * n << "\n";
            for (auto it : ans)
            {
                cout << it << " ";
            }

            cout << "\n";
        }
    };

    return 0;
}