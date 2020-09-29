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

int main()
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
        LL n, w;
        cin >> n >> w;
        vector<int> a(n);
        for(auto &i : a) cin >> i; 
        vector<int> pre(n); 
        pre = a;
        int mn = a[0], mx = a[0]; 
        for(int i = 1; i < n; i++){
            pre[i] += pre[i-1]; 
            mn = min(pre[i],mn);
            mx = max(pre[i],mx); 
        } 
        
        int ans;
        int mxAllowed = w - mx;
        int mnAllowed = max(0,mn); 
        ans = mxAllowed - mnAllowed;
        cout << ans;
     }
    return 0;
}
