//给定无重复的数字返回所有可能的collection
//https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
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
*/

//思路2: http://xiaohuiliucuriosity.blogspot.hk/2014/12/permutations.html
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
void permuteRecursive(vector<int>&, int, vector<vector<int>>&);
vector<vector<int> > permute(vector<int> &num)
{
    vector<vector<int> > result;
    permuteRecursive(num, 0, result);
    return result;
}

//对于每一个元素都放在首位 然后不断递归后面的元素
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)
{
    if (begin >= num.size())
    {
        result.push_back(num);
        return;
    }

    for (int i = begin; i < num.size(); i++)
    {
        std::swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, result);           //对于本轮循环
        // reset
        std::swap(num[begin], num[i]);
    }
}

int main(int argc,char** argv){
    vector<int> num = {1,2,3};
    vector<vector<int>> ans = permute(num);
    for(auto i : ans){
        for(auto j : i)
            cout<<j<<" ";
         cout<<endl;
    }
}
