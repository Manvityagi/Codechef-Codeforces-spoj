#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define mod 1000000007
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
const int N = 1e5+10;
vector<int> g[N];
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
LL power(LL x, LL y)
{
    x %= mod;
    LL ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % mod;
        y >>= 1LL;
        x = (x * x) % mod;
    }
    return ans;
}
LL ad(LL a, LL b)
{
    return ((a % mod + b % mod) % mod);
}
LL sub(LL a, LL b)
{
    return ((a % mod - b % mod + mod) % mod);
}
LL mul(LL a, LL b)
{
    return (((a % mod) * (b % mod)) % mod);
}
LL divi(LL a, LL b)
{
    return (mul(a, power(b, mod - 2)) % mod);
}
int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n, m;
        for(int i=0;i<m;i++){
            int src,dest;
            cin>>src>>dest;
            g[src].PB(dest);
        }        
        
    }
    return 0;
}
