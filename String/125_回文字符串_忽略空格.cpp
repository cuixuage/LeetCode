/*
A man, a plan, a canal: Panama �ǻ����ַ��� �ո���Ժ��� �����ַ����ܺ���
1.quicksort ����
2.����
*/
//һ���жϻ����ַ���
//bool isPalindrome(string str){
//    int i = 0;
//    int j = str.size() - 1;
//    while(i < j){
//        if(str[i++] != str[j--]) return false;
//    }
//    return true;
//}

#include "func.h"
//����1:
//�ؼ� isalnum ������ĸ������������
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


//����2:
bool isPalindrome2(string s) {
    //i �൱����start j�൱����end
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
