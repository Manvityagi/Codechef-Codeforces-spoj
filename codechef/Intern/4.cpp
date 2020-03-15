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

int max(LL a, LL b)
{
    return (a > b) ? a : b;
}

int knapSack(LL W, vector<LL> weight, vector<LL> nut, int X, int Y)
{
    int n = weight.size();
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
            {
                K[i][w] = max(max(nut[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]), 
                              max(X*nut[i - 1] + K[i - 1][w - weight[i - 1]], Y*nut[i - 1] + K[i - 1][w - weight[i - 1]])
                              );
            }
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
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
        LL N, W, X, Y;
        cin >> N >> W >> X >> Y;
        vector<LL> weight(N), nut(N);
        for (int i = 0; i < N; i++)
            cin >> weight[i];

        for (int i = 0; i < N; i++)
            cin >> nut[i];

        cout << knapSack(W, weight, nut, X, Y);
    }
    return 0;
}
