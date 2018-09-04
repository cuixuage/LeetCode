/*
题目前提:
数组中没有重复元素  求取所有可能的排列组合
(即结果中不必考虑重复的排列)
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//idea:  递推思路  Accept

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    ans.resize(1);
    for(auto num:nums){
        int len = ans.size();
        for(int i=0;i<len;i++){
            vector<int> tmp = ans[i];
            tmp.push_back(num);
            //不断改变了ans的size  注意循环不能使用ans.size()作为终止判断
            ans.push_back(tmp);
        }
    }
    return ans;
}
