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
unordered_set<char> st;
bool isvowel(char a)
{
    return (a == 'Y' || a == 'y' || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U');
}
void solve()
{
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (isvowel(s[i]))
            continue;
        cout << '.';
        cout << (char)tolower(s[i]);
    }
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
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}