#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    string s = "aeiou";
    for(int a = 5; a < k; a++)
    {
        if(a > 5) {
            s += s[(int)s.length() - 5];
        }
        int b = k/a;
        if(a*b == k && b >= 5)
        {
            for(int i = 0; i < b; ++i)
            {
                cout << s;
                s = s.substr(1) + s[0];
            }
            cout << endl;
            return 0; 
        }
    }

    cout << -1;

}

