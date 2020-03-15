#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL count_one(int n)
{
    LL count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
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
    scanf("%d", &t);

    while (t--)
    {
        LL n, q, evenbits = 0, oddbits = 0;
        scanf("%ld%ld", &n, &q);
        vector<LL> vec(n);

        for (int i = 0; i < n; i++)
        {
            scanf("%ld", &vec[i]);
            if (count_one(vec[i]) & 1)
                oddbits++;
            else
                evenbits++;
        }

        for (int i = 0; i < q; i++)
        {
            LL p;
            scanf("%ld", &p);

            if (p & 1)
            {
                printf("%ld %ld \n", evenbits, oddbits);
            }
            else
            {
                printf("%ld %ld \n", oddbits, evenbits);
            }

            // printf("%ld %ld \n", e, o);
        }
    }
    return 0;
}
