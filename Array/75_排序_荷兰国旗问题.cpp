/*
0,1,2分别代表三种颜色 使得颜色相同的相邻
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/
#include "func.h"
/*
思路1:  quicksort
思路2: 统计0,1,2分别出现的次数 重新覆盖掉原数组
思路3: 三路快排的变型？？
核心思路1: 两次快排的变型,每次排序好一种情况
核心思路2: 荷兰国旗问题,p1指向数字0的右边界,p2指向数字2的左边界（边界都是开区间）
*/

//核心思路2:

void sortColors(vector<int>& nums){
    int p1 = 0; //数字0的右边界,开区间
    int p2 = nums.size()-1; //数字2的左边界,开区间
    int cur = 0;    
    while(cur <= p2){           //终止循环条件      这里是小于等于
        if(nums[cur]==0){
            std::swap(nums[p1],nums[cur]);
            p1 ++;
            cur ++;
        }
        else if(nums[cur]==2){
            std::swap(nums[p2],nums[cur]);
            p2--;
            cur;        //这里不移动
        }
        else
            cur++;
    }
}

// while 循环不加小于等于则:
// Input
// [2,0,1]
// Output
// [1,0,2]
// Expected
// [0,1,2]


void sortColors(vector<int>& nums) {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    for(int tmp:nums){
        if(tmp==0) num1++;
        else if(tmp==1) num2++;
        else num3++;
    }
    for(int i=0;i<nums.size();i++){
        if(i<num1) nums[i]=0;
        else if(i<num1+num2) nums[i]=1;
        else nums[i]=2;
    }
}
