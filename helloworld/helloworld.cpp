#include<bits/stdc++.h>
#define p_pii_pii pair< pair<int,int> , pair<int,int> >
#define pii pair<int,int>
using namespace std;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

   struct Compare {
       bool operator() (const p_pii_pii &a,
                        const p_pii_pii &b)
    {
        return (a.first.first + a.second.first) > (b.first.first + b.second.first);
    }
     };

int main() {
    int k = 3;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,5};
        vector<vector<int>> ans;     
        //hashmap to avoid duplicacy in minpq
        unordered_map< pii, int, hash_pair> map;
        
        if(nums1.size() == 0 || nums2.size() == 0)
            return 0;
        
        priority_queue< p_pii_pii,vector<p_pii_pii>,Compare> minpq;
        
        auto entry1 = make_pair(nums1[0],0), entry2 = make_pair(nums1[0],0);
        auto newEntry = make_pair(entry1,entry2); 
        minpq.push(newEntry);   
        int index = 0;
        
        while(!minpq.empty() && ans.size() < k)
        {
            auto heaptop = minpq.top();
            minpq.pop();
            
             auto newIndexPair = make_pair(heaptop.first.second,heaptop.second.second);
             map[newIndexPair]++;
            
            //pushing into ans heaptops values of nums1, nums2
            vector<int> subans;
            subans.push_back(heaptop.first.first);
            subans.push_back(heaptop.second.first);
            ans.push_back(subans);
            
            int index1 = heaptop.first.second + 1;
            int index2 = heaptop.second.second + 1;
            
            
            if(ans.size() < k)
            {
                if(index1 < nums1.size())
                {
                    auto arr1next = make_pair(nums1[index1],index1);
                    auto newEntry = make_pair(arr1next,
                                            make_pair(heaptop.second.first,heaptop.second.second)
                                             );              
                    
                   auto newEntryIndex = make_pair(newEntry.first.second, newEntry.second.second);
                   if(map[newEntryIndex] <= 0)
                     minpq.push(newEntry);
                
                }
                
                if(index2 < nums2.size())
                {
                  auto arr2next = make_pair(nums2[index2],index2);  
                  auto newEntry = make_pair(make_pair(heaptop.first.first,heaptop.first.second),arr2next);
                    
                   auto newEntryIndex = make_pair(newEntry.first.second, newEntry.second.second);
                   if(map[newEntryIndex] <= 0)
                     minpq.push(newEntry);
                }
               
            }
        }
        for(int i = 0; i < ans.size(); i++)
        {
            for(int j = 0; j < 2; j++)
            cout << ans[i][j] << " ";

            cout << endl;
        }
            
        return 0;
      }
