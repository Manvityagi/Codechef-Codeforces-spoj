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
const long MOD = 998244353;
const long deno = 748683265;

unordered_set<char> operators;

vector<vector<LL>> solve(string &xpr, vector<vector<LL>> &base)
{
    // cout << " xpr " << xpr << "\n";
    if (xpr.size() <= 1)
    {
        return base;
    }

    if (xpr[0] == '(')
    {
        xpr = xpr.substr(1, xpr.size() - 2);
    }

    LL opidx = -1, open = 0, close = 0;
    char op = ' ';

    for (int i = 0; i < xpr.size(); i++)
    {
        if (operators.find(xpr[i]) != operators.end() && open == close)
        {
            op = xpr[i];
            opidx = i;
            break;
        }
        else if (xpr[i] == '(')
        {
            open++;
        }
        else if (xpr[i] == ')')
        {
            close++;
        }
    }

    string leftxpr = xpr.substr(0, opidx);
    string rightxpr = xpr.substr(opidx + 1, xpr.size() - opidx - 1);
    vector<vector<LL>> leftans = solve(leftxpr, base);
    vector<vector<LL>> rightans = solve(rightxpr, base);

    vector<vector<LL>> ans(4, vector<LL>(2));

    if (op == '^')
    {
        // for 0
        ans[0][1] = leftans[0][1] + rightans[0][1];
        ans[0][0] = (leftans[0][0] * rightans[0][0]) +
                    (leftans[1][0] * rightans[1][0]) +
                    (leftans[2][0] * rightans[2][0]) +
                    (leftans[3][0] * rightans[3][0]);

        // for 1
        ans[1][1] = leftans[1][1] + rightans[1][1];
        ans[1][0] = (leftans[0][0] * rightans[1][0]) +
                    (leftans[1][0] * rightans[0][0]) +
                    (leftans[2][0] * rightans[3][0]) +
                    (leftans[3][0] * rightans[2][0]);

        // for a
        ans[2][1] = leftans[2][1] + rightans[2][1];
        ans[2][0] = (leftans[2][0] * rightans[0][0]) +
                    (leftans[0][0] * rightans[2][0]) +
                    (leftans[1][0] * rightans[3][0]) +
                    (leftans[3][0] * rightans[1][0]);

        // for A
        ans[3][1] = leftans[3][1] + rightans[3][1];
        ans[3][0] = (leftans[3][0] * rightans[0][0]) +
                    (leftans[0][0] * rightans[3][0]) +
                    (leftans[1][0] * rightans[2][0]) +
                    (leftans[2][0] * rightans[1][0]);
    }
    else if (op == '&')
    {

        // for 0
        ans[0][1] = leftans[0][1] + rightans[0][1];
        ans[0][0] = (leftans[0][0] * rightans[0][0]) +
                    (leftans[0][0] * rightans[1][0]) +
                    (leftans[0][0] * rightans[2][0]) +
                    (leftans[0][0] * rightans[3][0]) +
                    (leftans[1][0] * rightans[0][0]) +
                    (leftans[2][0] * rightans[0][0]) +
                    (leftans[2][0] * rightans[3][0]) +
                    (leftans[3][0] * rightans[0][0]) +
                    (leftans[3][0] * rightans[2][0]);

        //for 1
        ans[1][1] = leftans[1][1] + rightans[1][1];
        ans[1][0] = leftans[1][0] * rightans[1][0];

        // for a
        ans[2][1] = leftans[2][1] + rightans[2][1];
        ans[2][0] = (leftans[2][0] * rightans[2][0]) +
                    (leftans[1][0] * rightans[2][0]) +
                    (leftans[2][0] * rightans[1][0]);
        // for A
        ans[3][1] = leftans[1][1] + rightans[1][1];
        ans[3][0] = (leftans[3][0] * rightans[3][0]) +
                    (leftans[1][0] * rightans[3][0]) +
                    (leftans[3][0] * rightans[1][0]);
    }
    else if (op == '|')
    {
        // for 0

        ans[0][1] = leftans[0][1] + rightans[0][1];
        ans[0][0] = leftans[0][0] * rightans[0][0];

        //for 1
        ans[1][1] = leftans[1][1] + rightans[1][1];
        ans[1][0] = (leftans[1][0] * rightans[0][0]) +
                    (leftans[1][0] * rightans[1][0]) +
                    (leftans[1][0] * rightans[2][0]) +
                    (leftans[1][0] * rightans[3][0]) +
                    (leftans[0][0] * rightans[1][0]) +
                    (leftans[2][0] * rightans[1][0]) +
                    (leftans[2][0] * rightans[3][0]) +
                    (leftans[3][0] * rightans[1][0]) +
                    (leftans[3][0] * rightans[2][0]);

        // for a
        ans[2][1] = leftans[2][1] + rightans[2][1];
        ans[2][0] = (leftans[2][0] * rightans[0][0]) +
                    (leftans[2][0] * rightans[2][0]) +
                    (leftans[0][0] * rightans[2][0]);

        // for A
        ans[3][1] = leftans[3][1] + rightans[3][1];
        ans[3][0] = (leftans[3][0] * rightans[0][0]) +
                    (leftans[3][0] * rightans[3][0]) +
                    (leftans[0][0] * rightans[3][0]);
    }

    ans[0][0] %= MOD;
    ans[1][0] %= MOD;
    ans[2][0] %= MOD;
    ans[3][0] %= MOD;

    return ans;
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
    operators.insert('&');
    operators.insert('|');
    operators.insert('^');

    while (t--)
    {
        string xpr;
        cin >> xpr;

        vector<vector<LL>> base(4, vector<LL>(2, 1));

        vector<vector<LL>> ans = solve(xpr, base);

        LL length = ans[0][1];
        cout << length << endl;
        LL mul = 748683265;
        for (LL i = 1; i < length; i++)
        {
            mul = (mul * deno) % MOD;
        }

        cout << (ans[0][0]) << " ";
        cout << (ans[1][0]) << " ";
        cout << (ans[2][0]) << " ";
        cout << (ans[3][0]) << "\n";

        cout << mul << endl;

        cout << (ans[0][0] * mul) % MOD << " ";
        cout << (ans[1][0] * mul) % MOD << " ";
        cout << (ans[2][0] * mul) % MOD << " ";
        cout << (ans[3][0] * mul) % MOD << "\n";
    }
    return 0;
}
