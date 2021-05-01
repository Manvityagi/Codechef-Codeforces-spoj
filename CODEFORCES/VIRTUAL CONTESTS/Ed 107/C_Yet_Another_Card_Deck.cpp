
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
    int n,q; 
    cin >> n >> q; 
    vector<int> a(n); 
    unordered_map<int,vector<int>> pos;  
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i--){
        mp[a[i]].emplace_back(i); 
    }

    while(q--){
        int col; 
        cin >> col;
        int idx = mp[col].back(); 
        cout << idx << " "; 
        mp[col].pop_back(); 
        mp[col].emplace_back(0);
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