
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
        int a, b;
        cin >> a >> b;
        int ans, ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX;

        if (2 * b <= a)
        {
            ans1 = a * a;
        }

        if (2 * a <= b)
        {
            ans2 = b * b;
        }

        ans3 = 2 * min(a, 2 * b);
        ans3 = ans3 * ans3;

        ans4 = 2 * min(2 * a, b);
        ans4 = ans4 * ans4;

        ans = min(ans1, min(ans2, min(ans4, ans3)));
        cout << ans << "\n";
    }

    return 0;
}
