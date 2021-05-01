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

void solve(){
    int n; 
    cin >> n; 
    vector<int> a(n);
    priority_queue<int> o, e; 
    int esum = 0, osum = 0; 
    for(auto &i : a){
        cin >> i;
        if(i&1) {
            o.emplace(i); 
        } 
        else{
            e.emplace(i); 
        } 
    } 

    int eidx = 0, oidx = 0; 

    int bob = 0, alice = 0; 
    for(int i = 0; i < n; i++){
        int omx = -1; 
        if(!o.empty()){
            omx = o.top(); 
            // o.pop(); 
        }
        int emx = -1; 
        if(!e.empty()){
            emx = e.top();
            // e.pop(); 
        }
        if(omx == -1 && emx == -1) break; 

        if(i & 1){
            //bob 
            if(omx > emx){
                if(!o.empty()){
                    bob += omx; 
                    o.pop(); 
                }
            } else {
                if(!e.empty())
                e.pop(); 
            }
        } else {
            if(emx > omx){
                if(!e.empty()){
                    alice += emx;
                    e.pop();  
                }
            } else {
                if(!o.empty())
                o.pop(); 
            }
        }
    }

    // cout << alice << ": " << bob << "\n";

    if(alice > bob){
        cout << "Alice\n"; 
    } else if(alice < bob){
        cout << "Bob\n"; 
    } else {
        cout << "Tie\n";
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