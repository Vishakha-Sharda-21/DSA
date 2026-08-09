class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), fresh = 0, time = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(g[i][j]==2) q.push({i,j});
                else if(g[i][j]==1) fresh++;

        int d[5]={1,0,-1,0,1};

        while(!q.empty() && fresh){
            int sz=q.size();
            while(sz--){
                auto [r,c]=q.front(); q.pop();

                for(int k=0;k<4;k++){
                    int x=r+d[k], y=c+d[k+1];

                    if(x>=0&&x<m&&y>=0&&y<n&&g[x][y]==1){
                        g[x][y]=2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
            time++;
        }

        return fresh ? -1 : time;
    }
};
