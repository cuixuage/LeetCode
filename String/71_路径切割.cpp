/*
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/
//�ؼ�˼��: ����/�и��ַ���

#include"func.h"
string simplifyPath(string path)
{
    stringstream ss(path);
    string temp;
    vector<string> file_name;    //vector deque
    //ע������ʹ�õ��� else if
    while(getline(ss,temp,'/'))
    {
        if(temp=="." || temp=="") continue;
        else if(temp==".." && !file_name.empty() ) file_name.pop_back();
        else if(temp != "..") file_name.push_back(temp);             //�����temp!=..�ж���� ˼�� "/.."ʾ�� ����Ի����"/.."
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
