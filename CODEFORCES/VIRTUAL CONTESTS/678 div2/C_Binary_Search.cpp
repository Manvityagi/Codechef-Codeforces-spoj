
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
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

int fact(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return (x % MOD1 * fact(x - 1) % MOD1) % MOD1;
}

void solve()
{
    int n,x,pos;
    cin >> n >> x >> pos;
    int st = 0, end = n;
    int ans = 1, cnt = 0;
    int small = x - 1, big = n - x;
    while (st < end)
    {
        // cout << "stend " << st << " " << end << "\n";
        int mid = (st + end) / 2;
        cnt++;
        // cout << "posmid " << pos << " " << mid << "\n";
        if(mid == pos){
            st = mid+1;
            continue; 
        }

        if (pos > mid)
        {
            //right bhejna hai st=mid+1, arr[mid] < arr[pos] (x)
            st = mid + 1;
            ans = (ans % MOD1 * small % MOD1) % MOD1;
            small--;
        }
        else if (pos < mid)
        {
            end = mid;
            ans = (ans % MOD1 * big % MOD1) % MOD1;
            big--;
        }
    }
    if (n - cnt >= 0)
    {
        int add = fact(n - cnt);
        ans = (ans % MOD1 * add % MOD1) % MOD1;
    }

    cout << ans << "\n";
}

signed main()
{
    solve();
    return 0;
}