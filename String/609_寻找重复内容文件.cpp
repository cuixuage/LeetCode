/*
�����ظ����ݵ��ļ�+Ŀ¼���
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  *********ע��Ŀ¼ƴ��
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
*/

//����Ѱ�������ظ��ķ���  ������������ hashmap
//ʵ������������δ����أ�
//˼·: hashmap �ļ�������Ϊkey �ļ�λ����Ϊval����vector<string>����
//�ѵ�: �и��ַ���

#include<string.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::unordered_map;
vector<vector<string>> findDuplicate(vector<string> &paths){
    unordered_map<string,vector<string>> files;
    vector<vector<string>> result;

    for(auto path:paths){
        stringstream ss(path);
        string root;
        string s;
        getline(ss,root,' ');
        while(getline(ss,s,' ')){ //��ǰroot���������ļ�
            string fileName = root+'/'+s.substr(0,s.find('('));
            string content = s.substr(s.find('(')+1,
                                      s.find(')')-s.find('(')-1);
            //map
            files[content].push_back(fileName);
        }
    }
    for(auto file:files){
        if(file.second.size()>1) {  //�ļ�content�ظ� �����·��
            //cout<<file.second.size()<<endl;
            result.push_back(file.second);    // vector<vector<string>>
        }
    }
    return result;
}

//********����
int main(){
    vector<string> paths;
    paths.reserve(32);
    paths.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
    paths.push_back("root/c 3.txt(abcd)");
    paths.push_back("root/c/d 4.txt(efgh)");
    paths.push_back("root 4.txt(efgh)");
                                                //ע��vector��Ϊ���� ����&����Ч�ʸ�
    vector<vector<string>> result = findDuplicate(paths);

    for(const auto &i:result){                   //vector���� ʹ�� const &����ÿһ��Ԫ��Ч�ʸ���
        for(const auto &j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/******************
unordered map ʵ��
    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
******************/
