#include "func.h"
/*
非负数组 每一个element代表了可以跳跃的步数  能否跳跃到终点？
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index
思路1:
每一次跳跃选择可选范围内的最大距离
e.g 2 3 1 1 1 4
=>2 3 1之间的下一步最大
=>3 1 1 4之间的下一步最大
=>break


*/
//accept
bool canJump(vector<int>& nums){
    if(nums.size()==0 || nums.size()==1) return true;
    int max_index = 0;
    int next_i = 0;
    bool res = false;
    for(int i=0;i<nums.size();){
        for(int j=i;j<nums.size() && j<=nums[i]+i;j++){
            if(nums[j]+j >= max_index){
                max_index = nums[j]+j;
                next_i = j;
            }
        }
        i = next_i;
        //[2,0,0] return true;
        //max_index==i e.g[3 2 1 0 4] return false
        if(max_index == i || max_index >= nums.size()-1) break;
    }
    if(max_index >= nums.size()-1) return true;
    else return false;
}

//discuss 简单
//线性的时间O(N)
public boolean canJump(int[] A) {
    int max = 0;
    for(int i=0;i<A.length;i++){
        if(i>max) {return false;}       //永远也无法到达
        max = Math.max(A[i]+i,max);
    }
    return true;
}
