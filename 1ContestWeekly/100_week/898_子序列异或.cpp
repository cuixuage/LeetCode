#include "func.h"
/*

尚未通过
问题1:
[1,1,2]子序列去重
The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].

问题2:
 [1,2,4]子序列怎么算出来7个？？
*/

int subsets(vector<int>& nums) {
    cout<<nums.size()<<endl;
    if(nums.size() <=1 ) return nums.size();
    vector<int> subs(1, 0);
    for (int i = 0; i < nums.size(); i++) {
        int n = subs.size();
        for (int j = 0; j < n; j++) {
            subs.push_back(subs[j]);
            subs.back() = subs.back() | nums[i];
        }
    }
    std::sort(subs.begin(),subs.end());
    int count=1;
    for(auto i:subs)
        cout<<i<<" ";
    for(int i=0;i<subs.size()-1;i++){
        if(subs[i] == subs[i+1]) continue;
        else count++;
    }
    return count;
}

int main(){
    vector<int> nums = {1,2,4};
    cout<<endl<<subsets(nums)<<endl;
    return 0;
}
