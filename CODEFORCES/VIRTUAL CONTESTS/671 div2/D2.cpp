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
        if(n == 1 || n == 2){
        	cout << 0 << "\n"; 
        	for(auto i : a) cout << i << " ";
        	continue;
        }
        sort(a.begin(),a.end());
        // cout << (n-1)/2 << "\n";
        int cnt = 0; 
        vector<int> ans(n); 
		int idx = 0; 

        int idx = 0;
        for(int i = 1; i < n; i+=2){
            ans[i] = a[idx++];
        }

        for(int i = 0; i < n; i+=2){
            ans[i] = a[idx++];
        }

        for(int i = 1; i < n-1; i++){
            if(ans[i] < ans[i-1] && ans[i] < ans[i+1]) cnt++;
        }

        cout << cnt << "\n";
        for(auto i : ans) cout << i << " " ;
        cout << "\n";
        
     }
    return 0;
}
