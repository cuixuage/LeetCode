/*
要求O(n)时间  获取最长连续序列
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

思路: union Find
*/

#include "func.h"

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        //连续的数字 放入同一个集合
        UionFind uf(n);
        unordered_map<int,int> hashMap;   //hashmap一般做倒排。  key:数组元素   val  val:数组index
        //O(n)
        for(int i=0;i<n;i++){

            //相同元素放入同一集合  有可能最后统计的最长连续序列变多了
            if(hashMap.count(nums[i])) continue;
            hashMap[nums[i]] = i;

            //前后连续的数字是否存在
            //如果存在:  nums序号放入同一个集合
            if(hashMap.count(nums[i]+1))
                uf.union2(i,hashMap[nums[i]+1]);
            if(hashMap.count(nums[i]-1))
                uf.union2(i,hashMap[nums[i]-1]);
        }
        //O(n)
        return uf.maxUnion();
    }
private:
    //quick-union 方法;  dp保存root序号
    class UionFind{
    public:
        UionFind(){};
        UionFind(int n)
        :dp_len(0){
            dp = new int[n];
            dp_len = n;
            for(int i=0;i<n;i++) dp[i] = i;
        };
        void union2(int,int);
        int maxUnion();
    private:
        int find2(int);
        int dp_len;
        int* dp;
    };
};

void Solution::UionFind::union2(int p,int q){
        int i = find2(p);
        int j = find2(q);
        if(i == j) return;
        dp[i] = j;
}

int Solution::UionFind::find2(int i){
    while(i != dp[i]){
        i = dp[i];
    }
    return i;
}

int Solution::UionFind::maxUnion(){
    if(dp_len==0) return 0;
    int count2[dp_len];
    memset(count2,0,dp_len*sizeof(int));
    int max2 = 0;
    for(int i=0;i<dp_len;i++){
        count2[find2(i)] ++;
        max2 = std::max(max2,count2[find2(i)]);
    }
    return max2;
}

int main(int args,char** argv){
    //
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1,1,};
     //vector<int> nums = {};
    Solution test;

    cout<<test.longestConsecutive(nums)<<endl;
    return 0;
}
