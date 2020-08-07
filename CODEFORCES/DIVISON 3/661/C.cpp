#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first 
#define S second 
#define MP make_pair
#define LL long long
#define int LL
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] ={ 0, 0, 1, -1 };
int movey[] ={ 1, -1, 0, 0 };

int countUniquePairs(vector<int> nums, int target) {

    int count = 0;

    for (int i = 0;i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[j] == -1) continue;
            if (nums[i] + nums[j] == target) {
                nums[j] = -1;
                count++;
                break;
            }
        }
    }

    return count;
}


signed main()
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
        vector<int> w(n);
        for (auto &i : w) cin >> i;

        LL ans = 0;

        map<int, int> mp;
        for (int e : w) mp[e] ++;

        for (int s = 1; s <= 110; s++)
        {
            int cur = 0;
            map<int, int> mp2 = mp;
            for (auto e : mp2)
            {
                int req = s - e.F;
                if (req < 0) continue;

                if (req == e.F) {
                    cur += e.S/2;
                }
                else
                {
                    cur += min(mp2[req], e.S);
                    mp2.erase(req);
                }
            }
            ans = max(ans, cur);
        }

        cout <<ans<< "\n";
    }
    return 0;
}
