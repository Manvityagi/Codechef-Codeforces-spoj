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

string rotate(string s, int i){
    string ans; 
    // cout << "orign " << s << ":" << i << "\n";
    int n = s.size(); 
    string p1 = s.substr(i,n-i); //i to end 
    string p2 = s.substr(0,i); //0 to i 
    ans = p1 + p2; 
    // cout << "ans " << ans << "\n"; 
    return ans; 
}

void solve(){
    int n;
    cin >> n; 
    vector<string> p(n); 
    for(auto &i : p)cin >> i;
    int ans = INT_MAX; 
    for(auto &s : p){
        string target = s; 
        int rot = 0;
        for(auto t : p){
            bool found = 0;
            if(t == target) continue; 
            for(int i = 0; i < t.size(); i++){
                string curr = rotate(t,i); 
                if(curr == target){
                    found = 1; 
                    rot += i; 
                    break;
                }
            }
            if(!found){
                // cout << "mess here " << target << " " << t << "\n";
                ans = -1;
                break;
            }
        }
        if(ans == -1) break;
        ans = min(ans,rot); 
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
    // cin >> t;

    while (t--){
        solve();
    }
    return 0;
}