#include "func.h"

int topButton(vector<vector<int>>& grid)
{
    int len = grid.size();
    int count = 0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(grid[i][j]==0)
                count++;
        }
    }
    //cout<<"top="<<(len*len-count)*2<<endl;
    return (len*len-count)*2;
}

int leftRight(vector<vector<int>>& grid)
{
    int len = grid.size();
    int count = 0;
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(i!=0 && grid[i][j]!=grid[i-1][j])
                count += std::abs(grid[i][j] - grid[i-1][j]);
            if(j!=0 && grid[i][j]!=grid[i][j-1])
                count += std::abs(grid[i][j] - grid[i][j-1]);
        }
    }
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            //这里需要分开计算最外侧的外面表面积
            if(i==0)
                count += grid[i][j];
            if(i== len-1)
                count += grid[i][j];
            if(j==0)
                count += grid[i][j];
            if(j==len-1)
                count += grid[i][j];
        }
    }
    return count;
}

int surfaceArea(vector<vector<int>>& grid)
{
    //正方形网格 N*N
    return topButton(grid) +leftRight(grid);

}


/*
//用投影做  很麻烦  放弃
int around(vector<vector<int>>& grid){
    int len = grid.size();
    vector<int> frontBackMax(len,0);
    vector<int> leftRightMax(len,0);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            leftRightMax[i] =std::max(leftRightMax[i],grid[i][j]);
            frontBackMax[j] = std::max(frontBackMax[j],grid[i][j]);
        }
    }
    int count1 =0;
    int count2 = 0;
    for(int i=0;i<len;i++){
        count1 += leftRightMax[i];
        count2 += frontBackMax[i];
    }
    return 2*(count1+count2);
}

int inSurface(){

}
*/

int main()
{
    vector<vector<int>> grid= {{2,2,2},{2,1,2},{2,2,2}};
    cout<<surfaceArea(grid)<<endl;
}
