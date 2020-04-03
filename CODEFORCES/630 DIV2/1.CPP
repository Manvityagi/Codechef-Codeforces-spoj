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
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        LL x, y, x1, y1, x2, y2;
        if (x == x1 && x == x2 && y == y1 && y == y2){
            cout << "NO\n";
            continue;
        }
            cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (a <= y2 && b <= y1 && c <= x1 && d <= x2)
        {
            cout << "YES\n";
            continue;
        }
        if ((abs(c - d) <= x2 - x1) && (abs(a - b) <= y2 - y1))
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
    return 0;
}
