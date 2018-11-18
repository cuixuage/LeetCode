//candidates中的元素只能被使用一次
//同时candidates中的元素不唯一


public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //升序排序
    std::sort(candidates.begin(),candidates.end());
    vector<vector<int>> result;
    vector<int> token;
    combinationSum(candidates,target,result,token,0);
    return result;
}

private:
    //注意 candidatas targrt参数  以及 result token begin参数
    void combinationSum(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& token,int begin){
        //先写递归出口
        if(!target){
            result.push_back(token);
            return;
        }
        //注意回溯时begin位置
        //Error 错误写法
        // for(int i=begin;i!=candidates.size() && target >= candidates[i];){
        //     token.push_back(candidates[i]);
        //     while(i!=0 && candidates[i-1] == candidates[i]) i++;
        //     combinationSum(candidates,target-candidates[i],result,token,i);
        //     token.pop_back();
        // }
        
        
        //再次递归时的begin位置  是i+1
        for(int i=begin;i!=candidates.size() && target >= candidates[i];i++){
            //1.方法1  最容易理解
            // if(i > begin && candidates[i-1]==candidates[i]) 
            //     continue;
            token.push_back(candidates[i]);    
            combinationSum(candidates,target-candidates[i],result,token,i+1);
            //2.方法2  想不明白为什么正确
            while (i < candidates.size() && candidates[i] == candidates[i+1]) i++;
            token.pop_back();
            //3.方法3
            // while (i < candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
    }
    
//FIXME:  why this is correct？？
void dfs(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& combination, int begin) {
    if (!target) {
        result.push_back(combination);
        return;
    }
    for (int i = begin; i < nums.size() && target >= nums[i]; i++) {
        combination.push_back(nums[i]);
        //combinationSum1 : dfs(nums, target - nums[i], result, combination, i);
        dfs(nums, target - nums[i], result, combination, i + 1);
        combination.pop_back();
        //combinationSum1 : no this line to filter the duplicate cases 
        while (i < nums.size() && nums[i] == nums[i+1]) i++;
    }
}
