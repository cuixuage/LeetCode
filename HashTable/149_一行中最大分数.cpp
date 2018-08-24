#include "func.h"
/*
2D数组,可以构成的最大直线的长度
思路1:
每两个点构成直线 得到y=kx+b,再顺序判断其他点
O(N*N)==>优化思路:
hashtable<double,int>保存每一个点的某斜率方向的全部点数
=》得到某一个点出发的最大点数
=》选取最大值

https://leetcode.com/problems/max-points-on-a-line/discuss/47117/Sharing-my-simple-solution-with-explanation

思路2:
Error
min,max构成table 只需判断hash中每一行，每一列，每一个斜线(斜线方向太多)即可 O(N*N)
*/

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
//[[0,0],[94911151,94911150],[94911152,94911151]]  无法通过  更改double为pair作为斜率
int maxPoints(vector<Point>& points){
    int result = 0;
    for(int i=0;i<points.size();i++){
        int samePoint = 0;
        int overFlowSlope = 0;
        int curMax = 0;
        unordered_map<string,int> map;
        
        //统计以points[i]为起点  所有斜率方向的点数
        for(int j=i+1;j<points.size();j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y)//operator==并没有重载
                samePoint++;
            else if(points[i].x == points[j].x)
                overFlowSlope++;
            //其他斜率的计算
            else{
                int yDif = points[i].y - points[j].y;
                int xDif = points[i].x - points[j].x;
                int g = std::__gcd(yDif,xDif);            //最大公约数
                yDif /= g;
                xDif /= g;
                if (yDif < 0) {                     //保证正数在转换后的string前面  key
                    yDif = -yDif;
                    xDif = -xDif;
                }
                stringstream str;
                str<<yDif<<","<<xDif;
                map[str.str()]++;
                curMax = std::max(curMax,map[str.str()]);
            }
            curMax = std::max(curMax,overFlowSlope);
        }
        
        //所有point中的最大值
        result = std::max(result,curMax+samePoint+1);
    }
    return result;
}




/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
