/*
1.n个小正方体累在一起，表面积是 4n+2
2.当你在旁边紧挨着再放一个累加的物体时，二者就会产生重叠，重叠的面数就是二者较矮的那堆正方体的个数再乘以2
3.减去遮挡面积
*/
#include "func.h"
int surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size(), res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] > 0) res += 4 * grid[i][j] + 2;
            if (i > 0) res -= std::min(grid[i][j], grid[i - 1][j]) * 2;    //重叠面积
            if (j > 0) res -= std::min(grid[i][j], grid[i][j - 1]) * 2;    //重叠面积
        }
    }
    return res;
}