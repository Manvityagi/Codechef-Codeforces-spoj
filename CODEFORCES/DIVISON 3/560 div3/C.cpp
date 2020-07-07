#include <bits/stdc++.h>
using namespace std;
//_ _ _ _ _ _
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    char prev_ch = 0;
    string s_print;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == prev_ch)
        {
            ans++; //remove a[i]
        }
        else
        {
            s_print += s[i];
            if (prev_ch == 0)
            {
                prev_ch = a[i];
            }
            else
            {
                prev_ch = 0;
            }
        }
    }

    if(prev_ch){
        s_print.pop_back();
        ans++;
    }

    cout << ans << "\n";
    cout << s_print << "\n";
}
