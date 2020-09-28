#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL n, k;
        cin >> n >> k;
        vector<int> arr(n);
        bool hopes = 0;
        for (auto &i : arr)
        {
            cin >> i;
            if (i == k)
                hopes = 1;
        }

        if (!hopes)
        {
            cout << "no\n";
            continue;
        }
        if (n == 1)
        {
            if (arr[0] == k)
                cout << "yes\n";
            else
                cout << "no\n";
            continue;
        }

        bool possible = 0;
        for (int i = 0; i < n; i++)
        {
            //2 length subarrays
            if (i + 1 < n && min(arr[i], arr[i + 1]) >= k)
            {
                possible = 1;
                break;
            }
        }

        if (possible)
        {
            cout << "yes\n";
            continue;
        }

        //3 length subarrays
        for (int i = 2; i < n; i++)
        {
            vector<int> tmp({arr[i], arr[i - 1], arr[i - 2]});
            sort(tmp.begin(), tmp.end());
            if (tmp[1] >= k)
            {
                possible = 1;
                break;
            }
        }
        if (possible)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
