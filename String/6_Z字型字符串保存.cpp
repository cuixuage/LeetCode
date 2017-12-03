/*n=numRows
��=2n-2    1                           2n-1                         4n-3
��=        2                     2n-2  2n                    4n-4   4n-2
��=        3               2n-3        2n+1              4n-5       .
��=        .           .               .               .            .
��=        .       n+2                 .           3n               .
��=        n-1 n+1                     3n-3    3n-1                 5n-5
��=2n-2    n                           3n-2                         5n-4

���밴��Z����;���ʱ�������
˼·: vector<vector<int>>  ������������
*/

#include "func.h"
string convert(string s,int rows){
    string temp = s;
    int len = temp.length();
    vector<string> str(rows,"");            //��ʼ���ܹؼ� ��Ȼ����vector�޷�ֱ��ʹ������
    //str.reserve(rows);
    int i=0;
    while(i<len){
        for (int idx=0;idx<rows&&i<len;idx++)   //��ֱ˳��
            str[idx] += temp.at(i++);   //i++ ��Ӽ�
        for (int idx=rows-2;idx>=1&&i<len;idx--) //Z б�ŵĵ�����
            str[idx] += temp.at(i++);
    }
    string ans="";
    for(auto sb:str)
        ans +=sb;
    return ans;
}

int main(){
    string test="PAYPALISHIRING";
    cout<<convert(test,3)<<endl;
    return 0;
}
