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
    int t;
    cin >> t;
    while (t--)
    {
        LL n, k;
        cin >> n >> k;

        if (n < k)
        {
            cout << "NO\n";
            continue;
        }

        if (n == k)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << "\n";
            continue;
        }

        //odd se represnt ho sakta hai, agar n-(k-1) is odd
        //even se represent ho sakta hai, if n-(2*(k-1)) > 0 * is even

        if ((n - k + 1) & 1)
        {
            cout << "YES\n";
            for (int i = 1; i <= k - 1; i++)
            {
                cout << 1 << " ";
            }
            cout << n - k + 1 << "\n";
        }
        else if (n - (2 * (k - 1)) > 0 && !((n - (2 * (k - 1))) & 1))
        {
            cout << "YES\n";
            for (int i = 1; i <= k - 1; i++)
            {
                cout << 2 << " ";
            }
            cout << n - (2 * (k - 1)) << "\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }

    return 0;
}
