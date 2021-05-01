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
    vector<int> a(n); 
    int o = 0, t = 0;
    for(auto &i : a){
        cin >> i; 
        if(i==1)o++;
        else t++; 
    }
    if(o == 2*t){return void(cout<<"YES\n");}
    int s = accumulate(a.begin(),a.end(),0); 
    if(s&1 || (o == 0 && (t&1))){return void(cout<<"NO\n");}

    cout << "YES\n";

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