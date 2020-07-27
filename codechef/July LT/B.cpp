#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n, m, x, y, ans = 0;
        cin >> n >> m >> x >> y;
        if (n == 0 || m == 0 || x == 0 || y == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        LL total = n * m;
        //case 1: n*m = odd
        if (total & 1)
        {
            if (x >= y)
            {
                ans = total / 2 * x + x;
            }
            else
            {
                x = y;
                ans = total / 2 * x + x;
            }
        }
        else //case 2: n*m = even
        {
            if (x >= y)
            {
                ans = total / 2 * x;
            }
            else
            {
                x = y;
                ans = total / 2 * x;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
