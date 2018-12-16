 /*
 2D矩阵row从左到右, col从上到下是升序的
 寻找target
 思路:
 从右上角寻找, 大于key下移行  小于key左移列
 直观: 对角线的区分
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0) return false;
    int row = 0;
    int col = matrix[0].size()-1;       //在右上角
    
    while(col>=0 && row<matrix.size()){
        if(target == matrix[row][col])
            return true;
        else if(target > matrix[row][col])
            row++;
        else
            col--;
    }
    return false;   
}
