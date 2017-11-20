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
        //后面这两句很关键，如无，则会又交换一次导致恢复原样,导致死循环
        i++;
        j--;
    }
    //      cout<<s<<endl;
    return s;
}
/*
//383题
//好像有道类似的题目 区分连续的子串 和 非连续子串问题
    bool canConstruct(string ransomNote, string magazine) {
    string::size_type position;
    for(int i=0;i<ransomNote.length();i++){
        //magazine中字符可以是非连续的形式包含ransomNote  所以需要对于ransomNote逐个字符判断是否被包含
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
