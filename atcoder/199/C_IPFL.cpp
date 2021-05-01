
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
    string s;
    cin >> s; 
    int q;
    cin >> q; 
    while(q--){
        int t, ai, bi; 
        cin >> t >> ai >> bi;
        if(t == 1){
            swap(s[ai],s[bi]);
        } else {
            int st = 0, end = n; 
            while(st < n){
                swap(s[st],s[end]);
                st++,end++;
            }
        }
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
    // cin >> t;

    while (t--){
        solve();
    }
    return 0;
}