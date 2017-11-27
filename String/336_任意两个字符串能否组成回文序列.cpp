

#include "func.h"


bool isPalindrome(string str){
    int i = 0;
    int j = str.size() - 1;
    while(i < j){
        if(str[i++] != str[j--]) return false;
    }
    return true;
}
/*
vector<vector<int>> palindromePairs(vector<string>& words){
    vector<vector<int>> ans;
    string temp;
    for(int str1=0;str1!=words.size();str1++){
        for(int str2=0;str2!=words.size();str2++){
            if(str1 != str2){
                temp="";
                temp += words[str1] + words[str2];
                //cout<<temp<<endl;
                if(isPalindrome(temp))
                    ans.push_back({str1,str2});
            }
        }
    }
    return ans;
}
*/

//˼��:https://leetcode.com/problems/palindrome-pairs/discuss/
//���ᳬʱ  ʱ�临�Ӷ�n*k*k
vector<vector<int>> palindromePairs(vector<string>& words)
{
    unordered_map<string, int> dict;
    vector<vector<int>> ans;
    // build dictionary
    //������wordsת�ú󱣴浽dict�� ��Ϊ�����������
    for(int i = 0; i < words.size(); i++)
    {
        string key = words[i];
        reverse(key.begin(), key.end());
        dict[key] = i;
    }
    // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
    if(dict.find("")!=dict.end())
    {
        for(int i = 0; i < words.size(); i++)
        {
            if(i == dict[""]) continue;
            if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
        }
    }

    for(int i = 0; i < words.size(); i++)
    {   //����ÿһ��words�ֳ�����������
        for(int j = 0; j < words[i].size(); j++)
        {
            string left = words[i].substr(0, j);
            string right = words[i].substr(j, words[i].size() - j);
            //���ǻ���˳����Ұ벿����Ϊ"�м�"  left+dict[left]������������
            if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
            {
                ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
            }

            if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
            {
                ans.push_back({dict[right], i});
            }
        }
    }

    return ans;
}


int main()
{
    vector<string> words;
    words.push_back("bat");
    words.push_back("tab");
    words.push_back("cat");
    vector<vector<int>> ans =palindromePairs(words);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
    }
    return 0;
}
