
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

void erast()
{
    int n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
        int ro, co;
        cin >> ro >> co;

        if (ro != 1 && co != 1)
        {
            cout << 27 << endl;
            ro = (ro + co) / 2;
            co = ro;
            cout << ro << " " << co << endl;
            cout << 1 << " " << 1 << endl;
        }
        else
        cout << 25 << endl;

        int x0 = 2, y0 = 2;
        int x1, y1, x2, y2, x3, y3;

        while (x0 != 8 && y0 != 8)
        {
            cout << x0 << " " << y0 << endl;
            if (x0 == 2 || x0 == 3 || x0 == 4)
            {
                y1 = 1, x1 = 2 * x0 - 1;
                cout << x1 << " " << y1 << endl;
                cout << y1 << " " << x1 << endl;
                cout << x0 << " " << y0 << endl;
            }
            else
            {
                x1 = 8, y1 = y0 - (x1 - x0);
                cout << x1 << " " << y1 << endl;
                cout << y1 << " " << x1 << endl;
                cout << x0 << " " << y0 << endl;
            }

            x0++, y0++;
        }
        cout << x0 << " " << y0 << endl;
    }
    return 0;
}
