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
const int MAX_N = 5e5 + 5;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        LL ans = 0;
        LL freq = n / 2;
        LL mul = 8;
        for (int i = 1; i <= freq; i++)
        {
            ans += (i * mul);
            mul *= i;
        }

        cout << ans << "\n";
    }

    return 0;
}
