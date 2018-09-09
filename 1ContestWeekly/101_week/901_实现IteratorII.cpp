//类似于900 题目
//区别 最大连续的递增子序列问题  明显不一样
#include "func.h"

//思路1 timelimit
class StockSpanner{
public:
    StockSpanner(){
        curMax = 0;
        prePrice = INT_MAX;
    }
    int next(int price){

        prices.push_back(price);
        if(price < prePrice){
            curMax = 1;
            prePrice = price;
        }else{
            prePrice = price;
            curMax = 0;
            for(int i=prices.size()-1;i>=0;i--){
                if(prices[i] <= prePrice){
                    //cout<<"prePrice="<<prePrice<<" curMax="<<curMax<<endl;
                    curMax += 1;
                }else{
                    break;
                }
            }
        }

        return curMax;
    }
private:
    std::vector<int> prices;
    int curMax;
    int prePrice;
};

int main(){
    StockSpanner obj = StockSpanner();
    int param1 = obj.next(100);
    cout<<param1<<endl;
        int param2 = obj.next(80);
    cout<<param2<<endl;
        int param3 = obj.next(60);
    cout<<param3<<endl;
        int param4 = obj.next(70);
    cout<<param4<<endl;
        int param5 = obj.next(60);
    cout<<param5<<endl;
        int param6 = obj.next(75);
    cout<<param6<<endl;

}
