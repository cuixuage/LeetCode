/*
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
//关键思想: 按照/切割字符串

#include"func.h"
string simplifyPath(string path)
{
    stringstream ss(path);
    string temp;
    vector<string> file_name;    //vector deque
    //注意这里使用的是 else if
    while(getline(ss,temp,'/'))
    {
        if(temp=="." || temp=="") continue;
        else if(temp==".." && !file_name.empty() ) file_name.pop_back();
        else if(temp != "..") file_name.push_back(temp);             //如果无temp!=..判断语句 思考 "/.."示例 结果仍会输出"/.."
    }

    string res="";
    for(auto str : file_name) res += "/"+str;
    return res.empty() ? "/" : res;

}


int main(){
    string s ="/a/./b/../../c/";
    cout<<simplifyPath(s)<<endl;
    return 0;
}
