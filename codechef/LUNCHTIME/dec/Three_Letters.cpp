
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

void solve()
{
    string s;
    cin >> s;
    int n = s.size(),ans=0;
    vector<int> freq(26); 
    for(auto c : s){
        freq[c-'a']++; 
    }
    
    for(int i = 0; i < 25; i++){
        ans += freq[i]/3; 

        freq[i] -= (freq[i]/3 * 3); 
    }

    int zero=0,one=0,two=0; 
    for(auto a : freq){
        if(a == 0) zero++;
        else if(a == 1) one++;
        else two++; 
    }
    ans += min(one,two); 
    two -= min(one,two); 

    if(two > 0){
        ans += two/2; 
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

    while (t--)
    {
        solve();
    }
    return 0;
}