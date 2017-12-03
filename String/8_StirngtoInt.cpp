/*string 转化为 int
我想我们只需要处理四种情况：
1.丢弃所有领先的空格
2.号码的标志
3.溢出
4.输入无效
*/

#include "func.h"
int atoi(const char *str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }                      //1.丢弃所有领先的空格
    if (str[i] == '-' || str[i] == '+') {               //2.号码的标志
        sign = 1 - 2 * (str[i++] == '-');               //++是后加加
    }
    while (str[i] >= '0' && str[i] <= '9') {
            //3.溢出 INT_MAX个位数是7
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
    cout<<binary.length()<<endl;         //INT_MAX 是31位(加一位符号位,则正好4bytes)
}

int main(){
    string str="+10000";
    cout<<atoi(str.c_str())<<endl;
    return 0;
}
