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
#define pll pair<LL,LL> 
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
        vector<pll> a;
        for (LL i = 0; i < n; i++){
            LL curr;
            cin >> curr;
            a.emplace_back(curr,i);
        }
        sort(a.begin(),a.end());
        unordered_map<LL,LL> mp; 

        for(LL i = 0; i < n; i++){
            if(mp.find(a[i].first) == mp.end()){
                mp[a[i].first] = i;
            }
        }

        vector<LL> ans(n);

        for (LL i = 0; i < n; i++)
        {
            int currans = a[i].first;
            if(mp.find(a[i].first) != mp.end()) currans += (i - mp[a[i].first]); 
            ans[a[i].second] = currans; 
            if(mp.find(currans) == mp.end()) mp[currans] = i; 
            else if(mp[currans] > i) mp[currans] = i;
        }

        for(auto a : ans){
            cout << a << " ";
        }
    }
    return 0;
}
