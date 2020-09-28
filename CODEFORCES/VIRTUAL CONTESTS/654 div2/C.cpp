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
    int t;
    cin >> t;
    while (t--)
    {
        LL v, c, n, m;
        cin >> v >> c >> n >> m;

        if (v + c < n + m)
        {
            cout << "No\n";
            continue;
        }

        if ((v == 0 || c == 0) && (m != 0))
        {
            cout << "No\n";
            continue;
        }

        //v,c me se jo chota hai wo bada hona chahiye m se

        if (v < c)
        {
            if (m > v)
            {
                cout << "No\n";
                continue;
            }
        }
        else
        {
            if (m > c)
            {
                cout << "No\n";
                continue;
            }
        }

        cout << "Yes\n";
    }
    return 0;
}
