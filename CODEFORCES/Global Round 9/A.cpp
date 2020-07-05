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

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<int> arr(n);
        if (!n)
        {
            continue;
        }
        if (n == 1)
        {
            cout << arr[0] << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = abs(arr[i]);
        }

        bool inc = 0;
        if (arr[1] > arr[0])
        {
            inc = 1;
        }

        for (int i = 2; i < n; i++)
        {
            if ((arr[i] < arr[i - 1] && inc == 1) || (arr[i] > arr[i - 1] && inc == 0))
            {
                continue;
            }

            if (inc)
            {
                arr[i] = -1 * arr[i];
            }
            else
            {
                arr[i-1] = -1 * arr[i-1];
            }
        }

        for(auto &a : arr) cout << a << " ";
        cout << "\n";
    }
    return 0;
}
