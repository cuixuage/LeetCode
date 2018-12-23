/*
构造螺旋数组
对比: 54题是按照螺旋数组遍历
稍微改造即可
*/

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix;
    matrix.resize(n,vector<int>(n));
    if(n==0) return matrix;
    int rowBegin = 0;
    int rowEnd = matrix.size()-1;
    int colBegin = 0;
    int colEnd = matrix[0].size()-1;
    int num=1;      //change
    
    while(rowBegin<=rowEnd && colBegin<=colEnd){
        //right
        for(int i=colBegin;i<=colEnd;i++)
            matrix[rowBegin][i] = num++;
        rowBegin++;
        //down
        for(int i=rowBegin;i<=rowEnd;i++)
            matrix[i][colEnd] = num++;
        colEnd--;
        //left
        if(rowBegin <= rowEnd){
            for(int i=colEnd;i>=colBegin;i--)
                matrix[rowEnd][i]=num++;
        }
        rowEnd--;
        //up
        if(colBegin<=colEnd){
            for(int i=rowEnd;i>=rowBegin;i--)
                matrix[i][colBegin]=num++;
        }
        colBegin++;
    }
    return matrix;
}
