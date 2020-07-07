#include <bits/stdc++.h>
using namespace std;
int MAX_N = 2 * 1e5;
#define LL long long
#define PB push_back
void test_case()
{
    LL A, B, M;
    scanf("%lld%lld%lld", &A, &B, &M);
    if (A == B)
    {
        printf("1 %lld\n", A);
        return;
    }

    for (int n = 2; n <= 50; ++n)
    {
        LL already = (A + 1) << (n - 2);
        if (already > B)
            break;

        //bcz r1,r2....rn tak saari values hum already at least 1 maan chuke hai to ab it will be in range (0,m-1)

        LL remaining = B - already;
        vector<LL> answer{A};
        // answer.PB(A);
        LL presum = A;
        for (int i = 2; i <= n; i++)
        {
            LL p_two = 1LL << max(0,(n - i - 1));
            LL times = min(remaining / p_two, M - 1);
			remaining -= times*p_two;
            LL newval = presum + times + 1;
            presum += newval;
            answer.PB(newval);
        }

        if (remaining == 0)
        {
            printf("%d ", n);
            for (auto x : answer)
            {
                printf(" %lld", x);
            }
            puts("");
            return;
        }
    }

    puts("-1");
}

int main()
{
    LL q;
    scanf("%lld", &q);

    while (q--)
    {
        test_case();
    }
}
