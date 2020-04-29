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

void solve()
{
    LL n, i;
    cin >> n;

    if ((n / 2) & 1)
    {
        cout << "NO \n";
        return;
    }

    set<LL> eset, oset;

    LL even = 2;

    while(even <= n)
    {
        eset.insert(even);

        for(LL subo = 1; subo < even; subo+=2){
            LL currodd = even-subo;
            if(oset.find(currodd) == oset.end())
            {
                oset.insert(currodd);
                even +=2;
                eset.insert(even);
                oset.insert(even-currodd);
                break;
            }
        }
    }

    cout << "YES\n";
    for (auto e : eset)
    {
        cout << e << " ";
    }
    for (auto o : oset)
    {
        cout << o << " ";
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
