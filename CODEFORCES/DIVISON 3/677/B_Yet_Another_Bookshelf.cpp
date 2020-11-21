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
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int ans = 0;
    vector<int> ones;
    for(int i = 0; i < n; i++){
        if(a[i]) ones.push_back(i);
    }

    for(int i = 1; i < ones.size(); i++){
        ans += (ones[i] - ones[i-1] - 1);
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