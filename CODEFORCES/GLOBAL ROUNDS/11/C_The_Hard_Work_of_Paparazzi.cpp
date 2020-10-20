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
    // cin >> t;
    while (t--)
    {
        int n, r;
        cin >> r >> n;
        vector<int> t(n+1), x(n+1), y(n+1); 
        for(int i = 1; i <= n; i++){
            cin >> t[i] >> x[i] >> y[i]; 
        }
        t[0] = 0, x[0] = 1, y[0] = 1; 

        //dp = ans
        vector<int> dp(n+1), suffixMx(n+1); 
        dp[n] = 1; 
        suffixMx[n] = 1; 
        suffixMx[n+1] = 0;
        for(int i = n-1; i >= 0; i--){
            int curr = 0; 
            int j = i+1; 
            while(j <= n){
                if(t[j] - t[i] > 2*r) break; 
                int dis = abs(x[i] - x[j]) + abs(y[i] - y[j]); 
                if(dis <= t[j] - t[i]){
                    curr = max(curr,dp[j]); 
                }
                j++;
            }
            curr = max(curr,suffixMx[j]);
            dp[i] = 1 + curr; 
            suffixMx[i] = max(dp[i],suffixMx[i+1]);
        }
        cout << dp[0] - 1; 
     }
    return 0;
}
