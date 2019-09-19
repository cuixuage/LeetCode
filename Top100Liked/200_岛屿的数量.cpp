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
        if( row == 0 ) return 0;
        column = grid[0].size();
        for(int i=0;i<row; i++){
            for(int j=0;j<column;j++)
                if(grid[i][j] == '1'){
                    DFSMarking(grid,i,j);       //i,j起点位置
                    ++count;
                }
        } 
        return count;
    }

    void DFSMarking(vector<vector<char>>& grid, int i, int j){
        //1.先写终止条件 关键:grid[i][j]!='1'
        if(i<0 || j<0 || i>=row || j>=column || grid[i][j]!='1') return ;
        //2.已到达位置标记为'0'
        grid[i][j] = '0'; 
        DFSMarking(grid,i+1,j);
        DFSMarking(grid,i-1,j);
        DFSMarking(grid,i,j+1);
        DFSMarking(grid,i,j-1);
    }
};
