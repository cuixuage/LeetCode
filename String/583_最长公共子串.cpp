/*
Ѱ����С��ɾ������,ʹ��s1,s2ʣ���ַ���ͬ  =�� Ѱ���(���Բ�������)�����Ӵ�
=> ��̬�滮
*/

#include "func.h"
int minDistance(string s1, string s2){
    int l1=s1.length();
    int l2=s2.length();
    int dp[l1+1][l2+1];     //string.length()+1��
    memset(dp,0,sizeof(dp));

    for (int i = 1; i <= l1; i++){
        for (int j = 1; j <= l2; j++){
            //s1[0]s2[0] �洢�� dp[1][1]
            if (s1.at(i-1) == s2.at(j-1))
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //ע��dpλ��:  �ַ��������һλҪ���ǽ�ȥ�������洢��dp[s.length]
    return s1.length() + s2.length() - 2 * dp[s1.length()][s2.length()];
}

//***************����
int main(){
    string s1="sea";
    string s2="eat";
    cout<<minDistance(s1,s2)<<endl;
    return 0;
}
