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
#define loop(i, a, b) for (LL i = a; i < b; i++)
LL n, k, ans = 0;
LL movex[] = {0, 0, 1, -1};
LL movey[] = {1, -1, 0, 0};
LL valid[102][102], base[102][102];
//dp[i][j] = ith number hai, sequence ke jth index par 

void multiply(LL a[102][102], LL b[102][102])
{
    LL c[102][102];
    for(LL i = 0; i < n; i++){
        for(LL j = 0; j < n; j++){
            c[i][j] = 0;
            for(LL k = 0; k < n; k++) c[i][j] += a[i][k]*b[k][j]%MOD1;
            c[i][j] %= MOD1;
        }
    }
    for(LL i = 0; i < n; i++){
        for(LL j = 0; j < n; j++){
            a[i][j] = c[i][j];
        }
    }
}

void power(LL valid[102][102], LL k)
{
    if(k<2) return;
    power(valid,k>>1);
    multiply(valid,valid);
    if(k&1) multiply(valid,base);
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<LL> a(n);
        for(auto &i : a) cin >> i;
        if(k == 1) {cout<<n;return 0;};
        for(LL i = 0; i < n; i++){
            for(LL j = 0; j < n; j++){
                if(__builtin_popcountll(a[i]^a[j]) % 3 == 0) valid[i][j]=1, base[i][j]=1;
                else valid[i][j] = 0, base[i][j] = 0;
            }
        }
        power(valid,k-1);
        for(LL i = 0; i < n; i++){
            for(LL j = 0; j < n; j++){
                ans += valid[i][j];
                ans %= MOD1;
            }
        }
        cout << ans;
    }
    return 0;
}
