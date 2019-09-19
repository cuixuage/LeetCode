/*
最长的没有重复字符的substring
注: substring(截取的连续字符)而非sequence(子序列)
dp[i] = dp[i-1]+1  or  dp[i]= hashtable delete
trick: string[i]如果已经有了重复项,寻找最近出现的index ==> j
substr = i-j
*/

// If the character is already in the hashmap, then move the left pointer to the right of the same character last found.
int lengthOfLongestSubstring(string str){
    if( str=="" ) return 0;
    unordered_map<char,int> map;    //key:字符, val:index
    int max_len = 0;
    int slow = 0;
    for(int fast=0;fast<str.size();fast++){
        if(!map.count(str[fast])){      //新的字符
            map[str[fast]] = fast;
        }else{
            //字符已经存在  更新slow到fast字符最近出现的位置
            slow = std::max(slow,map[str[fast]]+1);      //max函数目的: slow只能前向移动
            map[str[fast]] = fast;
        }
        max_len = std::max(max_len,fast-slow+1);
    }
    return max_len;
}












//方案: 对于每一个字符为结尾的max substr,从这些substr中再寻找最大的
//思考: i慢速指针 j指向待加入的新字符

//滑动窗口:
//使用一个哈希集跟踪最长的不重复的substr,使用一个快速的指针j来查看是否字符j是否在哈希集，
//如果不在，很好，将其添加到哈希集，移动j转发并更新最大长度，
//否则，使用慢速指针i从头部删除，直到我们可以将字符j置于哈希集合

//有点动态规划的思想

#include "func.h"
//*******************************************方案1
/*
//为什么也能通过呢？   set不按照输入的顺序排序啊？？
//hash set声明空间不是std  不用这个方法
int lengthLongestSubstring(string s){
    int i=0,j=0,maxlen=0;
    set<char> myset;
    while(j<s.length()){
        if(!myset.count(s.at(j))){
            myset.insert(s.at(j++));
            maxlen=std::max(maxlen,(int)myset.size());  //或者max(maxlen,j-i)
        }
        else{
            //滑动窗口 不断删除起始字符直到新的j字符能够加入set
           myset.erase(s.at(i++));
        }
    }
    return maxlen;
}
*/

//******************************方案2
int lengthLongestSubstring(string s) {
    if (s.length()==0) return 0;
    map<char,int> mymap;
    int maxlen=0;
    //j是慢指针,相当于start
    for (int i=0, j=0; i<s.length(); ++i){
        if (mymap.count(s.at(i))){
            //更新以i为结尾的substr的不重复substr的start位置
            //mymap是字符 位置的映射 和i相重复字符的下一个位置
            j = std::max(j,mymap[s.at(i)]+1);
        }

        //加入新的字符
        //这两种方法????
        //mymap.insert(std::make_pair(s.at(i),i));   //这样为什么会使得maxlen答案不对？
        //mymap.insert(std::pair<char,int>(s.at(i),i));
        mymap[s.at(i)]=i;
        //更新最大len
        maxlen = std::max(maxlen,i-j+1);
    }
//    for(auto i: mymap)
//        cout<<i.first<<":"<<i.second<<endl;
    return maxlen;
}
int main(){
    string test="abcabcbb";
    cout<<lengthLongestSubstring(test)<<endl;
    return 0;
}