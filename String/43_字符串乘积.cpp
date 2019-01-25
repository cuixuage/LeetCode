/*
num1 num2都是只包含0-9,小于110位的字符串,计算其乘积
思路:
只能一位接一位的相乘计算和
*/
string multiply(string num1,string num2){
    //1.预开辟空间
    string sum(num1.size()+num2.size(),'0');
    for(int i=num1.size()-1;i>=0;i--){
        int carry = 0;
        //2.tmp由三部分构成
        for(int j=num2.size()-1;j>=0;j--){
            int tmp = (sum[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            sum[i+j+1] = tmp%10+'0';
            carry = tmp/10;
        }
        //3.进位
        sum[i] += carry;
    }
    //4.删除预开辟的前导零
    size_t startpos = sum.find_first_not_of("0")
    if(startpos != string::npos )
        return sum.substr(startpos);
    return "0";
}




//Error 越界(超过int的范围)
string multiply(string num1, string num2) {
    int res=0;
    for(int i=num2.length()-1;i>=0;i--){
        int ele1=0;
        int ele2 = (num2[i]-'0')*std::pow(10,num2.length()-1-i);
        for(int j=num1.length()-1;j>=0;j--){
            ele1 += (num1[j]-'0')*std::pow(10,num1.length()-1-j);
        }
        res += ele1 * ele2;
    }
    return std::to_string(res);
}
