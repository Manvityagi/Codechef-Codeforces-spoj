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
    vector<pii> hw(n); 
    vector<pii> orig; 
    for(auto &i : hw) cin >> i.F >> i.S;
    orig = hw; 
    sort(hw.begin(),hw.end()); 
    vector<int> h, w; 
    for(int i = 0; i < n; i++){
        // cin >> h[i] >> w[i];
        h.emplace_back(h[i]); 
        w.emplace_back(w[i]); 
    }

    for(auto p : orig){
        int hi = p.F, wi = p.S; 
        int idx = lower_bound(h.begin(),h.end(),hi)-h.begin(); 
        
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
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}