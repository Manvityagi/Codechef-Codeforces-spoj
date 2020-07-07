
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

int main()
{
    LL t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        map<int, int> mp;
        mp.clear();
        vector<int> inx(n);
        for (int i = 0; i < n; i++)
        {
            cin >> inx[i];
            mp[inx[i]]++;
        }
        int ans = 0, rem = 0;
        for (auto it : mp)
        {
            LL num = rem;
            int no = it.first;
            int freq = it.second;
            rem = freq % no;
            num += freq;
            ans += num / no;
        }
        cout << ans << "\n";
    }
    return 0;
}
