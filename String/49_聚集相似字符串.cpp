/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
˼��:
���ֻ���ش������յ��أ�
[
  ["ate", "eat","tea"],
  ["nat","tan"],
]
Note: All inputs will be in lower-case.
*/

//N*logN
//����1: sort_����ÿһ��string�����ڲ��ַ�������Ϊkey ,��key��ͬ�ļ��뵽ͬһ��map<key,vector<string>>��
//N*K
//����2: hash ����ÿ��string,���ַ����ֵĴ�����Ϊkey ����:"aaa"=="300000....(26����ĸ)"

#include "func.h"

vector<vector<string>> groupAngrams(vector<string>& strs){
    unordered_map<string,multiset<string> >mp;
    for(auto s : strs){
        string t=s;
        std::sort(t.begin(),t.end());
        mp[t].insert(s);                //multiset insert
    }
    //��map.second����ȡ������
    vector<vector<string>> anagrams;
    for(auto m : mp){
        vector<string> anagram(m.second.begin(),m.second.end());   //iterator����vector�ĳ�ʼ��
        anagrams.push_back(anagram);                            //��ά����
    }
    /*
            //ֻ������multiset > 1��string
     	vector<string> ans;
     	for(auto i : anagrams){
            if(i.size()>1){
                for(auto j : i)
                ans.push_back(j);
     		}
        }
    */
    return anagrams;
}


int main(){
    vector<string> strs;
    strs.reserve(32);
//    strs.push_back("eat");
//    strs.push_back("tea");
//    strs.push_back("tan");
//    strs.push_back("ate");
//    strs.push_back("nat");
//    strs.push_back("bat");
    strs.push_back("a");
    vector<vector<string>> ans = groupAngrams(strs);
    for(auto i : ans){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
