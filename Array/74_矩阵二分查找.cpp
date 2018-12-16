/*
给定 sorted matrix,判断target是否存在
二分查找
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0;
    int end = row*col-1;
    //note:  等于号一定要加上
    while(start<=end){
        int mid = (start+end)/2;
        int mid_val = matrix[mid/col][mid%col];         //这也是关键代码
        //mid元素的位置
        
        if(mid_val == target)
            return true;
        else if(mid_val < target)
            start = mid+1;
        else
            end = mid-1;
    }
    return false;
}
