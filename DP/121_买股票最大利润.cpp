/*
����vectorѰ��ǰ���ֵ������ֵ��Ҫ����Ÿߵ����ּ�ȥ��ŵ͵����֡�
����˼·: ����������� ����:1 5 2 3 4 maxprofitӦΪ4
*/
#include "func.h"using std::cout;
using std::endl;

//min ��¼��ǰԪ��ǰ�������е���Сֵ
//�Ƚ� �Ѿ������maxprofit �� value[i]-min�Ĳ�ֵ����
int maxProfit(vector<int>& prices) {
    int valMin = INT_MAX;
    int profit = 0;
    for(int i=0;i<prices.size();i++){
        if(prices[i] < valMin) valMin=prices[i];
        profit = std::max(profit,prices[i]-valMin);
    }
    return profit;
}

int main(){
    vector<int> test = {1,2,2,3,3};
    cout<<maxProfit(test)<<endl;
    return 0;
}
