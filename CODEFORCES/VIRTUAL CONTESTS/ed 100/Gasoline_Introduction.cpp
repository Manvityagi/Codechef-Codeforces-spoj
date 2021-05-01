class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& food) {
        int n = st.size(); 
        int st0=0,st1=0,food0=0,food1=0;
        
        for(auto &i : st){
            if(i == 0){
                st0++;
            } else{
                st1++;
            }
        }
        
        
        for(auto &i : food){
            if(i == 0){
                food0++; 
            }else{
                food1++;
            }
        }
        
        int j = 0, ans = 0; //food  
        
        for(int i = 0; i < st.size(); i++){
            if(st[i] == food[j]){
                j++; 
                if(st[i]){
                    st0--;
                    food0--; 
                } else {
                    st1--;
                    food1--;
                }
            } else {
                if((st[i] == 0 && food0 == 0) || (st[i] == 1 && food1 == 0) || (food[j] == 0 && st0 == 0) || (food[j] == 1 && st1 == 0)){
                    ans = st.size()-i+1;
                    break; 
                } else {
                    st.emplace_back(st[i]);
                }
            }
        }
        
        return ans; 
    }
};