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
    int n,m;
    cin >> n >> m; 
    vector<int> a(n), b(m); 
    for(auto &i : a) cin >> i; //john
    for(auto &i : b) cin >> i; //jack 
    int asum = accumulate(a.begin(),a.end(),0); 
    int bsum = accumulate(b.begin(),b.end(),0); 
    //Make asum > bsum with min swaps, output the min swaps 

    if(asum > bsum){
        return void(cout<<"0\n"); 
    }

    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend()); 

    int ans = -1;
    for(int i = 0; i < min(n,m); i++){ 
        asum += (b[i]-a[i]); 
        bsum += (a[i]-b[i]); 
        if(asum > bsum){ans=i+1;break;}
    }

    cout << ans << "\n";
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