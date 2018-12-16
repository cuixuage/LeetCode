/*
考虑最后一位的加一  进制问题

思路: 
1.vector fornt先插入空位0       重要
2.从末尾其循环进位
3.判断删除前导零
*/

//一次AC
vector<int> plusOne(vector<int>& digits) {
    digits.insert(digits.begin(),0);
    int len = digits.size();
    digits[len-1] += 1;     //最后一位加1
    
    for(int i=len-1;i>=1;i--){
        if(digits[i] == 10){
            digits[i]=0;
            digits[i-1] += 1;
        }else
            break;
    }
    if(digits[0]==0) digits.erase(digits.begin(),digits.begin()+1);
    return digits;
}
