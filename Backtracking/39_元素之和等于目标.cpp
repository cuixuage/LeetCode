/*
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
//candidates中的元素可以被多次使用,其中没有重复元素
//类似于DFS的思想
//对比题目77题

public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //升序排序
    std::sort(candidates.begin(),candidates.end());
    vector<vector<int>> result;
    vector<int> token;
    combinationSum(candidates,target,result,token,0);
    return result;
}

private:
    void combinationSum(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& token,int begin){
        //target==0 means成功寻找到
        if(!target){
            result.push_back(token);
            return;
        }
        //注意回溯时begin位置  仍然是i
        for(int i=begin;i!=candidates.size() && target >= candidates[i]; ++i){
            token.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],result,token,i);
            token.pop_back();
        }
    }
