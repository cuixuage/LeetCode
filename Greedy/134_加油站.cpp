#include "func.h"
/*
Input:
如果存在solution 则solution唯一
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3  起始点 要求最终可以回到起始点

思路:
1.O(n*n) 对于每一个元素判断其是否可以作为起始点 & 经过后面所有元素可以回到出发点

2.O(N)  greedy
遍历一遍,如果sum(gas[i]-cost[i])<0,那么不存在，return -1。  大于零则必然存在一个合理的起始点

核心:  如果A是合理起始点，那么如果A无法到达B，则A,B之间的所有节点都无法达到B

*/

class Solution{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
        int start(0),negative_total(0),tank(0);
        //O(N) if fails at 'start', next position to judge
        for(int i=0; i<gas.size();i++){
            tank += gas[i]-cost[i];
            if(tank < 0){
                start = i+1;        //move start_postion forward
                negative_total += tank;  //add the negative tank value to total
                tank = 0;   //reset tank
            }
        }
        //sum(gas[i]-cost[i])<0; return -1
        return (negative_total + tank < 0)? -1:start;
    }
}
