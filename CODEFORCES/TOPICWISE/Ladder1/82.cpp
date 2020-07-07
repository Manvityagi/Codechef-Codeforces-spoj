#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
    for(int j=i+1;j<=n;j++)
    {
     double c=sqrt(i*i+j*j);
     if(c==int(c)&&c<=n&&c>=j) cnt++;
    }
    }
    cout<<cnt<<endl;
}