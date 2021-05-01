
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
unordered_map<int,int> diag_vals;

bool fillHelper(vector<vector<int>> mat){
    int r = mat.size(), c = mat[0].size(); 

    



}

void solve()
{
    diag_vals.clear(); 
    int r,c;
    cin >> r >> c; //500 
    vector<vector<int>> mat(r,vector<int>(c)); //1e9 

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> mat[i][j]; 
    }

     bool curr = fillHelper(mat); 

    int q; //2*1e5 
    cin >> q; 
    while(q--){
        int x,y,v; 
        cin >> x >> y >> v; 

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