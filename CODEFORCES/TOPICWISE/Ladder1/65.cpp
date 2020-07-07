#include <bits/stdc++.h>
using namespace std;
int Ret, g[6][6], x[5], n, i, j;

int f(int a, int b)
{
    return g[x[a]][x[b]] + g[x[b]][x[a]];
}

int main()
{
    for (i = 0; i < 5; ++i)
        x[i] = i + 1;
    for (i = 1; i <= 5; ++i)
        for (j = 1; j <= 5; ++j)
            scanf("%d", &g[i][j]);
    do
    {
        Ret = max(Ret, f(0, 1) + f(1, 2) + 2 * f(2, 3) + 2 * f(3, 4));
    } while (next_permutation(x, x + 5));
    printf("%d", Ret);
}