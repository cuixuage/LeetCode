/*
1.每个人至少一个糖果
2.如果一个人的得分高于其邻居,那么需要多一个糖果
最少需要的糖果数量？

思路:
从左到右遍历  +  从右到左遍历   == 建立正确的邻居关系
vector<int>保存糖果的数目
*/

#include "func.h"
int candy(vector<int>& ratings){
    int len = ratings.size();
    int res = 0;
    if(len==0) return res;
    vector<int> number(len,0);
    number[0] = 1;
    //从左到右
    for(int i=1; i<len; i++){
        if(ratings[i] > ratings[i-1])
            number[i] = number[i-1]+1;
        else
            number[i] = 1;
    }
    //从右到左
    res=number[len-1];
    for(int i=len-2; i>=0; i--){
        if((ratings[i] > ratings[i+1]) && number[i]<(number[i+1]+1))  
            number[i] = number[i+1]+1;
        res += number[i];
    }
    return res;
}