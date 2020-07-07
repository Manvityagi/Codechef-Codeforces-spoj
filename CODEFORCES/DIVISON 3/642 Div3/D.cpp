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
#define pii pair<int, int>
const int MAX_N = 5e5 + 5;

class compare
{
public:
    bool operator()(pii const &a, pii const &b)
    {
        if ((a.S - a.F) == (b.S - b.F))
        {
            return a.F > b.F;
        }

        return ((a.S - a.F) < (b.S - b.F));
    }
};

void solve(int n)
{
    priority_queue<pii, vector<pii>, compare> pq;
    vector<int> zeros(n + 1, 0);
    int l = 1, r = n;
    pq.emplace(MP(1, n));
    int cnt = 1, ptr = 0;
    vector<int> done(n + 1, 0);
    while (!pq.empty())
    {
        ptr++;
        auto top = pq.top();
        pq.pop();
        int ind;
        l = top.F, r = top.S;
        int check = r - l + 1;
        if (check & 1)
        {
            ind = (l + r) / 2;
        }
        else
        {
            ind = (l + r - 1) / 2;
        }

        if (!done[ind])
        {
            zeros[ind] = cnt;
            cnt++;
            done[ind] = 1;
        }

        if (l <= ind - 1 && l >= 1 && l <= n && (ind - 1) >= 1 && (ind - 1) <= n)
        {
                pq.emplace(MP(l, ind - 1));
        }

        if (ind + 1 <= r && ind + 1 >= 1 && ind + 1 <= n && r >= 1 && r <= n)
        {
                pq.emplace(MP(ind + 1, r));
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << zeros[i] << " ";
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        solve(n);
        puts("");
    }

    return 0;
}
