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
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<LL> arr(n);
        for (auto &i : arr)
            cin >> i;
        LL q;
        cin >> q;
        while (q--)
        {
            LL x, y;
            cin >> x >> y;
            LL ans = 0;
            int start = 0, end = n - 1;
            while (start <= end)
            {
                int mid = start + end >> 1;
                if (x + y == arr[mid])
                {
                    ans = -1;
                    break;
                }
                else if (x + y > arr[mid])
                {
                    start = mid + 1;
                    ans = mid + 1;
                }
                else if (x + y < arr[mid])
                {
                    start = mid + 1;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
