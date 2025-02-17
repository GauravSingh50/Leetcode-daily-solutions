//  11-02-2024

class Solution {
public:
    int m,n;
    int t[71][71][71];

    int solve(vector<vector<int>>&grid ,int row, int c1,int c2)
    {
        if(row>=m)
            return 0;
        if(t[row][c1][c2] != -1)
            return t[row][c1][c2];
        
        int cherry=grid[row][c1];
        if(c1!=c2)
            cherry+=grid[row][c2];
        
        int ans=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int new_row=row+1;
                int new_c1=c1+i;
                int new_c2=c2+j;
                if(new_c1>=0 && new_c1 < n && new_c2 >= 0 && new_c2 <n)
                    ans=max(ans, solve(grid,new_row,new_c1,new_c2));
            }
        }
        return t[row][c1][c2]=cherry+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,n-1);
    }
};
