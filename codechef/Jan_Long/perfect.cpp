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
#define INF LONG_MAX
#define pr(i, x, n)                    \
    for (int ii = i; ii < n + i; ii++) \
    {                                  \
        cout << x[ii] << " ";          \
    }                                  \
    cout << endl;
#define ip(i, x, n)                    \
    for (int ii = i; ii < n + i; ii++) \
    {                                  \
        cin >> x[ii];                  \
    };
#define db(x, y) cout << x << " " << y << endl;
#define LD long double
#define PR pair<LD, LL>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1) { 
            result = (result*base) ;
        }
        base = (base * base) ;
        power = power >>= 1;
    }
    return result ;
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

        //read n;
        LL n;
        cin >> n;

        //read A - n-perfect number
        LL A;
        cin >> A;

        LL mini = 1, maxi = fast_power(10, n) - 1;

        //it can be a random number
      
        LL S = A + 2 * mini + maxi % MOD2 + maxi % MOD2;
        cout << S << endl;

        LL B, C, D, E;
        // B,C,D,E are n-perfect numbers
        //read B
        cin >> B;

        C = (maxi - B + mini);
        cout << C << endl;

        cin >> D;

        E = (maxi - D + mini);
        cout << E << endl;

        LL result;
        cin >> result;
        if (result == -1)
        {
            return 0;
        }
       
    }

    return 0;
}