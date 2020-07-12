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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

LL helper(LL a, LL b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        if (!(n & 1))
        {
            cout << n / 2 << " " << n / 2;
        }

        else
        {
            bool prime = 1;
            LL f1 = -1, f2 = -1;
            for (int i = 3; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    prime = 0;
                    f1 = i;
                    f2 = n / i;
                    break;
                }
            }

            if (prime)
            {
                cout << 1 << " " << n - 1;
            }
            else
            {
                // LL ans1 = LONG_LONG_MAX, ans2 = LONG_LONG_MAX;
                LL t1 = f1, t2 = n - f1;
                LL r1 = f2, r2 = n - f2;
                LL ans1 = helper(t1, t2);
                LL ans2 = helper(r1, r2);
            }
        }
        cout << "\n";
    }
    return 0;
}
