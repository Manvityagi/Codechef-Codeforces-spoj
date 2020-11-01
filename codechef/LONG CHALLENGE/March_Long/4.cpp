
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ppl pair<LL, LL>
#define MOD1 1000000007
#define MOD2 1000000009

void erast()
{
    int n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
        LL n, q;
        cin >> n >> q;

        vector<ppl> cord;
        LL y;
        cin >> y;
        cord.push_back({1, y});
        vector<pair<ppl, ppl>> line;
        for (int i = 1; i < n; i++)
        {
            LL y;
            cin >> y;
            cord.push_back({i + 1, y});
            line.push_back({cord[i - 1], cord[i]});
        }

        // for (auto l : line)
        // {
        //     cout << l.F.F << "," << l.F.S << "   ";
        //     cout << l.S.F << "," << l.S.S << endl;
        // }

        while (q--)
        {
            LL x1, x2, y;
            LL ans = 0;
            cin >> x1 >> x2 >> y;
            //x1,y to x2,y is the beam

            for (auto l : line)
            {
                LL sx = l.F.F, sy = l.F.S, ex = l.S.F, ey = l.S.S;

                //in range y
                if ((y >= sy && y <= ey) || (y <= sy && y >= ey))
                {
                    //out of range x
                    if (ex < x1 || sx > x2)
                        continue;

                    //except when the left endpoint of this segment is (x2,y) or its right endpoint is (x1,y)
                    if ((sx == x2 && sy == y) || (ex == x1 && ey == y))
                        continue;

                    ans++;
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
}
