
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ppl pair<LL, LL>

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int t, s;
    cin >> t >> s;
    while (t--)
    {
        LL n;
        cin >> n;
        bool possible = true;
        unordered_map<LL, LL> mp;
        mp.clear();
        vector<LL> chef(n), frnd(n);
        for (int i = 0; i < n; i++)
            cin >> chef[i];
        for (int i = 0; i < n; i++)
            cin >> frnd[i];

        sort(chef.begin(), chef.end());
        sort(frnd.begin(), frnd.end());

        for (int i = 0; i < n; i++)
        {
            if (frnd[i] <= chef[i])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            mp[chef[0]]++;
            mp[frnd[0]]++;
            for (int i = 1; i < 2 * n; i++)
            {
                //if chef turn (if i is odd)
                if (i & 1)
                {
                    if (mp.find(chef[i/2]) == mp.end())
                    {
                        possible = false;
                        break;
                    }

                    mp[chef[i/2]]++;
                }
                else //if frnds turn
                {
                    mp[frnd[(i-1)/2]]++;
                }
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
