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
        cin >> n >> m;
        string name, ip;
        unordered_map<string, string> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> ip;
            mp[ip] = name;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> name >> ip;
            cout << name << " " << ip << " #" << mp[ip] << "\n";
        }
    }
    return 0;
}
