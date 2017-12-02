
/*对于字符串str1,str2 判断str2是否为str1子串,返回子串最先出现的序号*/

#include"func.h"

//方案1:
/*string::npos 是任何类型中最大值，它都可以容纳。 这是指定任何无符号类型的最大值的便捷方法
*/
int strStr(string haystack, string needle)
{
    size_t ans = haystack.find(needle);
    return  ans!=string::npos ? ans:-1;
}


//方案2:
int strStr(string haystack, string needle)
{
    int m = haystack.length(), n = needle.length();
    if (!n) return 0;
    for (int i = 0; i < m - n + 1; i++)
    {
        int j = 0;
        for (; j < n; j++)
            if (haystack[i + j] != needle[j])
                break;
        if (j == n) return i;
    }
    return -1;
}
