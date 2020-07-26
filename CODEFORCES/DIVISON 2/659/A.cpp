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
        LL n;
        cin >> n;
        vector<LL> a(n);
        for (auto &i : a)
            cin >> i;
        vector<string> ans(n + 1);
        string beg;
        for (int i = 0; i < 100; i++)
            beg += 'a';

        for (int i = 1; i <= n; i++)
        {
            ans[i] = ans[i - 1];
            char curr = a[i - 1] != 0 ? ans[i][a[i - 1] - 1] : ans[i][0]; //do soemthing else when a[i-1] = 0
            char nex = curr == 'z' ? 'a' : curr + 1;
            ans[i][a[i - 1]] = nex;
        }

        for (auto s : ans)
            cout << s << "\n";
    }
    return 0;
}
