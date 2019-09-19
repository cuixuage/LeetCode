/*
原地顺时针旋转90°
应用: 图像旋转
*/
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
//思路: 上下翻转 + 左下三角和右上三角的交换

void rotate(vector<vector<int>>& matrix){
    //上下翻转
    std::reverse(matrix.begin(),matrix.end());
    //右上角 左下角
    for(int i=0;i<matrix.size();i++){
        for(int j=i;j<matrix[i].size();j++)     //关键
            //matrix[i][j]是右上角
            std::swap(matrix[i][j],matrix[j][i]);
    }
}
