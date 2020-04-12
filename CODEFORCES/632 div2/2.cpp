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

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        if (a[0] != b[0])
        {
            cout << "NO\n";
            continue;
        }

        bool zero = 0, minus = 0, one = 0, found = 0;
        for (int i = 0; i < n; i++)
        {

            if (b[i] > a[i] && !one)
            {
                cout << "NO\n";
                found = true;
                break;
            }

            if (b[i] < a[i] && !minus)
            {
                cout << "NO\n";
                found = true;
                break;
            }

            if (a[i] == 0)
            {
                zero = true;
            }
            if (a[i] == 1)
            {
                one = true;
            }
            if (a[i] == -1)
            {
                minus = true;
            }
        }

        if(!found){
            cout << "YES\n";
        }
    }
    return 0;
}
