#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int digitSum(int a)
{
    int sum = 0;
    while(a > 0)
    {
        sum += a%10;
        a = a/10;
    }

    return sum;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,arr[100];
cin >> n;

int ar1[100] = { 0 },ar0[100] = { 0 };


for(int i = 0; i < n; i++)
{
    cin >> arr[i];
    if(arr[i] == 0)
    {
         ar0[i]++;
    }
    else
    {
        ar1[i]++;   
    }    
}

    if(ar0[n-1] != ar1[n-1])
        {
            cout << 1 << endl;
            cout << arr << endl;
        }

    for(int i = 0; i < n; i++)
    {
        if( (ar0[i] != ar1[i]) && (ar0[n-1]-ar0[i] != ar1[n-1]-ar1[i]) )
        {
            int j;
            cout << 2 << endl;
            for(j = 0; j < i; j++)
            cout << arr[j] << " ";
            for(;j<n;j++)
            cout << arr[j] << " ";

        }
    }

getchar();
return 0;

}