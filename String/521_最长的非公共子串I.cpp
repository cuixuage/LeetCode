/*
˼�� abc abd����ǹ����Ӵ������� 'c'or'd'  ����  'abc'or'abd'
������Ϊ �������ǰ���ԭ���е�

˼��:ԭ�ַ�����ȥ������ַ����Ľ�������ֿ����Ƿ����֣�

a=b. If both the strings are identical, it is obvious that no subsequence will be uncommon. Hence, return -1.

length(a)=length(b)length(a)=length(b) and a \ne ba��b. Example: abcabc and abdabd. In this case we can consider any string i.e. abcabc or abdabd as a required subsequence, as out of these two strings one string will never be a subsequence of other string. Hence, return length(a)length(a) or length(b)length(b).

length(a) \ne length(b)length(a)��length(b). Example abcdabcd and abcabc. In this case we can consider bigger string as a required subsequence because bigger string can't be a subsequence of smaller string. Hence, return max(length(a),length(b))max(length(a),length(b)).
*/

#include"func.h"
int findLUSlength(string a, string b) {
    if(a==b) return -1;   //˼��:ֻ����ȫ��ͬʱ ����ʹ��contains��(ֻ���ж��Ƿ����)
    else
        return std::max(a.length(),b.length());
}

int main(){
    string str1="abc";
    string str2="abd";
    cout<<findLUSlength(str1,str2);
    return 0;
}
