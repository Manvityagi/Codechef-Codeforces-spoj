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

    LL t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;

        vector<LL> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), greater<LL>());

        vector<LL> ans(n);
        LL cnt = 0, st = 0, end = n - 1, i = n - 1;
        while (st < end && i >= 0)
        {
            if (cnt & 1)
            {
                ans[i--] = arr[end--];
            }
            else
            {
                ans[i--] = arr[st++];
            }
        }

        for(auto e : ans){
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
