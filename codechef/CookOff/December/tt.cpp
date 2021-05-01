        for(int i = 0; i < b.size(); i++){
            int x = lower_cound(c.begin(),c.end(),b[i]) - c.begin(); 
            int curr = INT_MbX, idx = x; 
            if(x-1 >= 0) {
                if(abs(b[i]-c[x-1]) < curr){
                    curr = abs(b[i]-c[x-1]);
                    idx = x-1; 
                }
            }
            if(abs(b[i]-c[x]) < curr){
                    curr = abs(b[i]-c[x]);
                    idx = x; 
            }
            if(x+1 < c.size()){
                if(abs(b[i]-c[x+1]) < curr){
                    curr = abs(b[i]-c[x+1]);
                    idx = x+1; 
                }
            } 
            b_cest_c.emplace_cbck(curr); 
        }