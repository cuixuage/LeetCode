#include "func.h"
/*
思路1:  已经AC
O(N*N)
将每一个直方图作为起始点（向左向右拓展）,记录比current直方图的高 的连续长度。选取max
*/

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


/*
思路2
comment 解释
https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28905/My-concise-C++-solution-AC-90-ms

stack存储之前的递增序列，遇到新元素后会将其放在stack的合适位置
*/

int largestRectangleArea(vector<int> &height){
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
