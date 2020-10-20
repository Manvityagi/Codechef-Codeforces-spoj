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
        LL n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
        {
            cin >> i
        }
        vector<int> res = a;
        sort(res.begin(), res.end());

        if (res == a)
        {
            cout << 0 << "\n";
            continue;
        }

        for (int curr = 1; curr <= n; curr++)
        {
            auto pos = find(a.begin(), a.end(), curr) - a.begin();
            //ab pos se n tak waale ko pehle likhna hai
            int cuts = 0;
            if (pos == n - 1)
                cuts = curr;
            else
                cuts = curr + 1;
            cout << cuts << " ";
            //cuts in sorted part
            for (int c = 1; c < curr; c++)
                cout << 1 << " ";
            //next cut after pos
            cout << pos - curr + 1<< " ";
            //last cut
            if (n-pos-1 > 0)
                cout << n - pos - 1;

            vector<int> temp;
            
            a = temp;
        }
    }
    return 0;
}
