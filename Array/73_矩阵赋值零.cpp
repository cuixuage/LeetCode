//矩阵元素中存在零时  将其行 列都设置为0
/*
1.思路: 标记每一个零元素周围的元素,后面再置位零。空间(m*n) 时间(O(n))
2.O(1)空间是否可行？  从而就地执行
*/

//set 来保存需要置位零的行列
void setZeroes(vector<vector<int>>& matrix){
    set<int> setRow;
    set<int> setCol;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j] == 0){setRow.insert(i);setCol.insert(j);}
        }
    }
    
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(setRow.count(i) || setCol.count(j))
                matrix[i][j]=0;
        }
    }
}
