#include <bits/stdc++.h>
using namespace std;
int m, n, d;
main()
{
    cin >> m >> n >> d;
    int ans = 0;
    vector<int> arr(m * n);
    int r = arr[0] % d;
    for (int i = 1; i < m * n; i++)
    {
        cin >> arr[i];
        if (arr[i] % d != r)
        {
            cout << -1;
            return 0;
        }
    }
    sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(arr[i] - arr[n / 2]) / d;
    cout << ans << endl;
}