class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isValid(int x,int y,int n,int m)
    {
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    }
    void DFS(int i,int j,vector<vector<int>>& grid,int &cnt)
    {
        grid[i][j]=0;
        cnt++;
        for(int k=0;k<4;k++)
        {
            int X=i+dx[k],Y=j+dy[k],n=grid.size(),m=grid[i].size();
            if(isValid(X,Y,n,m) && grid[X][Y]==1)
            {
                DFS(X,Y,grid,cnt);
            }
        }
    }
    void BFS(vector<vector<int>> & grid, int r, int c,int & cnt)
    {
        queue<pair<int,int>> q;
        grid[r][c]=0;
        q.push({r,c});

        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            cnt++;
            for(int k=0;k<4;k++)
            {
                int X=i+dx[k],Y=j+dy[k],n=grid.size(),m=grid[i].size();
                if(isValid(X,Y,n,m) && grid[X][Y]==1)
                {
                    grid[X][Y]=0;
                    q.push({X,Y});
                }
            }

        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;    
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int tmp=0;
                    BFS(grid,i,j,tmp);
                    ans=max(ans,tmp);
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};
