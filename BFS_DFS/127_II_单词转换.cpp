//经典的BFS结构


//最短路径  ==》  BFS
//queue每一层代表一个字符的转换
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //unorder_set 初始化
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        //wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);         //相差一个字符的所有可能
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {     //关键:  只将当前层级遍历,没找到: 意味着需要两步转换
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
private:
    //wordDict erase删除元素  相当于标记已遍历  不要重复寻找
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        //寻找和word只相差一个字符的单词
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
