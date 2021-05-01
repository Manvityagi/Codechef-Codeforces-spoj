
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
    string red, blue;
    cin >> red>> blue;

    int r = 0, b = 0, e = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << red[i] << ":" << blue[i] << "\n";
        if (red[i]-'0' > blue[i]-'0')
            r++;
        else if (blue[i]-'0' > red[i]-'0')
            b++;
        else
            e++;
    }
    // cout << r << " " << b << "\n";
    if (r > b)
    {
        cout << "RED";
    }
    else if (b > r)
    {
        cout << "BLUE";
    }
    else
    {
        cout << "EQUAL";
    }
    cout << "\n";
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