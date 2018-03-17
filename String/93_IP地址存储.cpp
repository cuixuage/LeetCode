//Given "25525511135",
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

//3ѭ�����ַ���s�ֳ�4�����ַ�����s1��s2��s3��s4�����ÿ�����ַ����Ƿ���Ч
//��isValid�У����ȴ���3�����0���ַ�����Ч; ��������ַ����ĳ��ȴ���1���ҵ�һ����ĸ��'0'����ô������Ч��; ������������ʾ����255���ַ�����Ч

bool isvalid (string );
vector<string> restoreIpAddress(string s){
    vector<string> res;
    int len = s.length();
    for(int i=1;i<4&&i<len-2;i++){
        for(int j=i+1;j<i+4&&j<len-1;j++){
            for(int k=j+1;k<j+4&&k<len;k++){
                string s1 = s.substr(0,i);
                string s2 = s.substr(i,j-i);
                string s3 = s.substr(j,k-j);
                string s4 = s.substr(k,len-k);
                if (isvalid(s1) && isvalid(s2) && isvalid(s3) && isvalid(s4))
                    res.push_back(s1+"."+s2+"."+s3+"."+s4);
            }
        }
    }
    return res;
}

bool isvalid (string s){
    if(s.length() > 3 || s.length() == 0 ||
       ( s[0]=='0' && s.length()>1 )  || atoi(s.c_str())>255)
            return false;
    else
        return true;
}

int main(int argc,char** argv){
    vector<string> ans = restoreIpAddress("255255255255");
    for( auto tmp : ans)
        cout<<tmp<<endl;
    return 0;
}
