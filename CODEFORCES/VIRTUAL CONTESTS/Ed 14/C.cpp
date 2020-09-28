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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> bf;
        deque<int> af;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '.')
                bf.push_back(s[i] - '0');
            else
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                for (int j = i + 1; j < n; j++)
                {
                    af.push_back(s[j] - '0');
                }
                break;
            }
        }
        while ((int)af.size() && af.back() == 0)
            af.pop_back();

        reverse(bf.begin(), bf.end());
        while ((int)bf.size() && bf.back() == 0)
            bf.pop_back();
        reverse(bf.begin(), bf.end());

        int exp = 0;
        while ((int)bf.size() == 0)
        {
            int p = af.front();
            af.pop_front();
            if (p)
                bf.push_back(p);
            exp--;
        }
        while ((int)bf.size() > 1)
        {
            int p = bf.back();
            bf.pop_back();
            af.push_front(p);
            exp++;
        }

        while ((int)af.size() && af.back() == 0)
            af.pop_back();

        for (auto i : bf)
            cout << i;
        if ((int)af.size())
        {
            cout << '.';
            while ((int)af.size())
                cout << af.front(), af.pop_front();
        }
        if (exp)
            cout << 'E' << exp;
    }
    return 0;
}
