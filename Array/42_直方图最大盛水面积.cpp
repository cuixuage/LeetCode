/*
思路:
two points分别是左右maxLeft maxRight边界
从边界较矮的一侧流水  水量=maxLeft - left(left<maxLeft)

思路=注水  而非直接计算面积(w*h)
*/

int trap(vector<int>& heights){
    int left = 0;
    int right = heights.size()-1;
    int res = 0;
    int maxLeft=0,maxRight=0;
    
    while(left < right){
        //先寻找较矮的边界
        if(heights[left] <= heights[right]){
            if(heights[left] >= maxLeft)
                maxLeft = heights[left];
            else
                res += maxLeft - heights[left];
            left ++;
        }
        //右侧边界更矮
        else{
            if(heights[right] >= maxRight)
                maxRight = heights[right];
            else
                res += maxRight - heights[right];
            right --;
        }
    }
    return res;
}
