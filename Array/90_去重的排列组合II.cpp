/*
区别于78题 本题可能包含重复元素如何完成结果中的去重？
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

//思路1: set额外增加了O(n)的空间复杂度
//思路2: 优化78的递推

vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> ans = {{}};     //相当于resize(1)
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();){
        int countDup =0;
        while(countDup+i<nums.size() && nums[countDup+i]==nums[i])  countDup++;
        
        int len = ans.size();
        for(int j=0;j<len;j++){
            vector<int> tmp = ans[j];
            //处理连续的重复元素nums[i]
            for(int k=0;k<countDup;k++){
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        
        i += countDup;      //更新nums遍历位置
    }
    return ans;
}
