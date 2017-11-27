/*
Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/

#include "func.h"
string reverseVowels(string s)
{
    int i=0;
    int j=s.size()-1;
    static string vowels="aeiouAEIOU";
    while(i<j)
    {
        while((vowels.find(s[i])==string::npos)&&(i<j)) i++;
        while((vowels.find(s[j])==string::npos)&&(i<j)) j--;
        if(i<j) std::swap(s[i],s[j]);
        //����������ܹؼ������ޣ�����ֽ���һ�ε��»ָ�ԭ��,������ѭ��
        i++;
        j--;
    }
    //      cout<<s<<endl;
    return s;
}
/*
//383��
//�����е����Ƶ���Ŀ �����������Ӵ� �� �������Ӵ�����
    bool canConstruct(string ransomNote, string magazine) {
    string::size_type position;
    for(int i=0;i<ransomNote.length();i++){
        //magazine���ַ������Ƿ���������ʽ����ransomNote  ������Ҫ����ransomNote����ַ��ж��Ƿ񱻰���
        position=magazine.find(ransomNote[i]);
        if(position==string::npos) return false;
        else {
            magazine.erase(position,1);
        }
    }
    return true;
    }
*/

int main(){
    string temp = "leetcode";
    cout<<reverseVowels(temp)<<endl;
    return 0;
}
