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
    unordered_map<char, char> mp;
    while (t--)
    {
        int R = 0, P = 0, S = 0;
        string s;
        cin >> s;
        for (auto c : s)
        {
            if (c == 'R')
            {
                R++;
            }
            else if (c == 'P')
            {
                P++;
            }
            else
            {
                S++;
            }
        }

        char ans;
        int maxi = max(R, (max(P, S)));
        if (maxi == R)
        {
            ans = 'P';
        }
        else if (maxi == P)
        {
            ans = 'S';
        }
        else
        {
            ans = 'R';
        }

        for (int i = 0; i < n; i++)
            cout << ans;
        cout << "\n";
    }
    return 0;
}
