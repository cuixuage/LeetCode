//leetcode 127 https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS

//�����������ʣ�beginWord��endWord����һ���ֵ�ĵ����б��ҵ���beginWord��endWord�����ת�����еĳ��ȣ����磺
//һ��ֻ�ܸ���һ����ĸ��
//ÿ��ת���ĵ��ʱ�������ڵ����б��С���Ҫע�����beginWord�ǲ��Ǳ任�ʡ�

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::vector;
void addNextWords(string ,vector<string>& ,queue<string>& );


//��ϸ���BFS��˼��
//ÿһ���������һ�㶼ֻ���һ���ַ�
//ÿһ���queue����θ���unorderset��������ģ���
//**********��ʱ   ��vector����unordered_setӦ�ÿ��Կ첻��
int ladderLength(string beginword, string endword, vector<string>& worddict){
    //worddict.push_back(endword);
    queue<string> tovisit;
    addNextWords(beginword,worddict,tovisit);               //��ʼ��tovisit ֻ�����beginword���һ���ַ��ĵ���
    int dist = 2;
    while(!tovisit.empty()){
        int num = tovisit.size();
        for(int i=0;i<num;i++){
            string word = tovisit.front();
            tovisit.pop();
            if(word == endword) return dist;                //BFS ͬһ�㼶���������ͬ�� return distҲ��������̵�
            addNextWords(word,worddict,tovisit);            //����word���ʵ���һ���㼶��queue
        }
        dist++;
    }
    return 0;
}

//word == tovisit.front()
//��worddict��Ѱ�������word�ָı���һ���ַ��ĵ���
void addNextWords(string word,vector<string>& wordDict,queue<string>& toVisit){
    wordDict.erase(std::remove(wordDict.begin(), wordDict.end(), word), wordDict.end());
    for(int p=0;p<(int)word.length();p++){
        char letter = word[p];
        for(int k=0;k<26;k++){
            word[p] = 'a' + k;
            if(std::find(wordDict.begin(),wordDict.end(),word) != wordDict.end()){
                toVisit.push(word);
                wordDict.erase(std::remove(wordDict.begin(), wordDict.end(), word), wordDict.end());            //ɾ����ʹ�ù���word
            }
        }
        word[p] = letter;
    }
}

int main(int argc,char**argv){
    string beginword = "hit";
    string endword = "cog";
    vector<string> wordDict = {"hot", "dot", "dog", "lot", "log","cog"};
    cout<< ladderLength(beginword,endword,wordDict) <<endl;
    return 0;

}


//����ÿ��ֻ�ܸ���һ����ĸ��������Ǵ�һ��ʼ"hit"������ֻ�ܸ���Ϊ��Щֻ��һ����ĸ�ĵ��ʣ�����"hot"����ͼ�۵ķ�ʽ��˵�����ǿ���˵��"hot"��һ���ھ�"hit"��
//����뷨�ܼ򵥣���������start�����ھӣ�Ȼ��ݷ����ھӵ�δ�����ھ�......�ţ���ֻ�ǵ��͵�BFS�ṹ��
//
//Ϊ�˼����⣬���ǲ���end��dict��
//����distΪ�任�ĵ�ǰ���뱣��һ����������dist++�����һ��BFS��������ע�⣬��Ӧ�÷������������о���Ķ��壩����и��¡�
//���⣬Ϊ�����η���ĳ�����ʣ����ǻ��ڷ��ʸõ���dict����ɾ��



//
//
//public:
// int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
//        wordDict.insert(endWord);
//        queue<string> toVisit;
//        addNextWords(beginWord, wordDict, toVisit);
//        int dist = 2;
//        while (!toVisit.empty()) {
//            int num = toVisit.size();
//            for (int i = 0; i < num; i++) {
//                string word = toVisit.front();
//                toVisit.pop();
//                if (word == endWord) return dist;
//                addNextWords(word, wordDict, toVisit);
//            }
//            dist++;
//        }
//     return 0;
//    }
//private:
//    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
//        wordDict.erase(word);
//        for (int p = 0; p < (int)word.length(); p++) {
//            char letter = word[p];
//            for (int k = 0; k < 26; k++) {
//                word[p] = 'a' + k;
//                if (wordDict.find(word) != wordDict.end()) {
//                    toVisit.push(word);
//                    wordDict.erase(word);
//                }
//            }
//            word[p] = letter;
//        }
//    }
