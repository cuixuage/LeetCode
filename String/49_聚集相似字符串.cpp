/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
思考:
如果只返回存在字谜的呢？
[
  ["ate", "eat","tea"],
  ["nat","tan"],
]
Note: All inputs will be in lower-case.
*/

//N*logN
//方案1: sort_对于每一个string将自内部字符排序作为key ,将key相同的加入到同一个map<key,vector<string>>中
//N*K
//方案2: hash 按照每个string,其字符出现的次数作为key 例如:"aaa"=="300000....(26个字母)"

#include "func.h"

vector<vector<string>> groupAngrams(vector<string>& strs){
    unordered_map<string,multiset<string> >mp;
    for(auto s : strs){
        string t=s;
        std::sort(t.begin(),t.end());
        mp[t].insert(s);                //multiset insert
    }
    //将map.second单独取出保存
    vector<vector<string>> anagrams;
    for(auto m : mp){
        vector<string> anagram(m.second.begin(),m.second.end());   //iterator对于vector的初始化
        anagrams.push_back(anagram);                            //二维数组
    }
    /*
            //只保存了multiset > 1的string
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
