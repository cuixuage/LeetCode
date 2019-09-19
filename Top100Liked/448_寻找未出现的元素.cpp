/*
在 1<=a[i]<=n的范围内,寻找未出现的元素。其中n是数组的size
要求: O(1)空间 O(N)时间
思路1:
排序后将未出现的数字print. O(NlogN+N)时间
思路2:
建立大小为N的hashmap, O(N)空间 O(N)时间
思路3:
nums[nums[i]-1] = -nums[nums[i]-1]
遍历一遍,将其val-1（也就是nums[i]-1）位置的值置为负。 那么最终val出现过的位置被标记为负值


寻找所有的缺失元素
*/

//本题目类似于: 寻找出现的重复的元素 442题

#include "func.h"
vector<int> findDisappearedNumbers(vector<int>& nums){
    vector<int> ans;
    // 1.将val作为序号 标记为负
    for(int i=0;i<nums.size();i++){
        int val = std::abs(nums[i])-1;  //start from index 0
        if(nums[val]>0) nums[val] = -nums[val];
    }
    // 2.寻找非负值的序号
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0) ans.push_back(i+1);
    }
    return ans;
}