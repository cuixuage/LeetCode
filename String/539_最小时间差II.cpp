//�Ա� 681��Ŀ

/*
��������24Сʱ�Ƶ�ʱ�� �ж� ���� ʱ��������С�ķ�����
Input: ["23:59","00:00"]
Output: 1

//*****��Ҫ˼·:  ����ͬһת��Ϊ���Ӽ���
*/


//******************һ��AC
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
        ss.str("");      //****��ջ�����
    }
    std::sort(minutes.begin(),minutes.end());

    int minTime=INT_MAX;
    for(auto i=minutes.begin();i!=minutes.end()-1;++i){
        int temp = *(i+1) - *i;
        if(temp<minTime) minTime=temp;
    }
    int fromNightTime = 24*60-minutes.back()+minutes.front();   //���ʱ��ͨ��24:00������Сʱ��֮���ʱ����

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
