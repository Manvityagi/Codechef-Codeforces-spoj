#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1e9 + 7;
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
    return ((a % mod - b % mod + M) % mod);
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
    LL a, b, n, x;
    cin >> a >> b >> n >> x;
    if (a == 0)
    {
        cout << x;
        return 0;
    }
    LL ans;
    LL t1, t2;
    LL an = power(a, n);
    t1 = mul(an, x);

    LL gp = divi(sub(power(a, n), 1), sub(a, 1));
    t2 = mul(b, (a == 1 ? n : gp));

    // cout << t1 << " " << t2 << "\n";
    ans = ad(t1, t2);

    cout << ans;
}
