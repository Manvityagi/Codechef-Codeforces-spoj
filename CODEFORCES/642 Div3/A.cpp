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
        int n, m;
        cin >> n >> m;

        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        if (n == 2)
        {
            cout << m << "\n";
            continue;
        }

        cout << 2 * m << "\n";
    }

    return 0;
}
