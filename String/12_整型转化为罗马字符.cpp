#include "func.h"
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
/*
 int length = sizeof(values)/sizeof(values[0]);  //��������ĳ��ȷ���
 */

string intToRoman(int num) {

    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string strs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string sb;
    int length = sizeof(values)/sizeof(values[0]);  //��������ĳ��ȷ���
    for(int i=0;i<13;i++) {             //С��values.lenght()
        while(num >= values[i]) {
            num -= values[i];
            sb  += strs[i];
        }
    }
    return sb;
}

int main(int argc,char* argv){
    cout<<intToRoman(1)<<endl;
    return 0;
}
