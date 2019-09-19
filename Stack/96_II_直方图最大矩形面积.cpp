#include "func.h"
/*
Input: [2,1,5,6,2,3]
Output: 10
思路:
1.O(N)~O(N^2) 遍历一遍
2. stack存放直方图面积*连续*递增的 对应位置序号(待遍历的前一个元素为止)
3.遇到不递增的元素i时:  以pre直方图为起始,向左遍历stack j(序号j<i)
h=遍历元素高,wide=i-j-1   记录maxArea
4.额外给input添加元素0

主要idea: 递增的序列总能在下一步找到最大值
*/

int largestRectangleArea(vector<int>& heights){
    int maxarea=0;
    heights.push_back(0);       //input + 0
    std::vector<int> stack;     //vector模拟stack
    
    for(int i=0;i<heights.size();i++){
        //遇到小于stack.top元素
        //开始向left遍历stack
        while(stack.size()>0 && heights[i]<=heights[stack.back()]){
            int h = heights[stack.back()];
            stack.pop_back();
            
            //-1 宽度延长到序号0(在计算栈底元素时)
            int s_idx = stack.size()>0?stack.back():-1;
            if(h*(i-s_idx-1) > maxarea)
                maxarea = h*(i-s_idx-1);
        }
        //大于stack top==总是可以在下一步找到更大area
        stack.push_back(i);
    }
    return maxarea;
}
