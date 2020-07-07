
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, need_odd_idx = 0, need_even_idx = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if ((i & 1) && !(arr[i] & 1))
            {
                need_even_idx++;
            }

            if (!(i & 1) && (arr[i] & 1))
            {
                need_odd_idx++;
            }
        }

        if (need_even_idx == need_odd_idx)
        {
            cout << need_even_idx << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
