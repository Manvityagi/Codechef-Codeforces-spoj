#include <bits/stdc++.h>
#define fo(i, m, n) for (ll i = m; i < n; i++)
#define pii pair<ll, ll>
#define gt(n) scanf("%d", &n)
#define ii pair<ll, ll>
#define ll long long

using namespace std;
ll n, m;
char arr[100][100];

main()
{
    cin >> n;
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    string s;
    cin >> s;

    ll E = 0, W = 0, N = 0, S = 0;

    if (ex < sx)
    {
        E = sx - ex;
    }
    if (ex > sx)
    {
        W = ex - sx;
    }
    if (ey < sy)
    {
        S = sy - ey;
    }
    if (ey > sy)
    {
        N = ey - sy;
    }

    ll time = 0;
    for (int i = 0; i < n, (E != 0 || W != 0 || N != 0 || S != 0); i++)
    {
        if (s[i] == 'N')
        {
            N--;
        }
        else if (s[i] == 'S')
        {
            S--;
        }
        else if (s[i] == 'E')
        {
            E--;
        }
        else if (s[i] == 'W')
        {
            W--;
        }
        time++;
    }

    if (E == 0 && S == 0 && N == 0 && W == 0)
        cout << time;
    else
    {
        cout << -1 ;
    }

    return 0;
}