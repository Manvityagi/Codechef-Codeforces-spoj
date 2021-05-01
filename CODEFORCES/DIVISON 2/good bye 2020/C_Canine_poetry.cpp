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

char uniq(string s, int st, int end)
{
    for (auto ch = 'a'; ch <= 'z'; ch++)
    {
        bool poss = 1;
        for (int i = st; i <= end; i++)
        {
            if (i < 0 || i > s.size())
                continue;
            if (s[i] == ch)
            {
                poss = 0;
                break;
            }
        }
        if (poss)
        {
            return ch;
        }
    }
    return 'a';
}

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    vector<int> last(26, -1);
    if (s.size() == 0 || s.size() == 1)
    {
        cout << 0 << "\n";
        return;
    }
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1] || (i - 2 >= 0 && s[i] == s[i - 2]))
        {
            ans++;
            char curr = uniq(s, i - 2, i + 2);
            s[i] = curr;
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