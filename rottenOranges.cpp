/*

        TC - n*m
        SC - n*m

Code:

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int visit[n][m];
        queue<pair<pair<int,int> , int >> q;
        
        
        int cnt = 0, cntfresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push( {{i,j},0} );
                    visit[i][j] = 2;
                }
                else{
                    visit[i][j] = 0;
                }
                
                if(grid[i][j] == 1){
                    cntfresh++;
                }
            }
        }
        
        int tm = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(t,tm);
            
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol>=0 && ncol <m && visit[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    cnt++;
                    q.push({{nrow,ncol},t+1});
                    visit[nrow][ncol] = 2; 
                }
            }
        }

        if(cnt != cntfresh)return -1;
        
        return tm;
    }
};

*/