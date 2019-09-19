/*
数字1~N的排列方法,返回第K个排列
e.g. N=3时,第K个排列是321
*/
// https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
#include "func.h"

string getPermutation(int N, int K){
    int pos = 0;
    vector<int> numbers(N,0);
    vector<int> factorial(N+1,0);

    //factorial[] = {1,1,2,6,...,N!}
    int sum  = 1;
    factorial[0] = 1;
    for(int i=1; i<=N; i++){
        sum *= i;
        factorial[i] = sum;
    }
    
    //nembers to get index
    for(int i=0; i<N;i++)
        numbers[i] = i+1;
    
    string ans = "";
    K--;
    for(int i=1;i<=N;i++){
        int index = K/factorial[N-i];       //确定在哪个数字开头的排列中
        ans += numbers[index] + '0';
        numbers.erase(numbers.begin()+index,numbers.begin()+index+1);
        K -= index*factorial[N-i];
    }
    return ans;
}