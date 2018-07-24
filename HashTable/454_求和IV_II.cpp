/*
length of list = N 1~500
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

/*
思路:
map 保存A,B两者的交叉每一项的和 (和:出现次数)  另一个map保存C,D
计算这两者map和为零则output++
*/

#include "func.h"
#include<unordered_map>

int calSumCount(vector<int>& A, vector<int>& B, vector<int>&,C, vector<int>& D){
    unordered_map<int,int> abSum;
    for(auto a:A){
        for(auto b:B)
            abSum[a+b]++;
    }
    int count = 0;
    for( auto c:C){
        for(auto d:D){
            auto itera = abSum.find(0-c-d);  // 是否存在相加等于零的情况
            if(itera != abSum.end()){
                count += itera->second;
            }
        }
    }
    return count;
}
