/*
分割子串
使得子串全部是回文字符串,一共有多少种分割形式？
*/

class Solution{
public:
    vector<vector<string>> partition(string S){
        vector<vector<string>> ret;
        if(S.empty()) return ret;
        vector<string> path;
        dfs(0,S,path,ret);
        return ret;
    }
private:
//思路1: 拿到所有子集元素; 再挑选出符合回文的结果
    void dfs(int index,string& s,vector<string>& path,vector<vector<string>>& ret){
        if(index ==s.size()){
            ret.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                dfs(i+1,s,path,ret);
                path.pop_back();        //FIXME: 回溯
            }
        }
    }
    bool isPalindrome(const string& s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--])
            return false;
        }
        return true;
    }
}
