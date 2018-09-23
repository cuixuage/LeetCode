/*

寻找beginWord~endWord所有最短的变换序列

如果没有这样的转换序列，则返回空列表。
所有单词都有相同的长度。
所有单词仅包含小写字母字符。
您可以假设单词列表中没有重复项。
您可以假设beginWord和endWord是非空的并且不相同。
*/

//BFS   不过感觉理解的不深入 + 回来再看

vecttor<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordlist){
    vector<vector<string>> ans;
    queue<vector<string>> paths;
    
        //vector用来初始化unordered_set
    unordered_set<string> wordList(wordlist.begin(), wordlist.end());
    //wordList.insert(endWord);             //注意注释掉
    paths.push({beginWord});
    int level = 1;
    int minLevel = INT_MAX;
    std::unordered_set<string> visited;
    
    while(!paths.empty()){
        vector<string> path = paths.front();
        paths.pop();
        if(path.size() > level){
            //reach a new minLevel
            for(string w : visited)         //wordlist删除已遍历的element
                wordList.erase(w);
            visited.clear();
            if(path.size() > minLevel)
                break;
            else
                level = path.size();
        }
        
        string last = path.back();
        for(int i=0; i<last.size();i++){
            string news = last;
            for(char c='a'; c<='z';++c){
                news[i] = c;
                if(wordList.find(news) != wordList.end()){
                    vector<string> newpath = path;
                    newpath.push_back(news);
                    visited.insert(news);
                    if(news == endWord){
                        minLevel = level;
                        ans.push_back(newpath);
                    }else
                        paths.push(newpath);
                }
            } 
        }
    }
    //返回空的vector
    // if(ans[0].back() == endWord) //return {};   
    //     return {{}};
    return ans;
}
