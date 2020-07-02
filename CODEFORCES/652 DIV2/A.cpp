
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define int LL
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
const int MAX_N = 2 * 1e5;

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n%4 != 0) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
