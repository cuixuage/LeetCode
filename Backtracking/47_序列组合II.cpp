#include "func.h"
/*
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
思路: 递归
1.set 去掉重复的序列(set<vector<int>>)
2. 跳过 相同数字的swap
*/

vector<vector<int> > permuteUnique(vector<int> &num){

    //关键   要排序
    std::sort(num.begin(),num.end());
    vector<vector<int>> result;
    permuteRecursive(num,0,num.size(),result);
    return result;
}

//特别注意传递的num形参   不是引用！！！
//vector容器的传递存在传值   区别常规数组！！！
void permuteRecursive(vector<int> num, int begin,int len, vector<vector<int>> &result){
    //递归出口
    if(begin==len-1){
        result.push_back(num);
        return ;
    }
    for(int k=begin; k<len;k++){
        //关键 continue
        if(k!=begin && num[k]==num[begin]) continue;

        std::swap(num[begin],num[k]);
        //注意这里   num是传值  思考有什么区别么？？？
        permuteRecursive(num,begin+1,len,result);
    }
}



//set<vector<int>> -- accept
//空间是O(n)  时间N^2？？
vector<vector<int> > permuteUnique(vector<int> &num){
    vector<vector<int>> result;
    set<vector<int>> resultSet;
    permuteRecursive(num,0,resultSet);
    for(auto i:resultSet){
        result.push_back(i);
    }
    return result;
}

void permuteRecursive(vector<int> &num, int begin, set<vector<int>> &resultSet){
    //递归出口
    if(begin==num.size()){
        resultSet.insert(num);
        return ;
    }
    for(int i=begin; i<num.size();i++){
        std::swap(num[begin],num[i]);
        permuteRecursive(num,begin+1,resultSet);
        //reset
        std::swap(num[begin],num[i]);
    }
}
