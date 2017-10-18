/*
按照 '/' 切割字符串  思考:为什么？ 目的得到 . && .. && file

(better)方法1:stringstream + getline(ss,temp,'\')
方法2:find + substr(start,begin)
*/
#include<iostream>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::stringstream;
using std::vector;
string simplifyPath(string path){
    stringstream ss(path);
    string temp;
    vector<string> file_name;    //vector deque
    while(getline(ss,temp,'/')){
        if(temp=="." || temp=="") continue;
        else if(temp==".." && !file_name.empty() ) file_name.pop_back();
        else if(temp != "..") file_name.push_back(temp);             //如果无temp==0判断语句 思考 "/.."示例 结果仍会输出"/.."
    }
    string res="";
    for(auto str : file_name) res += "/"+str;
    return res.empty() ? "/" : res;                //空路径返回 /
}

//*************************测试
int main(int argc,char** argv){
    string path="/a/./b/../../c/b";
    cout<<simplifyPath(path)<<endl;
    return 0;
}
