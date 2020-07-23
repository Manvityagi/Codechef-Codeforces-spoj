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
#define loop(i, a, b) for (LL i = a; i < b; i++)
LL n, p;
LL movex[] = {0, 0, 1, -1};
LL movey[] = {1, -1, 0, 0};
vector<LL> arr;
vector<LL> tree;
LL mini = 0, maxi = 0;

void build(LL node = 1, LL start = mini, LL end = maxi + n)
{
    if (start == end)
    {
        LL choices = upper_bound(arr.begin(), arr.end(), start) - arr.begin();
        //choices - i
        //hmmm, i kaise pata chalega yaha
        tree[node] = choices;
        return;
    }
    LL mid = start + end >> 1;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] * tree[2 * node + 1];
}

//l,r for query and start,end for tree
LL query(LL l, LL r, int node = 1, int start = mini, int end = maxi + n)
{
    //no overlap
    if (r < start || l > end)
        return 1;

    //complete overlap
    if (start >= l && end <= r)
        return tree[node];

    int mid = start + end >> 1;

    LL left = query(l, r, 2 * node, start, mid);
    LL right = query(l, r, 2 * node + 1, mid + 1, end);

    return left * right;
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n >> p;
    arr.resize(n);
    tree.resize(4 * n);
    for (auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    LL mini = arr[0], maxi = arr[n - 1];

    vector<LL> res;
    LL ans = 0;

    for (LL x = mini; x <= maxi; x++)
    {
        build();
    }

    for (LL x = mini; x <= maxi; x++)
    {
        LL xx = x;
        //permutation ka size to n hi hoga
        LL totalcount = 1;

        //query will return product of choices for x,x+1,x+2...x+n
        //ye logn me chalega, to overall time complexity nlogn hi jayegi --- yeahhhhh!!!!
        totalcount = query(x, x + n);

        //x to x+n ke liye choices calculate kar raha hai ye loop
        // for (LL i = 0; i < n; i++)
        // {
        //     LL choices = upper_bound(arr.begin(), arr.end(), xx) - arr.begin();
        //     choices = choices - i;
        //     if (choices % p == 0)
        //     {
        //         totalcount = 0;
        //         break;
        //     }
        //     xx++;
        // }
        if (totalcount % p != 0)
        {
            res.push_back(x);
            ans++;
        }
    }
    cout << ans << "\n";
    for (auto &a : res)
        cout << a << " ";
    return 0;
}