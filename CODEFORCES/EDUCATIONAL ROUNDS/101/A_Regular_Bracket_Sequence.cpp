
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

bool isBalanced(string s)
{
    int n = s.size(), o = -1, c = -1;
    if (n & 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            o = i;
        else if (s[i] == ')')
            c = i;
    }

    int cnt = n - 2;

    if (c > o)
    {
        if (cnt & 1)
            return 0;
        return 1;
    }

    if (c == 0 || o == n - 1)
        return 0;
    else
    {
        if (cnt & 1)
            return 0;
        return 1;
    }

    return 0;
}

void solve()
{
    string s;
    cin >> s;
    stack<char> ele;
    if (isBalanced(s))
        cout << "YES\n";
    else
        cout << "NO\n";
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