/*
判断一个整数是不是回文数字
*/

bool isPalindrome(int x){
    //负数 或者 10的整数倍的值
    if(x<0 || (x!=0 && x %10==0))
        return false;
    int sum = 0;
    //e.g. 121 sum=12 x=1   
    //sum是后半部分数字的reverse(奇数个数字时 也包括中间数字)
    //x 是前部分
    while( x > sum ){
        sum = sum*10 + x%10;
        x = x/10;
    }
    return (x==sum) ||(x==sum/10)
}
