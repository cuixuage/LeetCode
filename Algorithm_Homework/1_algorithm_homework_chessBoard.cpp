// �������ⷽ������� ��L�ι����������
/**
*  tr �������Ͻ��к�
*  tc �������Ͻ��к�
*  dr ���ⷽ���к�
*  dc ���ⷽ���к�
*  size ���̵ı߳�
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
using std::endl;
using std::cout;
using std::ofstream;
#define N 16       //2^k k�Ǿ������������
static int ROW = 7;    //row colum�����ⷽ������λ�õ��к��к�
static int COLUM = 7;
static int tile = 1;   //��1��ʼ��ʶL�ι���
static int board[N][N]={0};

void chessBoard(int tr,int tc,int dr,int dc,int size){
        if (size == 1) {   //1*1ֱ�ӷ��� ��Ϊ��ʱҲ�Ѿ���Ϊtitle����
            return;
        }
        int t = tile++;   //���Ʊ��
        int s = size/2;   //���·��������С
        //�������Ͻ�����
        if (dr<tr+s&&dc<tc+s) {   //���ⷽ���ڴ˴η��������� �ٴη���
            chessBoard( tr, tc, dr, dc, s);
        }else {
            board[tr+s-1][tc+s-1] = t;  //�������½�Ԫ������title�����L����
            chessBoard(tr, tc, tr+s-1, tc+s-1, s);
        }
        //�������Ͻ�����
        if (dr<tr+s&&dc>=tc+s) {
            chessBoard(tr, tc+s, dr, dc, s);
        }else {
            board[tr+s-1][tc+s] = t;  //�������½�Ԫ������title�����L����
            chessBoard(tr, tc+s, tr+s-1, tc+s, s);
        }
        //�������½�����
        if (dr>=tr+s&&dc<tc+s) {
            chessBoard(tr+s, tc, dr, dc, s);
        }else{
            board[tr+s][tc+s-1] = t;  //�������Ͻ�Ԫ������title�����L����
            chessBoard(tr+s, tc, tr+s, tc+s-1, s);
        }
        //�������½�����
        if (dr>=tr+s&&dc>=tc+s) {
            chessBoard(tr+s, tc+s, dr, dc, s);
        }else{
            board[tr+s][tc+s] = t;  //�������Ͻ�Ԫ������title�����L����
            chessBoard(tr+s, tc+s, tr+s, tc+s, s);
        }
}
void print() {
    ofstream ofs("homework.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j]==0) ofs<<"###"<<"\t";    //��ʼ���ⷽ����###���
            else ofs<<board[i][j]<<"\t";
        }
            ofs<<endl;
    }
    ofs.close();
}
int main(int argc,char** argv){
    //��ʼֵ ���Ͻ�Ԫ���к��к� �����ַ������к��к� �����С
    chessBoard(0, 0, ROW, COLUM, N);
    print();
    cout<< "16*16����Ԫ�ؽ϶� cmd����һ�п���ȫ"<<endl<<
    "���н���Ѿ�д�뵱ǰĿ¼��homework.txt"<<endl;
}

