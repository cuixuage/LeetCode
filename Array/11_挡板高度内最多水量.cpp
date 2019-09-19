/*
连续的非负整数  计算其中容积水量最大的数值

只需要考虑挡板问题(左右的 最低高度)
*/
/*
思路:
先找第一个和最后一个  这两者之间的宽度是最大的； 如果容量的水需要更大 则高度必须更高

画图: 多思考几种case
*/


//1. 头尾指针问题
//2. 向中间移动过程中,如果其挡板高度低于原来的h_min 就不可能存储最大水量
int maxArea(vector<int>& height){
    int water = 0;
    int i=0;
    int j=height.size()-1;
    while(i<j){
        int h_min = std::min(height[i],height[j]);     
        water = std::max(water,(j-i)*h_min);
        //小于等于
        while(height[i]<=h_min && i<j) i++;
        while(height[j]<=h_min && i<j) j--;
    }
    return water;
}
