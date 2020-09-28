#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int T, n, m, p, A[N], cnt[N];
int s, t, l, r, mx;

bool check(int x)
{
    int now = 1;
    for (int i = 0; i < n; i++)
        now = (now * (cnt[i + x] - i)) % p;
    return now != 0;
}
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    sort(A + 1, A + 1 + n);

    mx = A[n];
    for (int i = 1; i <= n; i++)
        A[i] = max(A[i] - mx + n, 0), cnt[A[i]]++;

    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];

    for (int i = n; i >= 1; i--)
        s = max(s, A[i] - (i - 1));

    if (!check(s))
    {
        printf("0\n");
        return 0;
    }
    t = A[n];

    for (int i = 0; i < n; i++)
        while (cnt[i + t] - i >= p)
            t--;

    printf("%d\n", t - s + 1);

    for (int i = s; i <= t; i++)
        printf("%d ", i + mx - n);
    return 0;
}
