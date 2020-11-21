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
#define eb emplace_back
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
bool same(vector<int> a)
{
    int f = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != f)
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (same(a))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int rootgang = a[0], notroot;
    vector<pii> ans; 
    for(int i = 1; i < n; i++){
        if(a[i] != rootgang){
            ans.eb(1,i+1);
            notroot = i+1;
        }
    }

    for(int i = 1; i < n; i++){
        if(a[i] == rootgang){
            ans.eb(notroot,i+1);
        }
    }

    for(auto p : ans){
    cout << p.F << " " << p.S << "\n";
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

    while (t--)
    {
        solve();
    }
    return 0;
}