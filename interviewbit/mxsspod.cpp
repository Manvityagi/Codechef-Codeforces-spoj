#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	vector<int> A = {8,6,3,1,12,4,3};
	vector<int> LSV,RSV;
stack< pair<int,int> > st; 
int n = A.size();

//filling LSV array
st.push(make_pair(A[0],0));
for(int i = 1; i < n-1; i++)
{
    if(st.empty())
    {
        LSV.push_back(0);   
    }
    else
    if(st.top().first >  A[i])
    {
        st.push( make_pair(A[i],i));
        LSV.push_back(st.top().second);   
    }
    else
    {
        //pop until u find a value greater A[i] or the stack empties
        while(!st.empty() && st.top().first >  A[i])
        {
            st.pop();
        }

        if(st.empty())
        LSV.push_back(0);
        else
        {
             LSV.push_back(st.top().second);   
        }
    }
}






//filling RSV array
st.push(make_pair(A[n-1],n-1));
for(int i = n-2; i >= 1; i--)
{
    if(st.empty())
    {
        RSV.push_back(0);   
    }
    else
    if(st.top().first >  A[i])
    {
        st.push( make_pair(A[i],i));
        RSV.push_back(st.top().second);   
    }
    else
    {
        //pop until u find a value greater A[i] or the stack empties
        while(!st.empty() && st.top().first >  A[i])
        {
            st.pop();
        }

        if(st.empty())
        RSV.push_back(0);
        else
        {
             RSV.push_back(st.top().second);   
        }
    }
}



int ans = INT_MIN;
for(int i = 0; i < LSV.size(); i++)
{
    if(LSV[i] * RSV[i] >= ans)
    {
        ans = LSV[i] * RSV[i];
    }
}

return ans % 1000000007 ;
	return 0;
}
