//�жϸ����������Ƿ�Ϊ2�Ĵ���
//˼·: ��������ת��Ϊ2���ƺ��1�ĸ���Ϊ0����1���� ��ô����������&1 ���Եõ�β���Ƿ�Ϊ1

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

bool isPowerOfTwo(int n){
    if( n < 0) return false;
    bool hasone = false;
    while (n > 0){
        if (n & 1){         //���ֶ��������1λΪ1
            if (hasone) return false; //�Ѿ�����1λ
            else hasone = true;
        }
        n >>=1;  //����n����1λ
    }
    return hasone;
    //return true;   //error ��Ϊ��n==0ʱ��Ҫ����false
}

int main(){
    cout<< isPowerOfTwo(100) <<endl;
    return 0;
}
