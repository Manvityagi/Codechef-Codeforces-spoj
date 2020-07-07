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
    LL n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int day = 1, i, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (day <= arr[i])
        {
            day++;
        }
    }

    cout << day;

    return 0;
}
