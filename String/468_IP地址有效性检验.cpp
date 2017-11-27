/*判断IPV4 IPV6的有效性*/

#include "func.h"
const string validIPv6Chars = "012345678abcdefABCDEF";

bool isvaildIPv4token(string& block){
    int num=0;
    if(block.size()>0 && block.size()<=3){
        for(int i=0;i<block.size();i++){
            char c = block[i];
            //判断每一小段是否不大于255 且没有前导0 且为数字
            if(!isdigit(c) || (i==0 && c=='0' && block.size()>1))
                return false;
            else{
                //计算每一段token的值
                //study:从高位到低位 不断计算十进制的和
                num *=10;
                num += c-'0';
            }
        }
        return num<=255?1:0;
    }
    return false;
}

bool isvaildIPv6token(string& block){
    //block size<=4 共5位
    if(block.size()>0 && block.size()<=4){
        for(int i=0;i<block.size();i++){
            char c = block[i];
            //定义字符串
            if(validIPv6Chars.find(c) == string::npos) return false;
        }
        return true;
    }
    return false;
}

string validIPAddress(string IP){
    string ans[3]={"IPv4","IPv6","Neither"};
    stringstream ss(IP);
    string block;
    //ipv4 IP每次截取后都会变短
    if(IP.substr(0,4).find('.')!=string::npos){
        for(int i=0;i<4;i++){
            if(!getline(ss,block,'.') || !isvaildIPv4token(block))
                return ans[2];
        }
        return ss.eof()?ans[0]:ans[2];
    }
    //IPV6
    else if(IP.substr(0,5).find(':')!=string::npos){
        for(int i=0;i<8;i++){
            if(!getline(ss,block,':') || !isvaildIPv6token(block))
                return ans[2];
        }
        return ss.eof()?ans[1]:ans[2];
    }
    return ans[2];
}

int main(){
    string s1="255.255.255.255";
    string s2="2001:0db8:85a3:0:0:8A2E:0370:7334";
    string s3="256.256.256.256";
    cout<<vaildIPAdress(s1)<<endl;
    cout<<vaildIPAdress(s2)<<endl;
    cout<<vaildIPAdress(s3)<<endl;
}
