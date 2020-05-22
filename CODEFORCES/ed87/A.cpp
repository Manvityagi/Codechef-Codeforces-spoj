

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
const int MAX_N = 2 * 1e5;
char a[MAX_N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a <= b)
        {
            cout << b << "\n";
            continue;
        }

        if (a > b && c <= d)
        {
            cout << -1 << "\n";
            continue;
        }

        LL f = (a - b) / (c - d);
        if ((a - b) & 1)
            f++;
        // cout << "f " << f << "\n";
        LL ans = f * c + b;
        cout << ans << "\n";
    }

    return 0;
}
