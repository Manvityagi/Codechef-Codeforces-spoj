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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

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
        for (auto &i : arr)
            cin >> i;

        vector<int> ans;
        //inc, dec subsqeuences ke break points answer me daalne hai
        int i = 1;
        ans.push_back(arr[0]);
        while (i < n)
        {
            bool inc = 0;
            while (i < n && arr[i] > arr[i - 1])
            {
                inc = 1;
                i++;
            }
            if (inc)
                ans.push_back(arr[i - 1]);

            bool dec = 0;
            while (i < n && arr[i] < arr[i - 1])
            {
                dec = 1;
                i++;
            }
            if (dec)
                ans.push_back(arr[i - 1]);
        }

        cout << ans.size() << "\n";
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
