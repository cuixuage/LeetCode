/*
������496�� findnums��nums��û���ظ�Ԫ���ҽ�������������ƽ�
���еݼ����м���stack��������stack.top��ѭ��stack.popͬʱ�޸�map

����: ѭ��������Ѱ�ҡ�������ʼѰ��
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

//����1 O(n^2)
vector<int> nextGreaterElements(vector<int>& nums)
{
    vector<int> result(nums.size(),-1);
    int length = nums.size();
    //result.reserve(length);
    for(int i=0; i<length; i++)
    {
        result[i]=-1;           //���ڴ��жϵ�ÿһ��Ԫ���ȳ�ʼ��Ϊ-1
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
//����2: stack O(n)  �����һ��Ԫ�ؿ�ʼ�ж�
//����ζ�Ŷ������ұߵ�Ԫ�أ����ȳ��Դ���߿�ʼ�ҵ���һ�������Ԫ�ء�����ߵ�Ԫ��������ʵ���Ԫ�����ѵ���
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
//**************************����
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
