/*
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
DP 自底向上是更加直观的
minpath[k][i] = min( minpath[k+1][i], minpath[k+1][i+1]) + triangle[k][i];
init: 最底层的值就是它们自己
minpath[i] = min( minpath[i], minpath[i+1]) + triangle[k][i];
*/

#include "func.h"
int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = std::min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
        }
    }
    return minlen[0];
}