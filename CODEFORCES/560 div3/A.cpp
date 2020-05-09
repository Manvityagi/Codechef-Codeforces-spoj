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
const int MAX_N = 200 * 1000 + 5;
char a[MAX_N];

int main()
{
    LL n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    scanf("%s", &a);

    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        if (a[n - 1 - i] != (i == y ? '1' : '0'))
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
