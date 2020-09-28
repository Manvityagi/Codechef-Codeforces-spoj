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
        LL n, k;
        cin >> n >> k;
        if (k % n)
            cout << 2 << "\n";
        else
            cout << 0 << "\n";

        vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
        int i = 0, j = 0;
        while (k--)
        {
            if (i >= n)
                i = 0, j++, j %= n;

            ans[i++][j++] = 1;
            j %= n;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}
