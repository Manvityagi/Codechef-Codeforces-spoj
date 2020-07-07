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
    while(t--)
    {
        LL n,k;
        cin >> n >> k;
        LL x = ceil((k*1.0)/(n-1));
        LL ans = x+k-1;
        cout << ans << "\n";
        
    }

    return 0;
}
