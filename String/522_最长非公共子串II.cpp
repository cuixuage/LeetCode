/*
对比 521题
522 输入约束窄 目测不用加上程度判断 直接暴力即可
*/

/*思路2:
sort 按照字符串长度排序 如果没有重复,最长的字符串即为结果
max.length字符串重复 按照长度顺序判断下一个 + 下一个字符串不能是其它字符串(other bigger str)的子串
*/

#include "func.h"
bool hasCommon(string a,string b)
{
    int remine = a.size();
    int remine2 = b.size();
    for(; remine>0&&remine2>0;)
    {
        int i = a.size()-remine;    //从0开始遍历元素
        int j = b.size()-remine2;
        if(a.at(i) == b.at(j))
        {
            remine--;
            remine2--;
        }
        else                      //寻找b的下一个能与a下一个相同元素
        {
            remine2--;
        }
    }
    return remine==0;
}
////大错特错  需要判断 b中能否寻找的非连续的子串 == a
////而非简单的连续子串包含关系
//bool hasCommon(string a,string b){
//    if(a.find(b)!=string::npos || b.find(a)!=string::npos)
//        return true;
//    else
//        return false;
//}

int findLUSlength(vector<string>& strs)
{
    int maxLen = -1;
    int i,j;
    for(i = 0; i<strs.size(); ++i)  //遍历每一各元素
    {
        int currentLen = strs[i].length();              //str长度
        bool all = true;
        //***这里必须是由0 开始遍历！！ 需要保证每一个bigger元素都包括此元素
        for(j= 0; j<strs.size(); ++j)
        {
            if(i!=j && hasCommon(strs[i], strs[j]))      //寻找此str 与其他所有元素的最大非公共子串
            {
                all = false;
                break;
            }
        }
        if(all==true)
        {
            maxLen = maxLen<currentLen?currentLen:maxLen;   //maxlen保存最大值
        }
    }
    return maxLen;
}


int main()
{
    vector<string> strs;
    strs.reserve(32);
    strs.push_back("aaa");
    strs.push_back("aaa");
    strs.push_back("aa");
    cout<<findLUSlength(strs)<<endl;

    return 0;
}
