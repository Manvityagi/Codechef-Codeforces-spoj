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
const int N = 1e6 + 10;
vector<int> f(N, 2);
bool prime(int n)
{
    // Assumes that n is a positive natural number
    // We know 1 is not a prime number
    if (n == 1)
    {
        return false;
    }

    int i = 2;
    // This will loop from 2 to int(sqrt(x))
    while (i * i <= n)
    {
        // Check if i divides x without leaving a remainder
        if (n % i == 0)
        {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return false;
        }
        i += 1;
    }
    // If we did not find any factor in the above loop,
    // then n is a prime number
    return true;
}
int helper(int n)
{

    for (int j = 3; j * j <= n; j += 2)
    {
        if (n % j == 0)
        {
            return j;
        }
    }
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
    preprocess();
    while (t--)
    {
        LL n, k;
        cin >> n >> k;

        if (!(n & 1))
        {
            cout << n + k * 2 << "\n";
        }
        else
        {
            if (prime(n))
            {
                cout << 2 * n + (k - 1) * 2 << "\n";
            }
            else
            {
                LL temp = helper(n);
                cout << n + (k - 1) * 2 + temp << "\n";
            }
        }
    }
    return 0;
}
