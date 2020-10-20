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
        string s;
        cin >> s;
        stack<char> st;

        int n = s.size();
        if(n==0){
            cout << 0 << "\n";
            continue;
        }
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (!st.empty() && s[i] == 'B' && st.top() == 'A')
                st.pop();
            else
                st.push(s[i]);
        }

        int ca = 0, cb = 0;

        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(c == 'A') ca++;
            else cb++;
        }

        int ans = ca + (cb%2);
        cout << ans << "\n";
    }
    return 0;
}
