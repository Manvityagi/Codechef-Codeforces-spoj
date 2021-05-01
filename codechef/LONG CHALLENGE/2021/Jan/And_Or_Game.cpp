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
int n,m;

void solve()
{
    cin >> n >> m; 
    vector<int> a(n), b(m); 
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    int v = 0, ans = 1; 
    unordered_set<int> st; 
    st.emplace(v);
    unordered_set<int> vis;
    vis.emplace(v); 

    while(!st.empty()){
        int v = *st.begin(); 
        st.erase(st.begin()); 
        for(int i = 0; i < n; i++){
            int curr = v | a[i]; 
            if(vis.find(curr) == vis.end()){st.emplace(curr); vis.emplace(curr); ans++;}
        }
        for(int i = 0; i < m; i++){
            int curr = v & b[i]; 
            if(vis.find(curr) == vis.end()){ st.emplace(curr); vis.emplace(curr); ans++;}
        }
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