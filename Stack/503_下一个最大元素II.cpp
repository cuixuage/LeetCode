/*
区别于496题 findnums与nums都没有重复元素且解决方法是正向推进
所有递减序列加入stack遇到大于stack.top则循环stack.pop同时修改map

此题: 循环数组中寻找——倒序开始寻找
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

//方法1 O(n^2)
vector<int> nextGreaterElements(vector<int>& nums)
{
    vector<int> result(nums.size(),-1);
    int length = nums.size();
    //result.reserve(length);
    for(int i=0; i<length; i++)
    {
        result[i]=-1;           //对于待判断的每一个元素先初始化为-1
        for(int j=1; j<length; j++)
        {
            if(nums[(i+j)%length] > nums[i])
            {
                result[i] = nums[(i+j)%length];
                break;
            }
        }
    }
    return result;
}
//方法2: stack O(n)  从最后一个元素开始判断
//这意味着对于最右边的元素，首先尝试从左边开始找到下一个更大的元素。在左边的元素上添加适当的元素来堆叠。
    public int[] nextGreaterElements_2(int[] nums) {
       int n = nums.length;
        Stack<Integer> stack = new Stack();
        for(int i = n - 1; i >= 0; i--){
          stack.push(i);
        }

        int[] res = new int[n];
        for(int i = n - 1; i >= 0; i--){
            res[i] = -1;
            while(!stack.isEmpty() && nums[stack.peek()] <= nums[i]){
              stack.pop();
            }

            if(!stack.isEmpty()) res[i] = nums[stack.peek()];
            stack.push(i);
        }
        return res;
    }
//**************************测试
int main(int argc,char** argv)
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    vector<int> result = nextGreaterElements(nums);
    for(auto i : result)
        cout<<i<<endl;
    return 0;
}
