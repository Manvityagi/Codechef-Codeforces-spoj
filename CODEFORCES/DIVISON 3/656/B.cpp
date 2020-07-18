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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
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
        LL n;
        cin >> n;

        vector<int> a(n * 2);
        vector<int> ans(n);
        unordered_set<int> st;
        for (auto &i : a)
        {
            cin >> i;
            if (st.find(i) == st.end())
            {
                ans.push_back(i);
            }
            st.insert(i);
        }

        for (auto &i : ans)
            cout << i << " ";

        cout << "\n";
    }
    return 0;
}
