#include "func.h"
/*
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
思路: 递归
*/

vector<vector<int> > permute(vector<int> &num){
    vector<vector<int>> result;
    permuteRecursive(num,0,result);
    return result;
}

void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result){
    //递归出口
    if(begin==num.size()){
        result.push_back(num);
        return ;
    }
    for(int i=begin; i<num.size();i++){
        std::swap(num[begin],num[i]);
        permuteRecursive(num,begin+1,result);
        //reset
        std::swap(num[begin],num[i]);
    }
}
/*
begin=0时 i=0，i=1，i=2
第二层迭代 begin=1时 i=1，i=2
第三层迭代 begin=2时 i=2

swap(num[begin],num[i])
分别对应的排列是:
begin=0,i=0时的三层迭代 1,2,3  1,3,2
begin=0,i=1时的三层迭代 2,1,3  2,3,1
begin=0,i=2时的三层迭代 3,1,2  3,2,1
*/
