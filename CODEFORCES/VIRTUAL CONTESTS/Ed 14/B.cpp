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

unordered_map<char, char> mp;
int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;

    vector<pair<char, char>> v = {{'A', 'A'},
                                  {'b', 'd'},
                                  {'H', 'H'},
                                  {'I', 'I'},
                                  {'M', 'M'},
                                  {'O', 'O'},
                                  {'o', 'o'},
                                  {'p', 'q'},
                                  {'T', 'T'},
                                  {'U', 'U'},
                                  {'V', 'V'},
                                  {'v', 'v'},
                                  {'W', 'W'},
                                  {'w', 'w'},
                                  {'X', 'X'},
                                  {'x', 'x'},
                                  {'Y', 'Y'}};
    map<char, char> mp;
    for (auto i : v)
    {
        mp[i.first] = i.second;
        mp[i.second] = i.first;
    }
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int m1 = 0, m2 = n - 1;
        while (m1 <= m2)
        {
            if (mp[s[m1]] != s[m2])
            {
                cout << "NIE";
                return 0;
            }
            m1++, m2--;
        }

        cout << "TAK";
    }
    return 0;
}
