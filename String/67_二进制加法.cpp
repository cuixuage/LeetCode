/*
˼·1��Ӳ����
˼·2: elegent ����ĳ��Ȳ�'0'  ***************����
˼·3:ת��Ϊʮ������� ��ת��Ϊ������(�м����ȫ����string����)  ������Χ
*/
#include"func.h"
//����2:
string addBinary2(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;    //���� s+=char��˳��
            c /= 2;
        }

        return s;
    }
//����1 Ӳ����  accepted
string addBinary(string a, string b) {
    string ans;
    int la=a.length();
    int lb=b.length();
    cout<<la<<" "<<lb<<endl;
    bool flag = false;
    for(int i=0;i<std::min(la,lb);i++){
        int temp = a.at(la-1-i)-'0' + b.at(lb-1-i)-'0';
        cout<<temp<<endl;
        if(flag==false){
            if(temp!=2) ans += temp+'0';
            else        {flag=true;ans += '0';}
        }
        else{
            if(temp==0) {flag=false;ans += '1';}
            //���� ������� ��Ȼ����flag==true;
            else if(temp==1) ans +='0';
            else ans += '1';
        }
    }
    std::reverse(ans.begin(),ans.end());
    if(flag==false){
        return la>lb?a.substr(0,la-lb)+ans : b.substr(0,lb-la)+ans;
    }
    else{
        string temp;
        if(la==lb) return '1'+ans;
        else if(la>lb){
            for(int i=la-lb-1;i>0;i--){
                if(i==la-lb-1) a.at(i) +=1;       //ascii��+1 �൱����ֵ+1
                if(a.at(i)=='2'){
                    a.at(i-1) +=1;
                    temp += '0';
                }
                else temp += a.at(i);
            }
            if(la-lb==1) a.at(0) +=1;   //����"11"+"1"���û�н��������ѭ��
            //�������ַ����⴦��
            if(a.at(0)!='2') temp +=a.at(0);
            else if(a.at(0)=='2') temp +="01";
            std::reverse(temp.begin(),temp.end());
            return temp+ans;
        }
        else{
            for(int i=lb-la-1;i>0;i--){
                if(i==lb-la-1) b.at(i) +=1;       //ascii��+1 �൱����ֵ+1
                if(b.at(i)=='2'){
                    b.at(i-1) +=1;
                    temp += '0';
                }
                else temp += b.at(i);
            }
            if(lb-la==1) b.at(0) +=1;
            if(b.at(0)!='2') temp +=b.at(0);
            else if(b.at(0)=='2') temp +="01";

            std::reverse(temp.begin(),temp.end());
            return temp+ans;
        }
    }
}
//����3 ����ת��  ���ᳬ��unsigned long��Χ
//����м�ʹ��string �������ͱ����������ֻص��˶����Ƽӷ�������
string addBinary3(string a, string b){
    unsigned long temp=0,ans1=0,ans2=0,c=0;  //c��ÿһλ��Ȩ��
    string res;   //�������յĶ�����
    c=1;
    for(int i=a.length()-1;i>=0;i--){
        ans1 += (a.at(i)-'0')*c;
        c *= 2;
    }
    c=1;
    for(int i=b.length()-1;i>=0;i--){
        ans2 += (b.at(i)-'0')*c;
        c *=2;
    }

    temp = ans1+ans2;
    do{                     //����while do
        int k=temp%2;
        res += k+'0';
        temp /=2;
    }while(temp!=0);
    std::reverse(res.begin(),res.end());
    return res;
}
int main(){
    string a="11";
    string b="1";

    //�����β�
    cout<<addBinary3(a,b)<<endl;
    return 0;
}
