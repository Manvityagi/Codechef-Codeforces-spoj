#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '.'){
                if(i+2 < n && j+2 < n){
                    //horizontal
                    if(grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2])
                    {
                        cout << grid[i][j];
                        return 0;
                    }
                    
                    //vertical`
                     if(grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+2][j])
                    {
                        cout << grid[i][j];
                        return 0;
                    }
                    
                    //diaogonal
                     if(grid[i][j] == grid[i+1][j+1] && grid[i][j] == grid[i+2][j+2])
                    {
                        cout << grid[i][j];
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "Ongoing";
}