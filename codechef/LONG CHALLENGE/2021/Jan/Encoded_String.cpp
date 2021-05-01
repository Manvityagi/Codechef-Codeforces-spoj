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
int n; 
string s;
void solve(){
    cin >> n >> s;
    string ans; 
    for(int i = 0; i < n; i+=4){
        int st = 0, end = 15; 
        for(int j = i; j < i+4; j++){
            if(s[j] == '0') end = (st+end >> 1);      //first half 
            else st = (st+end>>1)+1; 
        }
        ans += char(end+97);  
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