class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > r(numRows);

        for (int i = 0; i < numRows; i++) {
                //resize函数必须有
            r[i].resize(i + 1);              //定义vector<int>大小为行数+1
            r[i][0] = r[i][i] = 1;       //两侧均为1

            for (int j = 1; j < i; j++)   //每一层边界条件
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }     

};
