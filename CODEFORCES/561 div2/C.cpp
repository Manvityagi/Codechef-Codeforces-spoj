#include <bits/stdc++.h>
using namespace std;
int MAX_N = 2 * 1e5;

int main()
{
    int n;
    scanf("%d", &n);
    vector<long long> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x)
            arr.push_back(abs(x));
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i && arr[i] == arr[i - 1])
        {
            ans++;
        }

        ans += (upper_bound(arr.begin(), arr.end(), 2 * arr[i]) - upper_bound(arr.begin(),arr.end(),arr[i]));
    }

    printf("%lld", ans);
}
