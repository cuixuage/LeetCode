/*
A man, a plan, a canal: Panama 是回文字符串 空格可以忽略 数字字符不能忽略
1.quicksort 变型
2.正常
*/
//一般判断回文字符串
//bool isPalindrome(string str){
//    int i = 0;
//    int j = str.size() - 1;
//    while(i < j){
//        if(str[i++] != str[j--]) return false;
//    }
//    return true;
//}

#include "func.h"
//方案1:
//关键 isalnum 不是字母或者数字跳过
bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}


//方案2:
bool isPalindrome2(string s) {
    //i 相当于是start j相当于是end
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}

int main(){
    string s ="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s)<<endl;
    return 0;
}
