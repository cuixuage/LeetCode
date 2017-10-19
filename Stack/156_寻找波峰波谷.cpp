/*形如  132模式  at i < j < k and ai < ak < aj
*/

#include<iostream>
#include<stack>
#include<vector>
#include<limits>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

//******************方法1  时间N^2
//思想:  已知波谷 波峰 寻找是否存在a[k]
bool find132_1(vector<int>& nums)
{
    int minNum = INT_MAX;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] < minNum) minNum=nums[i];   //对于假设num[i]为波峰 波谷minNum
        for(int j=i+1; j<nums.size(); j++)
            if(nums[j]<nums[i] && nums[j]>minNum) return true;   //判断是否存在
    }
    return false;
}
//  时间N^3暴力计算是不接受的

//**********************方法2
//堆栈方法  时间N 线性的
//*************************************还是不太理解？？？？
//数组保存波谷值  stack保存a[k]  at i < j < k and ai < ak < aj
//public boolean find132pattern(int[] nums)
//{
//    if (nums.length < 3)
//        return false;
//    Stack < Integer > stack = new Stack < > ();
//    int[] min = new int[nums.length];
//    min[0] = nums[0];
//    for (int i = 1; i < nums.length; i++)
//        min[i] = Math.min(min[i - 1], nums[i]);
//    for (int j = nums.length - 1; j >= 0; j--)
//    {
//        if (nums[j] > min[j])
//        {
//            while (!stack.isEmpty() && stack.peek() <= min[j])
//                stack.pop();
//            if (!stack.isEmpty() && stack.peek() < nums[j])
//                return true;
//            stack.push(nums[j]);
//        }
//    }
//    return false;
//}

//*******************测试
int main(int argc,char** argv){
    vector<int> nums;
    nums.reserve(64);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout<<find132_1(nums)<<endl;
    return 0;
}
