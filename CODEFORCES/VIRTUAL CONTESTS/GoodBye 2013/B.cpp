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
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;

        string ans = "";
        char dir = 'R';
        while (1)
        {
            bool done = 1;
            if (dir == 'R')
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i] != 0)
                        done = 0;
                    if (a[i] > 0)
                    {
                        if (ans.size() && ans.back() == 'P')
                        {
                            if (i != n - 1)
                            {
                                ans += 'R';
                            }
                        }
                        else
                        {
                            if (i != n - 1)
                                ans += "PR";
                            else
                                ans += "P";
                            a[i]--;
                        }
                    }
                    else if (i != n - 1)
                    {
                        ans += "R";
                    }
                }
                dir = 'L';
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] != 0)
                        done = 0;

                    if (a[i] > 0)
                    {
                        if (ans.size() && ans.back() == 'P')
                        {
                            if (i != 0)
                            {
                                ans += 'L';
                            }
                        }
                        else
                        {
                            if (i != 0)
                                ans += "PL";
                            else
                                ans += "P";
                            a[i]--;
                        }
                    }
                    else if (i != 0)
                    {
                        ans += "L";
                    }
                }
                dir = 'R';
            }
            if (done)
                break;
        }
        cout << ans;
    }
    return 0;
}
