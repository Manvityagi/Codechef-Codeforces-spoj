
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
const int maxn = 1e7 + 1;

void solve()
{
    int n,s,k; 
    cin >> n >> s >> k; 
    int moves = 0, throne = 1, curr = s+1; 
    unordered_set<int> vis; 
    vis.emplace(curr); 
    while(moves < maxn){
        if(curr == throne) {
            cout << moves << "\n"; 
            return;
        }
        curr = (curr+k)%n; 
        if(vis.find(curr) != vis.end()) break; 
        vis.emplace(curr);
        moves++; 
    }

    cout << -1 << "\n"; 
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