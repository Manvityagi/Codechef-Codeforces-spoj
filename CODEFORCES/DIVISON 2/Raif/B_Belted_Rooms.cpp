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
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
LL n;
string s;

bool ordered(string s)
{
    int n = s.size();
    int l = 0, g = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            continue;
        if (s[i] == '>' && l >= 1)
            return false;
        if (s[i] == '<' && g >= 1)
            return false;

        if (s[i] == '>')
            g++;
        if (s[i] == '<')
            l++;
    }

    return true;
}

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
    while (t--){
        cin >> n;
        cin >> s;
        int cnt = 0;

        if (ordered(s)){
            cout << n << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            if (s[i] == '-' || s[(i + 1) % n] == '-') cnt++;

        cout << cnt << "\n";
    }
    return 0;
}
