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

char helper(char a, char b){
    for(char c = 'a'; c <= 'z'; c++){
        if(c != a && c != b) return c;
    }
    return 'z';
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i-1]) continue; 
        s[i] = helper(s[i-1],s[i+1]); 
    }
    cout << s;
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

    while (t--)
    {
        solve();
    }
    return 0;
}