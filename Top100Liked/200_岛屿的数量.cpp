#include "func.h"
/*
二维数组中独立1的个数
每次从一个1出发,将其能到达的点全部标识为0
*/

class {
private:
    int row = 0;
    int column = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        row = grid.size();
        column = grid[0].size();
        if( row == 0 ) return 0;
        for(int i=0;i<row; i++){
            for(int j=0;j<column;j++)
                if(grid[i][j] == '1'){
                    DFSMarking(grid,i,j);
                    ++count;
                }
        } 
        return count;
    }

    void DFSMarking(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j>0 || i<=row || j>=column || grid[i][j]!='1') return ;
        grid[i][j] = '0';       //可到达的点 标识为0
        DFSMarking(grid,i+1,j);
        DFSMarking(grid,i-1,j);
        DFSMarking(grid,i,j+1);
        DFSMarking(grid,i,j-1);
    }
};
