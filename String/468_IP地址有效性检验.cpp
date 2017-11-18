/*�ж�IPV4 IPV6����Ч��*/

#include "func.h"
const string validIPv6Chars = "012345678abcdefABCDEF";

bool isvaildIPv4token(string& block){
    int num=0;
    if(block.size()>0 && block.size()<=3){
        for(int i=0;i<block.size();i++){
            char c = block[i];
            //�ж�ÿһС���Ƿ񲻴���255 ��û��ǰ��0 ��Ϊ����
            if(!isdigit(c) || (i==0 && c=='0' && block.size()>1))
                return false;
            else{
                //����ÿһ��token��ֵ
                //study:�Ӹ�λ����λ ���ϼ���ʮ���Ƶĺ�
                num *=10;
                num += c-'0';
            }
        }
        return num<=255?1:0;
    }
    return false;
}

bool isvaildIPv6token(string& block){
    //block size<=4 ��5λ
    if(block.size()>0 && block.size()<=4){
        for(int i=0;i<block.size();i++){
            char c = block[i];
            //�����ַ���
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
    //ipv4 IPÿ�ν�ȡ�󶼻���
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
