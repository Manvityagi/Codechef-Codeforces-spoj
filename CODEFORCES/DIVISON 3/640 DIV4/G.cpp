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
        int n;
        cin >> n;

        if (n < 4)
        {
            cout << -1 << "\n";
            continue;
        }

        //print all odd integres first

        for (int i = n; i >= 1; i--)
        {
            if (i & 1)
            {
                cout << i << " ";
            }
        }

        cout << 4 << " " << 2 << " ";

        int even = 6;

        while (even <= n)
        {
            cout << even << " ";
            even += 2;
        }

        cout << "\n";
    }
    return 0;
}
