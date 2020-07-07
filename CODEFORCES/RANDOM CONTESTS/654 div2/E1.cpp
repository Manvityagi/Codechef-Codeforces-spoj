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

    LL n, p;
    cin >> n >> p;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    int mini = arr[0], maxi = arr[n - 1];

    vector<int> res;
    int ans = 0;
    for (int x = mini; x <= maxi; x++)
    {
        int xx = x;
        //permutation ka size to n hi hoga
        int totalcount = 1;
        for (int i = 0; i < n; i++)
        {
            int choices = upper_bound(arr.begin(), arr.end(), xx) - arr.begin();
            choices = choices - i;
            if (choices % p == 0) 
            {
                totalcount = 0;
                break;
            }
            xx++;
        }
        if (totalcount % p != 0)
        {
            res.push_back(x);
            ans++;
        }
    }
    cout << ans << "\n";
    for (auto &a : res)
        cout << a << " ";
    return 0;
}