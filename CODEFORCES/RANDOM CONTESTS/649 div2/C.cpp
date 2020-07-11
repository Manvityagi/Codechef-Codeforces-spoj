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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<int> extras;
        vector<int> arr(n + 1), ans, present(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            present[arr[i]] = 1;
        }
        for (int i = 0; i <= n; i++)
            if (!present[i])
                extras.push_back(i);
        extras.push_back(n + 1);

        int e = 0;
        for (int i = 1; i <= n; i++)
        {
            //if i == 1,
            //if a[i] = 0
            //ans[i] = extras me se kuch
            //if(a[i] == 1)
            //ans[i] = 0

            //if arr[i] != arr[i-1]
            //ans[i] = ans[i-1]
            //else
            //ans[i] = extras[e++]

            if (i == 1)
            {
                if (arr[i] == 0)
                    ans[i] = extras[e++];
                else
                    ans[i] = 0;
            }
            else if (arr[i] != arr[i - 1])
                ans[i] = ans[i - 1];
            else
                ans[i] = extras[e++];
        }

        for (auto a : ans)
            cout << a << " ";
    }
    return 0;
}
