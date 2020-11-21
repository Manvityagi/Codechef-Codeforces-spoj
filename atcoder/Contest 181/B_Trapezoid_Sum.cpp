
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
#define pii pair<int,int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

void solve()
{
    int n;
    cin >> n; 
    int ans = 0;
   
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        // cout << a << ": " << b << "\n";
        a--;
        int s2 = (b * (b + 1))/2;
        int s1 = (a * (a+1))/2;
        int curr = s2 - s1;
        // cout << s1 << "  : " << s2 << "\n";
        // cout << curr << "\n";
        ans += (s2 - s1);
    }
    cout << ans;
    
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

    while (t--){
        solve();
    }
    return 0;
}