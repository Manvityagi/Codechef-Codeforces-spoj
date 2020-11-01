
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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> left(a), right(a);

    for (int i = 1; i < n; i++)
        left[i] *= left[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] *= right[i + 1];
    
    for(int i = 0; i < n; i++) cout << left[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << right[i] << " ";
    cout << "\n";
     
    int ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int part1 = left[i];
        int part2 = right[i + 1];
        if (__gcd(part1, part2) == 1)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << "\n";
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
        solve();
    }
    return 0;
}