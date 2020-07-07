#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
const int MAX_N = 10123;
bitset<MAX_N> b[51];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x);
            b[i][x] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if ((b[i] & b[j]) == 0)
            {
                puts("impossible");
                return 0;
            }
        }
    }
    puts("possible");
}
