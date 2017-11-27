/*��̬�滮
S = "rabbbit"��T ="rabbit"
S���е����ַ��� �ж��ٺ�T�ַ�����ͬ*/

/*
  S 0123....j
T +----------+
  |1111111111|
0 |0         |
1 |0         |
2 |0         |
. |0         |
. |0         |
i |0         |
���S�еĵ�ǰ�ַ������ڵ�ǰ�ַ�T����ô���Ǿ�����û�����ַ�ʱ��ͬ�����Ĳ�ͬ�����С�
���S�еĵ�ǰ�ַ����ڵ�ǰ�ַ�T����ô��ͬ�����������У�����֮ǰ�����е������������������еĲ�ͬ�����������У�����T���٣�S��С��
*/
//��Ȼ���Ǻ����

#include"func.h"
int numDistinct(string S, string T) {
    // ��ʼ��
    int mem[T.length()+1][S.length()+1];         //T���ַ���Ϊ��
   // bzero(mem,(S.length()-1)*(T.length()-1)*sizeof(int));
    memset(mem,0,(S.length()+1)*(T.length()+1)*sizeof(int));
    for(int j=0; j<=S.length(); j++) {
        mem[0][j] = 1;
    }

    //����T��ÿһ���ַ� ȥ��ѯS�������ַ�
    for(int i=0; i<T.length(); i++) {
        for(int j=0; j<S.length(); j++) {
            if(T.at(i) == S.at(j)) {
                //����������
                mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
            } else {
                //S�����ַ��͵�ǰT�ַ�����ͬ ;ans��ͬ����δ�������ַ���ֵ
                mem[i+1][j+1] = mem[i+1][j];
            }
        }
    }

    return mem[T.length()][S.length()];
}


int main(){
    string s="rabbbit";
    string t="rabbit";
    cout<<numDistinct(s,t)<<endl;
    return 0;
}
