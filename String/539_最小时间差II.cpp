//对比 681题目

/*
给定两个24小时制的时间 判断 所有 时间间隔中最小的分钟数
Input: ["23:59","00:00"]
Output: 1

//*****主要思路:  首先同一转换为分钟计算
*/


//******************一遍AC
#include "func.h"
int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;
    minutes.reserve(32);
    stringstream ss;
    string hour,minute;
    for(auto str:timePoints){
        ss<<str;
        getline(ss,hour,':');
        getline(ss,minute,':');
        minutes.push_back(std::atoi(hour.c_str())*60+std::atoi(minute.c_str()));
        ss.clear();
        ss.str("");      //****清空缓冲区
    }
    std::sort(minutes.begin(),minutes.end());

    int minTime=INT_MAX;
    for(auto i=minutes.begin();i!=minutes.end()-1;++i){
        int temp = *(i+1) - *i;
        if(temp<minTime) minTime=temp;
    }
    int fromNightTime = 24*60-minutes.back()+minutes.front();   //最大时间通过24:00到达最小时间之间的时间差距

    return minTime<fromNightTime?minTime:fromNightTime;
}

int main(){
    vector<string> times;
    times.reserve(32);
    times.push_back("23:59");
    times.push_back("00:00");
    cout<<findMinDifference(times)<<endl;
    return 0;
}
