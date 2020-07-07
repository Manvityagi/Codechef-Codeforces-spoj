
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

void findminmax(LL dig, LL &mn, LL &mx)
{
    while (dig > 0)
    {
        LL curr = dig % 10;
        mn = min(curr, mn);
        mx = max(curr, mx);
        dig /= 10;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL a1, k;
        cin >> a1 >> k;
        k--;
        LL mn = 9;
        LL mx = 0;

        findminmax(a1, mn, mx);
        while (k-- && mn)
        {
            a1 += mn * mx;
            mn = 9, mx = 0;
            findminmax(a1, mn, mx);
        }
        

        cout << a1 << "\n";
    }

    return 0;
}
