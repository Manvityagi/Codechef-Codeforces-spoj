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

    LL n;
    cin >> n;
    LL ans;
    if (n == 1)
        ans = 1;
    else if (n == 2)
        ans = 2;
    else if (n == 3)
        ans = 6;
    else if (n % 2 == 0)
    {
        if (n % 3 == 0)
            ans = (n - 1) * (n - 2) * (n - 3);
        else
            ans = n * (n - 1) * (n - 3);
    }
    else
        ans = n * (n - 1) * (n - 2);
    cout << ans << endl;

    return 0;
}
