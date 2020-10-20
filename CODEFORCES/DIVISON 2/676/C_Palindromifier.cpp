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
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
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
        if (n >= 3)
        {
            cout << "3\n";
            cout << "L " << n - 1 << "\n";
            cout << "R " << n - 1 << "\n";
            cout << "R " << (2 * n - 1) << "\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
