#include "func.h"
/*
前缀树的实现  (多叉树 + root到节点为一个单词)
节点: 标识isword,当isword==true时,从根节点到当前节点才为一个单词

e.g 多叉树每每一层26个字母,从左到右字典序
*/
class TrieNode{
public:
    TrieNode* next[26];
    bool is_word;
    TrieNode(bool is_word_):is_word(is_word_){std::memset(next,0,sizeof(next));}
    TrieNode():is_word(false){std::memset(next,0,sizeof(next));}
};

class Trie{
    TrieNode* root; //默认是私有变量 private
public:
    Trie(){
        root =  new TrieNode();
    }
    //插入单词
    void insert(string s){
        TrieNode* p = root;
        for(int i=0;i<s.size();++i){
            if(p->next[s[i] - 'a'] == NULL)
                p->next[s[i] - 'a'] = new TrieNode();
            p = p->next[s[i] - 'a'];
        }
        p->is_word = true;      
    }
    //单词查找
    bool search(string key){
        TrieNode* p = find(key);
        return p!=NULL && p->is_word;
    }
    //查找trie()树种是否存在以prefix起始的单词
    bool startsWith(string prefix){
        return find(prefix) != NULL;
    }

private:
    //查找单词是否存在于trie中
    TrieNode* find(string key){
        TrieNode* p = root;
        for(int i=0; i<key.size() && p!=NULL; ++i)
            p = p->next[key[i] - 'a'];
        return p;
    }
};