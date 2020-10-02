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
    vector<int> dx = {0, 1, -1};
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n);
        for (auto &i : a)
            cin >> i;
        int ans = INT_MAX;
        int currans = 0;
        for (int i = 0; i < 3; i++)
        {

            int a1 = a[0] + dx[i];
            for (int j = 0; j < 3; j++)
            {
                currans = 0;
                currans += (abs(dx[i]) + abs(dx[j]));
                int a2 = a[1] + dx[j];
                // cout << "intital " << a1 << " " << a2 << "\n";
                int cd = a2 - a1;
                for (int k = 2; k < n; k++)
                {
                    int ak = a1 + (k)*cd;
                    // cout << k << " " << ak << "\n";
                    if (abs(a[k] - ak) > 1)
                    {
                        currans = INT_MAX;
                        break;
                    }
                    if (currans != INT_MAX && abs(a[k] - ak))
                        currans++;
                }
                 ans = min(ans, currans);
            }
            // cout << "currans " << i << " " << currans << "\n";
          
        }

        int fans = ans == INT_MAX ? -1 : ans;
        cout << fans;
    }
    return 0;
}
