#include <iostream>
#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli sum(lli arr[], int n)
{
    
    lli sans = 0;
    for(int i = 0; i < n; i++)
        sans += arr[i];
        
        return sans;
}

int main() {
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n; 
	    cin >> n;
	    lli arr[100000];
	    for(int i = 0; i < n; i++)
	    cin >> arr[i];
	    
	    sort(arr,arr+n);
	    
	    lli osum = sum(arr,n);
	    // cout << "osum: " << osum << endl;
	    float mean = osum/(n*1.0);
	    
	    // cout << "mean: " << mean << endl;
	    float ans = osum - mean*(n-1);
	    
	    
	    
	      if (binary_search(arr, arr + n, ans))
	       cout << ans << "\n";
	      else
	      cout << "Impossible" << "\n";

        //   cout << endl << "ans: " << ans << endl; 
	}
	
	getchar();
	return 0;
}
