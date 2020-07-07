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

    LL a, b, c, d, luckz = -1, lucky = -1, res = 0;
    cin >> a >> b >> c >> d;
    for (int i = c; i <= d; i++)
    {
        for (int j = b; j <= c; j++)
        {
            if ((i - j) <= b)
            {
                luckz = i;
                lucky = j;
            }

            if (luckz != -1)
            {
                LL cnt = (b - a) - (luckz - lucky) + 1;
                if(cnt > 0)
                res += cnt;
            }
            luckz = -1;
        }
    }

    if (luckz == -1)
    {
        cout << 0;
        return 0;
    }

    cout << res;

    return 0;
}
