/*
Given array numss = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

思路:
1.O(N^3)
2.O(N^2)
对于三元组后面两个元素，相当于2sum.   特别注意: 去除重复元素(在扫描过程中跳过连续的重复元素 ？因为后续)
*/
#include "func.h"
vector<vector<int>> threeSum(vector<int> &nums){
    //排序
    std::sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int len = nums.size();   //当nums为空时 nums.size()-1导致整数下溢,成为一个大整数
    for(int i=0;i<len-2;i++){
        if(i==0 || (i>0 && nums[i] != nums[i-1])){
            //two sum
            int lo=i+1, hi=len-1,sum=0-nums[i];
            while( lo<hi){
                if(nums[lo]+nums[hi]==sum){
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[lo]);
                    item.push_back(nums[hi]);
                    ans.push_back(item);
                    while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                    lo++;hi--;  //跳过重复元素
                }
                else if(nums[lo]+nums[hi]<sum) lo++;
                else hi--;
            }
        }
    }
    return ans;
}

int main(int args,char** argv){
    vector<int> nums;
    cout<<"start"<<endl;
    cout<<threeSum(nums).size()<<endl;
    return 0;
}
