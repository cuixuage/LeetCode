/*
对于重复内容的文件+目录输出
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  *********注意目录拼接
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
*/

//这种寻找内容重复的方法  —————— hashmap
//实际生产中又如何处理呢？
//思路: hashmap 文件内容作为key 文件位置作为val——vector<string>保存
//难点: 切割字符串

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
        while(getline(ss,s,' ')){ //当前root后面所有文件
            string fileName = root+'/'+s.substr(0,s.find('('));
            string content = s.substr(s.find('(')+1,
                                      s.find(')')-s.find('(')-1);
            //map
            files[content].push_back(fileName);
        }
    }
    for(auto file:files){
        if(file.second.size()>1) {  //文件content重复 输出其路径
            //cout<<file.second.size()<<endl;
            result.push_back(file.second);    // vector<vector<string>>
        }
    }
    return result;
}

//********测试
int main(){
    vector<string> paths;
    paths.reserve(32);
    paths.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
    paths.push_back("root/c 3.txt(abcd)");
    paths.push_back("root/c/d 4.txt(efgh)");
    paths.push_back("root 4.txt(efgh)");
                                                //注意vector作为参数 引用&传递效率高
    vector<vector<string>> result = findDuplicate(paths);

    for(const auto &i:result){                   //vector遍历 使用 const &遍历每一个元素效率更高
        for(const auto &j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}

/******************
unordered map 实例
    // Iterate and print keys and values of unordered_map
    for( const auto& n : u ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
******************/
