#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ppi pair<int, int>
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> seq(n + 1);
    bool possible = true;
   
    
    int firstNotSame = -1; //kth position se peeche jaate waqt
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
  
         int same = seq[k];
		 //cout << same << "\n";
      
        if (i > k && seq[i] != same)
        {
            possible = false;
        }
    }

    if (!possible)
    {
        cout << -1;
        return 0;
    }

  

int i;
for(i=k;seq[--i]==seq[k];);
	cout<<i;
    // cout << firstNotSame;
}