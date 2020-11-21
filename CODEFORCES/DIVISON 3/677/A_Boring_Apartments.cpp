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
    string x;
    cin >> x; 

    int cnt = (x[0]-'0')-1;
    cnt *= 10; 
    if(x.size() == 1) cnt++;
    else if(x.size() == 2) cnt += 3;
    else if(x.size() == 3) cnt += 6;
    else if(x.size() == 4) cnt += 10;

    cout << cnt << "\n";
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