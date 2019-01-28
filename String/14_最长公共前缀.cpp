/*
1.后缀数组解决(循环做LCP)
2.暴力寻找
两两寻找两者的公共前缀,没有公共前缀其prefix元素删除末尾数字 并在此比较
*/

string longestCommonPrefix(vector<string>& strs){
    if(strs.size()==0) return "";
    string prefix = strs[0];
    //从第二个字符串开始两两比较得出公共前缀
    for(int i=1;i<strs.size();i++){
        //prefix不是其他字符串的前缀
        while(strs[i].find(prefix) != 0){
            //prefix删除某位字符,直到成为别人的前缀字符串
            prefix = prefix.substring(0,prefix.size()-1);
            if(prefix.size()==0) return "";
        }
    }
    return prefix;
}
