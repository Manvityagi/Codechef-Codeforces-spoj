
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
const int MAX_N = 2 * 1e5;

string helper(string s, int idx)
{
    if (!s.size() || s.size() == '1')
        return s;

    if (s[idx] == '1' && s[idx + 1] == '0')
    {
        
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string ans = helper(s);
        cout << ans << "\n";
    }

    return 0;
}
