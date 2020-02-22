#include <bits/stdc++.h>
#define moduli 1000000007
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return

using namespace std;

int dayofweek(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 +
            y / 400 + t[m - 1] + d) %
           7;
}

void solve()
{

    int m1, y1, m2, y2;

    cin >> m1 >> y1 >> m2 >> y2;

    if (m1 > 2)
        y1++;

    if (m2 < 2)
        y2--;

    int temp1 = y1, temp2 = y2;

    if (y1 % 4 != 0)
        y1 += (4 - y1 % 4);

    if (y2 % 4 != 0)
        y2 -= y2 % 4;

    //cout<<y1<<" "<<y2;

    if (y2 - y1 < 2800)
    {

        int ctr = 0;

        for (int i = temp1; i <= temp2; i++)
        {

            int ans = dayofweek(1, 2, i);

            if (ans == 6)
                ctr++;

            else if (ans == 0)
            {

                if (i % 4 != 0)
                    ctr++;
            }
        }

        cout << ctr << endl;
        R;
    }

    else
    {

        int ctr = 0;

        int interval = (y2 - y1 + 1) / 2800;

        ctr = interval * 707;

        //cout<<ctr<<endl;

        for (int i = temp1; i < y1; i++)
        {
            //cout<<i<<endl;
            if (dayofweek(1, 2, i) == 6)
                ctr++;

            if (dayofweek(1, 2, i) == 0)
            {
                if (i % 4 != 0)
                    ctr++;
            }
        }
        // cout<<ctr<<endl;
        int mod = (y2 - y1 + 1) % 2800;
        int sol = y2 - mod;

        for (int i = y2; i > sol; i--)
        { //cout<<i<<endl;
            if (dayofweek(1, 2, i) == 6)
                ctr++;

            if (dayofweek(1, 2, i) == 0)
            {

                if (i % 4 != 0)
                    ctr++;
            }
        }
        // cout<<ctr<<endl;

        for (int i = y2 + 1; i <= temp2; i++)
        { // cout<<i<<endl;
            if (dayofweek(1, 2, i) == 6)
                ctr++;

            if (dayofweek(1, 2, i) == 0)
            {

                if (i % 4 != 0)
                    ctr++;
            }
        }

        cout << ctr << endl;
        R;
    }
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}