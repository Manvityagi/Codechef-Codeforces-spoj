#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD1 1000000007
#define MOD2 1000000009

LL primeFactors(int n)
{
    LL pf = 0;
    while (n % 2 == 0)
    {
        pf++;
        n = n / 2;
    }

    for (LL i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            pf++;
            n = n / i;
        }
    }

    if (n > 2)
        pf++;

    return pf;
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
    //if number of prime factors of x are more than k, then ans is 1, otherwise 0
    while (t--)
    {
        LL x, k;
        cin >> x >> k;

        if (primeFactors(x) >= k)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}
