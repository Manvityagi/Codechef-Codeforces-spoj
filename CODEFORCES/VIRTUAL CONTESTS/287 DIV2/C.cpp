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
// LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

void helper(LL h, LL ex, LL &i, bool left)
{
    if (h <= 0 || ex <= 0)
        return;
        
    LL total = 1LL << h; //nodes on last level
    // cout << "Nodes on last level " << total << "\n";
    if (left)
    {
        if (ex > total / 2)
        {
            i += total;
            helper(h - 1, ex - total / 2, i, left);
        }
        else
        {
            i += 1;
            helper(h - 1, ex, i, !left);
        }
    }
    else
    {
        if (ex <= total / 2)
        {
            i += total;
            helper(h - 1, ex, i, left);
        }
        else
        {
            i += 1;
            helper(h - 1, ex - total / 2, i, !left);
        }
    }
}

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
        LL h, ex;
        cin >> h >> ex;

        LL ans = 0;
        bool left = true;
        helper(h, ex, ans, left);
        cout << ans << "\n";
    }
    return 0;
}
