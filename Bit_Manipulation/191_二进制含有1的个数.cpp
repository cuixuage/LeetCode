
//��n��1�������Ƶ���(AND)���㣬�����ж��������λ�Ƿ�Ϊ1������ǵĻ����Ѽ���������һ��
//Ȼ���n�����ƶ�һλ���ظ���������
#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main(){
    cout<<hammingWeight(2)<<endl;
}
