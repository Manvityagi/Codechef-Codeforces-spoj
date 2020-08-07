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
int movex[] ={ 0, 0, 1, -1 };
int movey[] ={ 1, -1, 0, 0 };

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
        cin >> n;
        vector<int> a(n), ans(n);
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ch;
            a[i] = ch - '0';
        }
        stack<int> zero, one;
        int seq = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (one.empty()) {
                    seq++;
                    ans[i] = seq;
                    zero.emplace(seq);
                }
                else {
                    ans[i] = one.top();
                    one.pop();
                }
            }
            else {
                if (one.empty()) {
                    seq++;
                    ans[i] = seq;
                    one.emplace(seq);
                }
                else {
                    ans[i] = zero.top();
                    zero.pop();
                }
            }
        }
        cout << seq << "\n";
        for (auto &i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}