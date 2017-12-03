/*string ת��Ϊ int
��������ֻ��Ҫ�������������
1.�����������ȵĿո�
2.����ı�־
3.���
4.������Ч
*/

#include "func.h"
int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }                      //1.�����������ȵĿո�
    if (str[i] == '-' || str[i] == '+') {               //2.����ı�־
        sign = 1 - 2 * (str[i++] == '-');               //++�Ǻ�Ӽ�
    }
    while (str[i] >= '0' && str[i] <= '9') {
            //3.��� INT_MAX��λ����7
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}
void test0(){
//****************************INT_MAX
    string binary;
    int temp = INT_MAX;
    do{
        int k = temp%2;
        temp /=2;
        binary += k +'0';
    }while(temp!=0);
    std::reverse(binary.begin(),binary.end());

    printf("%X\n",INT_MAX);   //2147483647  7fffffff
    cout<<binary.length()<<endl;         //INT_MAX ��31λ(��һλ����λ,������4bytes)
}

int main(){
    string str="+10000";
    cout<<atoi(str.c_str())<<endl;
    return 0;
}
