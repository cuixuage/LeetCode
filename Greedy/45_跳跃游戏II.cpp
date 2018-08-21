#include "func.h"
/*
最小的跳跃步数
假设总是可以到到最后一步
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

// restruct my 55_Problem Error  边界条件的步数老是出错
//最终Accept了
bool canJump(vector<int>& nums){
    if(nums.size()==0 || nums.size()==1) return 0;
    int max_index = 0;      //final index
    int next_i = 0;
    int countStep = 0;
    //把一次性就能通过的情况单列出来
    if(nums[0]+0 >= nums.size()-1) return 1;
    
    for(int i=0;i<nums.size();){
        for(int j=i;j<nums.size() && j<=nums[i]+i;j++){
            if(nums[j]+j >= max_index){
                max_index = nums[j]+j;
                next_i = j;
            }
        }
        i = next_i;         //跳跃到当前最远距离
        countStep++;
        //[2,0,0] return 1;
        if(max_index == i || max_index >= nums.size()-1) break;
        
    }
    return countStep+1;
}


//discuss 简单方法
public int jump(int[] A) {
    int sc = 0;
    int e = 0;      //记录之前可以达到的最大值
    int max = 0;
    for(int i=0; i<A.length-1; i++) {
        max = Math.max(max, i+A[i]);        //i+A[i]
        if( i == e ) {
            sc++;
            e = max;            //下一轮可以到达的最大位置
        } 
    }
    return sc;
}
