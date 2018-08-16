#include "func.h"
/*
思路1:
DP 动态规划
https://leetcode.com/problems/maximal-rectangle/discuss/29054/Share-my-DP-solution
思路2:
基于直方图的最大矩形题目。按照每一行为底部，height[i]记录当前位置的连续1个数
*/

int maximalRectangle(vector<vector<char>> matrix){
    if(matrix.size()==0) return 0;
    //reserve vector
    vector<vector<int>> height(matrix.size(),vector<int>(matrix[0].size()));

    for(int i=0;i<height.size();i++){
        for(int j=0;j<height[0].size();j++){
            height[i][j] = matrix[i][j]-'0';
            if(height[i][j]==1 && i>0)
                height[i][j] += height[i-1][j];      //到i行为止,连续数值1的个数
        }
    }
    int max_area = 0;
    for(auto h: height){
        max_area = std::max(largestRectangleArea2(h),max_area);
    }
    return max_area;
}

int largestRectangleArea(vector<int>& heights) {
    int area=0;
    for(int i=0;i<heights.size();i++){
        int len=0;
        for(int j=i;j<heights.size();j++){
            if(heights[j]<heights[i]) break;
            len++;
        }
        //思考[2,1,2]例子  需要向左拓展
        for(int j=i-1;j>=0;j--){
            if(heights[j]<heights[i]) break;
            len++;
        }
        if(area < heights[i]*len)
            area = heights[i]*len;
    }
    return area;
}

int largestRectangleArea2(vector<int> &height){
    int maxarea = 0;
    height.push_back(0);        //考虑全部递增case
    std::vector<int> stack;

    for(int i=0;i<height.size();i++){
        //stack top总是current直方图的左边第一个元素
        //大于stack top意味着总是可以出现更大的area
        while(stack.size()>0 && height[stack.back()] >= height[i]){
            int h = height[stack.back()];
            stack.pop_back();
            int sidx = stack.size()>0 ? stack.back():-1;        //sidx+1是左边的矩形
            if(h*(i-sidx-1)>maxarea)
                maxarea = h*(i-sidx-1);
        }
        stack.push_back(i);
    }
    return maxarea;
}
