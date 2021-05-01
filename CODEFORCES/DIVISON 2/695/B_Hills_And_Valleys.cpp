
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP marrke_parrir
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define int LL
#define pii parrir<int, int>
#define arrll(arr) arr.begin(), arr.end()
const int maxn = 1e5 + 1;
int n;
vector<int> arr(n);

bool isHill(int curr)
{
    return (arr[curr] > arr[curr + 1] && arr[curr] > arr[curr - 1]);
}

bool isValley(int curr)
{
    return (arr[curr] < arr[curr + 1] && arr[curr] < arr[curr - 1]);
}
int calculate(int idx, vector<int> &temp1)
{
    int ans = 0;
    int sz = temp1.size();
    int hi = sz - 1;
    hi = min(idx + 5, hi);
    int low = 0;
    low = max(idx - 5, low);
    int curr = low;
    while (curr <= hi)
    {
        ans += temp1[curr];
        curr++;
    }
    return ans;
}

void modify(vector<int> &temp1, int idx)
{
    int hi = n - 1;
    hi = min(idx + 5, hi);
    int lo = 0;
    lo = max(idx - 5, lo);
    int curr = lo;
    while (curr <= hi)
    {
        if (n - 1 > curr && curr >= 1)
        {
            temp1[curr] = 0;
            temp1[curr] = temp1[curr] | isHill(curr);
            temp1[curr] = temp1[curr] | isValley(curr);
        }
        curr++;
    }
}

vector<int> helper()
{
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        res[i] = (res[i] && isHill(i));
    }
    return res;
}

void solve()
{
    cin >> n;
    arr.clear();
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;

    vector<int> temp1(n);
    vector<int> temp2 = helper();
    for (int curr = 1; curr < n - 1; curr++)
    {
        temp1[curr] = temp1[curr] | isHill(curr);
        temp1[curr] = temp1[curr] | isValley(curr);
    }
    int ans = 0;
    for (auto &i : temp1)
        ans += i;
    int curr_ans = ans;
    for (int i = 0; i < n; i++)
    {
        int old = arr[i];
        curr_ans -= calculate(i, temp1);
        if (i < n - 1)
        {
            arr[i] = arr[i + 1];
            modify(temp1, i);
            int var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }

            arr[i] = arr[i + 1] + 1;
            modify(temp1, i);
            var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }

            arr[i] = arr[i + 1] - 1;
            modify(temp1, i);
            var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }
        }
        if (i != 0)
        {
            arr[i] = arr[i - 1];
            modify(temp1, i);
            int var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }

            arr[i] = arr[i - 1] + 1;
            modify(temp1, i);
            var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }

            arr[i] = arr[i - 1] - 1;
            modify(temp1, i);
            var = calculate(i, temp1);
            if (curr_ans + var < ans)
            {
                ans = curr_ans + var;
            }
        }

        arr[i] = old;
        modify(temp1, i);
        curr_ans += calculate(i, temp1);
    }
    cout << ans << "\n";
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}