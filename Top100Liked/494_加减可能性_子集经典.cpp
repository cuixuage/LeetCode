#include "func.h"
/*
给定array元素，只能执行加或者减，等于target的有多少种计算方式
证明: https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
转化为计算 sum(subset)==K的个数

假设子集P使用加法,子集N使用减法。 那么
sum(P)-sum(N) = target
sum(P)+sum(N)+sum(P)-sum(N) = target + sum(P) + sum(N)
即 2*sum(P) = target + sum(array)
即 target_val + sum(array)必须是偶数，问题转化为: 子集和为某一个定值的情况数目     关键

leetcode 560.subarray sum equals K ("连续"子序列问题)
leetcode 78. subset（无重复元素的所有子集 e.g.二叉树思想=DFS回溯）
leetcode 90. subsetII (有重复元素的所有子集)
*/

// //subset leetcode78
// vector<vector<int>> subsetsWithDup(vector<int> &array) {
//     if (array.empty()) return {};
//     vector<vector<int>> res;
//     vector<int> subset;
//     std::sort(array.begin(), array.end());      //1. sort
//     getSubsets(array, 0, subset, res);
//     return res;
// }
// void getSubsets(vector<int> &array, int pos, vector<int> &subset, vector<vector<int>> &res) {
//     res.push_back(subset);
//     for (int i = pos; i < array.size(); ++i) {
//         subset.push_back(array[i]);  //2.
//         getSubsets(array, i + 1, subset, res);
//         subset.pop_back();      //3.  回溯; 二叉树的思想
//         // while (i + 1 < array.size() && array[i] == array[i + 1]) ++i;            //重复元素当做distinct元素
//     }
// }

// //leetcode 494  （超时）
// int findTargetSumWays(vector<int>& nums, int target) {
//     int sums = 0;
//     for(auto& i : nums) sums += i;
//     if(sums < target || (sums+target)&1) return 0;      //sums+target是奇数,不存在满足条件的子集
//     int count = 0;
//     vector<vector<int>> subsets = std::move(subsetsWithDup(nums));
//     for(auto& subset : subsets){
//         int sub_sum = 0;
//         for(auto& i : subset)
//             sub_sum += i;
//         if(sub_sum == (sums+target)>>1)         //sum(subset) == (target+sum(array))/2
//             count ++;
//     }
//     return count;
// }

// trick  =>  子集和为定值
//subset leetcode78
int subsetsWithDup(vector<int> &array,int target) {
    if (array.empty()) return {};
    std::sort(array.begin(), array.end());      //1. sort
    int subset = 0;
    int count = 0;
    getSubsets(array, 0, subset, count,target);
    return count;
}
void getSubsets(vector<int> &array, int pos, int& subset, int& count, int target) {
    if(subset == target) count++;
    for (int i = pos; i < array.size(); ++i) {
        subset += array[i];
        getSubsets(array, i + 1, subset, count,target);
        subset -= array[i];
        // while (i + 1 < array.size() && array[i] == array[i + 1]) ++i;            //重复元素当做distinct元素,子集重复元素排列组合
    }
}

//leetcode 494
int findTargetSumWays(vector<int>& nums, int target) {
    int sums = 0;
    for(auto& i : nums) sums += i;
    if(sums < target || (sums+target)&1) return 0;
    int count = 0;
    target = (sums+target)>>1;          //sum(subset) == (target+sum(array))/2
    return subsetsWithDup(nums,target);
}