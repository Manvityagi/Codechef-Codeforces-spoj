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
#define loop(i, a, b) for (LL i = a; i < b; i++)
LL n, m;
LL movex[] = {0, 0, 1, -1};
LL movey[] = {1, -1, 0, 0};

signed main()
{
    static const LL _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<LL> a(n);
        unordered_map<int, int> mp;       //bitcount, minimum number
        unordered_map<int, int> bitcount; //number,bits in the number
        for (auto &i : a)
        {
            cin >> i;
            int bits = 0;
            LL temp = i;
            while (temp)
                temp >>= 1, bits++;
            mp[i] = bits;
            if (mp.find(bits) == mp.end())
                mp[bits] = i;
            else
                mp[bits] = i < mp[bits] ? i : mp[bits];
        }
        LL ans = 0;
        int l, r, b;
        for (auto i : a)
        {
            l = bitcount[i];

            for (auto p : mp)
            {
                r = p.F;
                b = p.S;
                LL res = i * ((1LL << r) - 1) - b * ((1LL << l) - 1);
                ans = max(res, ans);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
