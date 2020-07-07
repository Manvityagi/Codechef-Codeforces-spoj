
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
const int MAX_N = 2 * 1e5;
char a[MAX_N];

void findminmax(LL dig, LL &mn, LL &mx)
{
    while (dig > 0)
    {
        LL curr = dig % 10;
        mn = min(curr, mn);
        mx = max(curr, mx);
        dig /= 10;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int n; 
       cin>>n;
       vector<int> arr(n);

       for(int i = 0; i < n; i++)
       {
           cin >> arr[i];
       }

       sort(arr.begin(),arr.end());

       vector<int> diff;

        int ans = INT_MAX;
       for(int i = 1; i < n; i++)
       {
           ans = min(ans,arr[i] - arr[i-1]);
       }

       cout << ans << "\n";
    }

    return 0;
}
