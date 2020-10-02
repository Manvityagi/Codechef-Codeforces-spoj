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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
#define int LL
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
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n); 
        for(auto &i : a) cin >> i; 
        sort(a.begin(),a.end());
        cout << n/2 << "\n"; 
        vector<int> ans; 

        for(int idx = 0, j = n/2 ; j < n && idx < n; j++, idx += 2){
            ans[idx] = a[j]; 
        }

        for(int idx = 1, i = 0; i < n && idx < n; i++,idx += 2){
            ans[idx] = a[i];
        }

        for(auto i : ans) cout << i << " ";
     }
    return 0;
}
