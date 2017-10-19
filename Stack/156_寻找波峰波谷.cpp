/*����  132ģʽ  at i < j < k and ai < ak < aj
*/

#include<iostream>
#include<stack>
#include<vector>
#include<limits>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

//******************����1  ʱ��N^2
//˼��:  ��֪���� ���� Ѱ���Ƿ����a[k]
bool find132_1(vector<int>& nums)
{
    int minNum = INT_MAX;
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] < minNum) minNum=nums[i];   //���ڼ���num[i]Ϊ���� ����minNum
        for(int j=i+1; j<nums.size(); j++)
            if(nums[j]<nums[i] && nums[j]>minNum) return true;   //�ж��Ƿ����
    }
    return false;
}
//  ʱ��N^3���������ǲ����ܵ�

//**********************����2
//��ջ����  ʱ��N ���Ե�
//*************************************���ǲ�̫��⣿������
//���鱣�沨��ֵ  stack����a[k]  at i < j < k and ai < ak < aj
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

//*******************����
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
