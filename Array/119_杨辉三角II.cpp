/*
O(k)空间的大小
计算第m列的vector数值
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
                vector<int> vi(rowIndex + 1);
       	vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)
        {
            //*******************************************************************************************
        	for (int j = i; j > 0; --j)    //J 循环反向开始，正向开始会导致下一个 j-1 的数值不为初始值
        	{
	        	vi[j] = vi[j] + vi[j-1];
        	}
        }
        return vi;
    }

};
