/*
ʹ�ø������ֵ�digit  �ҵ����д��ڵ�ǰ��������С��һ��  �����������-1
����: 534976 => 536 479
*/
//˼��: ֻ�е�����������digit��������ʱ����-1
/*
I�������ұߵ����ֱ������������֣�����������ֱ���ҵ�һ��С����ǰ���������ֵ����֡����磬�����������ǡ�534976��������ͣ��4����Ϊ4С����һ������9.�������û���ҵ�����һ�����֣���ô����ǡ������ܵġ���

II�������������ҵ�������'d'���Ҳ���������'d'����С���֡����ڡ�53 4 976����4���ұ߰�����976��������4����С������6��

III�����������ҵ�����λ���֣�����������������еõ�53 6 97 4��

�ģ���������ӡ�d���Աߵ�λ�õ����ֵĽ�β���������֡������������õ������־��������������������ӣ������ô���536 974�����ֽ����������ǵõ���536 479 ������������534976����һ�����������
*/

//��̰�ĵ�˼��  ���ҵ���Ѱ�ҵ�һ�������Ԫ�ؼ�Ϊ��������Ԫ��(�����������Ԫ������С����һ��)
#include"func.h"

int nextGreatElement(int n){
    stringstream ss;
    ss<<n;
    string str = ss.str();
    int i,j;
    //i��¼���ҵ����һ���ݼ�Ԫ�ص���Ҫ��������Ԫ�� j��¼iλ�ú�����СԪ�ص�λ��
    //˼��: ����Ѱ�ҵ�һ�����������  ����������Ѱ�ҵ�һ������(�޷���֤�������С)
    for(i=str.length()-1;i>0;i--)
        if(str[i-1] < str[i]) break;
    //���ҵ���������� i==1������ i=0 break
    if(i==0) return -1;

    int x=str[i-1];   //[i-1] < [i]
    int smallest=i;
    for(j=i+1;j<str.length();j++)
    //*********���������ز�����  ����Ԫ�ش���x ���ǵ�����С���Ҳ����һ��
        if(str[j] > x && str[j] <= str[smallest])
            smallest = j;
    //**III swap
    std::swap(str[i-1],str[smallest]);

    //**IV  sort after(i-1)
    std::sort(str.begin()+i,str.end());
    long val = std::atol(str.c_str());

    return (val <= INT_MAX) ? (int) val : -1;;
}
//*************************
int main(){
    int a = 534976;
    cout<<nextGreatElement(a)<<endl;
    return 0;
}

/*
1.int 2 string (use stringstream)
    stringstream ss;
    ss<<n;
    string str ;  //str=ss.str();
    ss>>str;

2.sort + compare
    // sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {
            return a < b;
        }
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    for (auto a : s) {
        std::cout << a << " ";
    }
*/
