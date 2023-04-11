// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

//  

// 示例 1：

// 输入：grid = {
//   {'1','1','1','1','0'},
//   {'1','1','0','1','0'},
//   {'1','1','0','0','0'},
//   {'0','0','0','0','0'}
// }
// 输出：1
// 示例 2：

// 输入：grid = {
//   {'1','1','0','0','0'},
//   {'1','1','0','0','0'},
//   {'0','0','1','0','0'},
//   {'0','0','0','1','1'}
// }
// 输出：3
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid,int row,int colmn){
        int rows=grid.size(),colmns=grid[0].size();
        grid[row][colmn]='0';
        if (row-1>=0&&grid[row-1][colmn]=='1')
        {
            dfs(grid,row-1,colmn);
        }
        if (row+1<rows&&grid[row+1][colmn]=='1')
        {
            dfs(grid,row+1,colmn);
        }
        if (colmn-1>=0&&grid[row][colmn-1]=='1')
        {
            dfs(grid,row,colmn-1);
        }
        if (colmn+1<colmns&&grid[row][colmn+1]=='1')
        {
            dfs(grid,row,colmn+1);
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size()==0)
        {
            return 0;
        }
        int res=0;
        int rows=grid.size();
        int colmns=grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colmns; j++)
            {
                if (grid[i][j]=='1')
                {
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid={
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    int res=s.numIslands(grid);
    cout<<res;
    return 0;
}