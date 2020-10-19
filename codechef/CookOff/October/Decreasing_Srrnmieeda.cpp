
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
#define int LL
int w, n;
vector<int> x;
int l,r; 

bool cal(int n){
    for(int i = l; i < r; i++){
        if(n%(i+1) >= n%i) return 0;
    }
    return 1;
}

void solve()
{
    cin >> l >> r; 
    if(l == 1){
        cout << -1;
    } else {
        int gap = r - l; 
        if(gap >= l){
            cout << -1;
        } else {
            cout << gap + l;
        }
    }

    cout << "\n";

}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}