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
const int MAX_N = 10001;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	string s;
        vector<int> ans;
    	cin >> s;
        // size_t size = sizeof(a) / sizeof(a[0]);
        int size = s.size();
        // cout << "si " << size << "\n";
        for(int i = 0; i < size; i++){
            int num = (s[i]-'0');
            if(num){
                  ans.push_back(num * pow(10,size-i-1));
            }
           
        }

        cout << ans.size() << "\n";
        for(auto a : ans)
        {
            cout << a << " ";
        }

        cout << "\n";
    }

    return 0;
}
