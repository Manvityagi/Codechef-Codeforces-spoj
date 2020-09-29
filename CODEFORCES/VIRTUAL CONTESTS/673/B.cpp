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
        LL n, target;
        cin >> n >> target;
        vector<int> a(n);
        for (auto &i : a)
            cin >> i;
        unordered_map<int, int> mp;
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            int one = a[i], two = target - a[i];
            if (mp.find(two) != mp.end())
            {
                if (i != mp[two])
                {
                    if (color[mp[two]] != -1)
                    {
                        color[i] = !color[mp[two]];
                    }
                    else
                    {
                        color[i] = 0;
                        color[mp[two]] = 1;
                    }
                }
            }
            mp[a[i]] = i;
        }
        for (auto c : color)
        {
            cout << c << " ";
        }
        cout << "\n";
    }
    return 0;
}
