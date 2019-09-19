/*
判断一个整数是不是回文数字
*/

bool isPalindrome(int origin){
    //负数 或者 10的整数倍的值
    if(origin<0 || (origin!=0 && origin %10==0))
        return false;
    int last_half = 0;
    //e.g. 121 sum=12 x=1   
    //sum是后半部分数字的reverse(奇数个数字时 也包括中间数字)
    //x 是前部分
    while( origin > last_half ){
        last_half = last_half*10 + origin%10;
        origin = origin/10;
    }
    return (origin==last_half) ||(origin==last_half/10);
}
