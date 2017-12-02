
/*�����ַ���str1,str2 �ж�str2�Ƿ�Ϊstr1�Ӵ�,�����Ӵ����ȳ��ֵ����*/

#include"func.h"

//����1:
/*string::npos ���κ����������ֵ�������������ɡ� ����ָ���κ��޷������͵����ֵ�ı�ݷ���
*/
int strStr(string haystack, string needle)
{
    size_t ans = haystack.find(needle);
    return  ans!=string::npos ? ans:-1;
}


//����2:
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
