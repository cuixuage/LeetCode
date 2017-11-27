/*
给定数组[a,b,c,d] 更改括号的优先级使得元素相除 商值最大
math: 商最大即除数最小 b/c/d < b/(c/d)
*/

//**********int 整形数据转化为string 使用stringstream

#include"func.h"
string optimalDivision(vector<int>& nums) {
    stringstream ss;
    string temp;
    if(nums.size()==1){
        ss<<nums[0];
        temp = ss.str();
        return temp;
    }
    if(nums.size()==2){
        ss<<nums[0];
        temp = ss.str();
        ss.str("");      //*************stringstream clear操作 ss.clear()只是清除标志位
        ss<<nums[1];
        temp += "/"+ss.str();
        return temp;
    }
    ss<<nums[0];
    temp = ss.str() + "/"+"(";
    for(int i=1;i<nums.size()-1;i++){
        ss.str("");
        ss<<nums[i];
        temp += ss.str() +"/";
    }
    ss.str("");
    ss<<nums[nums.size()-1];
    temp += ss.str() + ")";
    return temp;
}

//************
int main(){
    vector<int> nums;
    nums.reserve(32);
    nums.push_back(1000);
    nums.push_back(100);
    nums.push_back(10);
    nums.push_back(2);
    cout<<optimalDivision(nums)<<endl;
    return 0;
}

//**********int 整形数据转化为string 使用stringstream
