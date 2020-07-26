#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n, m, x, y;
        cin >> n >> m >> x >> y;
        LL first = min(x, y);
        LL second = y - first;
        LL tot = n * m;

        LL small = tot / 2, big = tot - small; //multipliers

        if (first < second)
            swap(first, second);

        LL ans = big * first + small * second;
        cout << ans << "\n";
    }
    return 0;
}
