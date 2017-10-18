/*
数组sum1是数组sum2的子集，两个数组中均没有重复的元素。
对于sum1中每一个元素来说，sum2对应sum1相同值的位置的 [后面的所有的元素] 是否比当前值大？val:-1

假设我们有一个减少的序列后跟一个更大的数字
例如[5, 4, 3, 2, 1, 6]，更大的数字6是序列中所有以前的数字的下一个更大的元素

我们使用堆栈来保持一个递减的子序列，每当我们看到一个数字x大于stack.peek()我们弹出所有的元素小于x和所有弹出的元素，他们的下一个更大的元素是x
例如[9, 8, 7, 3, 2, 1, 6]
堆栈将首先包含[9, 8, 7, 3, 2, 1]，然后我们看到6哪个是大于1我们弹出1 2 3的下一个更大的元素应该是6
*/
#include<iostream>
#include<stack>
#include<map>
#include<unordered_map>
#include<vector>
using std::cout;
using std::endl;
using std::stack;
using std::map;
using std::vector;
using std::unordered_map;    //map会按照key自动排序
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    unordered_map<int,int> maptable;    //后面存在更大值的元素  保存下来
    stack<int> numsVal;    //保存(没有更大值元素)递减序列

    for(auto val:nums){
        while(!numsVal.empty() && numsVal.top()<val){
            maptable[numsVal.top()]=val;      //这些元素的后面是存在更大的VAL
            numsVal.pop();
        }
        numsVal.push(val);   //***********递减序列
    }
    vector<int> answer;
    for(auto val:findNums){
                                    //count存在返回1 否则0
        if(maptable.count(val))     //find 返回map迭代器 maptable.find(val)!=maptable.end()
            answer.push_back(maptable[val]);

        else answer.push_back(-1);
    }
    return answer;
}

//**************************测试
int main(int argc,char** argv){
    vector<int> findNums,Nums;
    Nums.push_back(1);
    Nums.push_back(3);
    Nums.push_back(4);
    Nums.push_back(2);
    findNums.push_back(4);
    findNums.push_back(1);
    findNums.push_back(2);

    vector<int> ans;
    ans.reserve(64);
    ans = nextGreaterElement(findNums,Nums);
    for(auto val:ans){
        cout<<val<<endl;
    }
    return 0;
}
