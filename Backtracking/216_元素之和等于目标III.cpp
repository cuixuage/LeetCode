/*
candidates=[1,2,3,4,5,6,7,8,9]
寻找所有排列组合 add k numbsers to target
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution{
public:
vector<vector<int>> combinationSum3(int k, int target) {
    vector<vector<int>> result;
    vector<int> token;
    combinationSum(result,token,k,target,0);
    return result;
}

private:
    vector<int> candidates = {1,2,3,4,5,6,7,8,9};
    void combinationSum(vector<vector<int>>& result,vector<int>& token,int k,int target,int begin){
        //先写递归出口
        if(target==0 && k==0){
            result.push_back(token);
            return;
        }
        for(int i=begin;i!=candidates.size() && target >= candidates[i] && k>0;i++){
            token.push_back(candidates[i]);
            combinationSum(result,token,k-1,target-candidates[i],i+1);
            token.pop_back();
        }
    }
}
