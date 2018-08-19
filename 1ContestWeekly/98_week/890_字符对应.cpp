#include "func.h"
//Accept
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    for(auto word:words){
        if(word.size()!=pattern.size()) continue;
        unordered_map<char,char> token;
        unordered_map<char,bool> word_map;
        bool add = true;

        for(int i=0;i<word.size();i++){
            //pattern no map_value && word_element ֮ǰ��û�б�ӳ���
            if(token.find(pattern[i])==token.end() && word_map.find(word[i]) == word_map.end()){
                token[pattern[i]] = word[i];
                word_map[word[i]] = true;
            }else{
                //e.g ["ccc"] c�տ�ʼӳ��� ��˴�'b', add=false
                if(token[pattern[i]] != word[i]){
                    add = false;
                    break;
                }
            }
        }
        if(add==true) res.push_back(word);
    }
    return res;
}
