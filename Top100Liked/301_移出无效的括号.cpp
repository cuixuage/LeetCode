#include "func.h"
/*
BFS 如何理解？
*/
void remove(string s,vector<string>& ans, int last_i, int last_j, vector<char> par){
    for(int stack=0,i=last_i;i<s.length(); ++i){
        if(s[i] == par[0]) stack++;
        if(s[i] == par[1]) stack--;
        if(stack >= 0) continue;
        for(int j = last_j; j<=i; ++j){
            if(s[j] == par[1] && (j==last_j || s[j-1] != par[1]))
                remove(s.substr(0,j) + s.substr(j+1,s.length()-j-1), ans,i,j,par);
        }
        return;
    }    
    string s_tmp = s;
    std::reverse(s_tmp.begin(),s_tmp.end());
    if(par[0] == '(')   remove(s_tmp,ans,0,0,vector<char>{')','('});
    else ans.push_back(s_tmp);
}

vector<string> removeInvalidParentheses(string s){
    vector<string> ans;
    vector<char> par = {'(',')'};
    remove(s,ans,0,0,par);
    return ans;
}