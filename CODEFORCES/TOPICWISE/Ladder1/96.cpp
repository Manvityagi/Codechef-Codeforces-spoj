#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1e9 + 7;
LL f1, f2, fn;
main()
{
    cin >> f1 >> f2 >> fn; 
    fn = fn / 4;

    if (fn == f1)
    {
        cout << f1%mod;
    }
    else if (fn == f2)
    {
        cout << f2%mod;
    }
    else if (fn == 2)
    {
        cout << (f1%mod + f2%mod)%mod;
    }
    else if (fn == 3)
    {
        cout << (f2%mod - f1%mod)%mod;
    }
    else if (fn == 1)
    {
        cout << (f2%mod - f1%mod)%mod;
    }
}