#include <bits/stdc++.h>
using namespace std;

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

int a;

cin >> a;
int sumD = digitSum(a);

if(a % 4 == 0)
return a;

int qu = a/4;
int nexMul = (qu+1)*4;
int diff = nexMul - sumD;

return a + diff;

}