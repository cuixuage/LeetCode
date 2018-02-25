//�������� Ѱ�ҵ����ж�ʧ��Ԫ��
//Input: [9,6,4,2,3,5,7,0,1]
//Output: 8
/*
˼·1: ��ֱ�۵�˼·�Ƕ����ݽ�������Ȼ������ɨ�裬�����ҳ�©�������֣����ǻ��ڱȽϵ������㷨��ʱ�临�Ӷ�������nlog(n)
˼·2: ���еľ�������ʱ�临�Ӷȵ��㷨����͡���0��n��ͣ�Ȼ��Ը�����������ͣ�����֮�Ϊ©��������
˼·3: ���Ƚ�0��n��Щ������������㣬Ȼ���������������������㣬��������������������㣬�������©�������֣���Ϊ�������������������ж��ǳɶԳ��ֵģ���������õ�0
*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int missingNumber(vector<int>& nums)
{
    int x = 0;
    for (int i = 0; i <= nums.size(); i++) x ^= i;
    for (auto n : nums) x ^= n;
    return x;
}

int main(int argc,char** argv){
    vector<int> test{9,6,4,2,3,5,7,0,1};
    cout << missingNumber(test)<<endl;
    return 0;
}
