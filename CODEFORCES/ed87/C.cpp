

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
const double pi = acos(-1.0);
const int MAX_N = 2 * 1e5;
char a[MAX_N];

int main()
{
    int t;
    cin >> t;
    cout << fixed << setprecision(8);
    while (t--)
    {
        int n;
        cin >> n;

        cout << 1.0 / tan(pi / (2 * n)) << "\n";
    }

    return 0;
}
