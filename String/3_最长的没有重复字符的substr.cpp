/*
���û���ظ��ַ���substring
ע: substring(��ȡ�������ַ�)����sequence(������)
*/

//����: ����ÿһ���ַ�Ϊ��β��max substr,����Щsubstr����Ѱ������
//˼��: i����ָ�� jָ�����������ַ�

//��������:
//ʹ��һ����ϣ��������Ĳ��ظ���substr,ʹ��һ�����ٵ�ָ��j���鿴�Ƿ��ַ�j�Ƿ��ڹ�ϣ����
//������ڣ��ܺã�������ӵ���ϣ�����ƶ�jת����������󳤶ȣ�
//����ʹ������ָ��i��ͷ��ɾ����ֱ�����ǿ��Խ��ַ�j���ڹ�ϣ����

//�е㶯̬�滮��˼��

#include "func.h"
//*******************************************����1
/*
//ΪʲôҲ��ͨ���أ�   set�����������˳�����򰡣���
//hash set�����ռ䲻��std  �����������
int lengthLongestSubstring(string s){
    int i=0,j=0,maxlen=0;
    set<char> myset;
    while(j<s.length()){
        if(!myset.count(s.at(j))){
            myset.insert(s.at(j++));
            maxlen=std::max(maxlen,(int)myset.size());  //����max(maxlen,j-i)
        }
        else{
            //�������� ����ɾ����ʼ�ַ�ֱ���µ�j�ַ��ܹ�����set
           myset.erase(s.at(i++));
        }
    }
    return maxlen;
}
*/

//******************************����2
int lengthLongestSubstring(string s) {
    if (s.length()==0) return 0;
    map<char,int> mymap;
    int maxlen=0;
    //j����ָ��,�൱��start
    for (int i=0, j=0; i<s.length(); ++i){
        if (mymap.count(s.at(i))){
            //������iΪ��β��substr�Ĳ��ظ�substr��startλ��
            //mymap���ַ� λ�õ�ӳ�� ��i���ظ��ַ�����һ��λ��
            j = std::max(j,mymap[s.at(i)]+1);
        }

        //�����µ��ַ�
        //�����ַ���????
        //mymap.insert(std::make_pair(s.at(i),i));   //����Ϊʲô��ʹ��maxlen�𰸲��ԣ�
        //mymap.insert(std::pair<char,int>(s.at(i),i));
        mymap[s.at(i)]=i;
        //�������len
        maxlen = std::max(maxlen,i-j+1);
    }
//    for(auto i: mymap)
//        cout<<i.first<<":"<<i.second<<endl;
    return maxlen;
}
int main(){
    string test="abcabcbb";
    cout<<lengthLongestSubstring(test)<<endl;
    return 0;
}
