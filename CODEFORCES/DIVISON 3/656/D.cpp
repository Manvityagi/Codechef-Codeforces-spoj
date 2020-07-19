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
vector<unordered_map<char, int>> mp;
string s;

int countx(char x, int st, int end)
{
    int len = end - st + 1;
    if (!st)
        return len - mp[end][x];

    int cntx = mp[end][x] - mp[st - 1][x];
    return len - cntx;
}

int xgood(char x, int st, int end)
{
    if (st > end)
        return INT_MAX;

    int len = end - st + 1;
    if (len == 1)
    {
        return s[st] != x;
    }

    int mid = st + end >> 1;

    //convert [st,mid] to x and [mid+1,end] to x+1-good
    int ans1 = countx(x, st, mid) + xgood(x + 1, mid + 1, end);

    //convert [mid+1,end] to x and [st,mid] to x+1-good
    int ans2 = xgood(x + 1, st, mid) + countx(x, mid + 1, end);

    return min(ans1, ans2);
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
    cin >> t;
    while (t--)
    {
        mp.clear();
        cin >> n;
        cin >> s;
        mp.resize(n);
        mp[0][s[0]]++;
        for (int i = 1; i < n; i++)
        {
            mp[i] = mp[i - 1];
            mp[i][s[i]]++;
        }
        cout << xgood('a', 0, n - 1) << "\n";
    }
    return 0;
}