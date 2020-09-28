#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL LCM(LL a, LL b)
{
    return a / __gcd(a, b) * b;
}

LL helper()
{
    LL n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    LL cnta = 0, cntb = 0;
    LL lcm = LCM(a, b);
    cnta = n / a;
    cntb = n / b;
    LL com = n / lcm;

    cnta -= com;
    cntb -= com;

    LL ans = cnta * p + cntb * q;
    if (p > q)
        ans += com * p;
    else
        ans += com * q;
    return ans;
}

signed main()
{

    cout << helper();
}