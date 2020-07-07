#include <bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n, k;
    cin >> n >> k;

    vector<int> h(n), sum(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = n - 1; i <= n - k + 1, i >= 0; i--)
    {
        sum[n - 1] += h[i];
    }

    int ans = sum[n-1];
    int ansindex = n-k+1;

    for (int i = n - 2; i >= k - 1; i--)
    {
        sum[i] = sum[i+1]-h[i+1]+h[i-k+1];
        if(sum[i] < ans){
            ans = sum[i];
            ansindex = i-k+1;
        }
    }

    cout << ansindex;


}