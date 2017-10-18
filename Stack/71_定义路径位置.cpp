/*
���� '/' �и��ַ���  ˼��:Ϊʲô�� Ŀ�ĵõ� . && .. && file

(better)����1:stringstream + getline(ss,temp,'\')
����2:find + substr(start,begin)
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
        else if(temp != "..") file_name.push_back(temp);             //�����temp==0�ж���� ˼�� "/.."ʾ�� ����Ի����"/.."
    }
    string res="";
    for(auto str : file_name) res += "/"+str;
    return res.empty() ? "/" : res;                //��·������ /
}

//*************************����
int main(int argc,char** argv){
    string path="/a/./b/../../c/b";
    cout<<simplifyPath(path)<<endl;
    return 0;
}
