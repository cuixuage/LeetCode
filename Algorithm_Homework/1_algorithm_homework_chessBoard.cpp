// 存在特殊方格的棋盘 被L形骨牌填充问题
/**
*  tr 棋盘左上角行号
*  tc 棋盘左上角列号
*  dr 特殊方格行号
*  dc 特殊方格列号
*  size 棋盘的边长
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
using std::endl;
using std::cout;
using std::ofstream;
#define N 16       //2^k k是矩阵的行数列数
static int ROW = 7;    //row colum是特殊方块所在位置的行号列号
static int COLUM = 7;
static int tile = 1;   //由1开始标识L形骨牌
static int board[N][N]={0};

void chessBoard(int tr,int tc,int dr,int dc,int size){
        if (size == 1) {   //1*1直接返回 因为此时也已经标为title号码
            return;
        }
        int t = tile++;   //骨牌编号
        int s = size/2;   //更新分治区域大小
        //覆盖左上角棋盘
        if (dr<tr+s&&dc<tc+s) {   //特殊方块在此次分治区域内 再次分治
            chessBoard( tr, tc, dr, dc, s);
        }else {
            board[tr+s-1][tc+s-1] = t;  //否则右下角元素设置title号码的L骨牌
            chessBoard(tr, tc, tr+s-1, tc+s-1, s);
        }
        //覆盖右上角棋盘
        if (dr<tr+s&&dc>=tc+s) {
            chessBoard(tr, tc+s, dr, dc, s);
        }else {
            board[tr+s-1][tc+s] = t;  //否则左下角元素设置title号码的L骨牌
            chessBoard(tr, tc+s, tr+s-1, tc+s, s);
        }
        //覆盖左下角棋盘
        if (dr>=tr+s&&dc<tc+s) {
            chessBoard(tr+s, tc, dr, dc, s);
        }else{
            board[tr+s][tc+s-1] = t;  //否则右上角元素设置title号码的L骨牌
            chessBoard(tr+s, tc, tr+s, tc+s-1, s);
        }
        //覆盖右下角棋盘
        if (dr>=tr+s&&dc>=tc+s) {
            chessBoard(tr+s, tc+s, dr, dc, s);
        }else{
            board[tr+s][tc+s] = t;  //否则左上角元素设置title号码的L骨牌
            chessBoard(tr+s, tc+s, tr+s, tc+s, s);
        }
}
void print() {
    ofstream ofs("homework.txt");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j]==0) ofs<<"###"<<"\t";    //初始特殊方格按照###输出
            else ofs<<board[i][j]<<"\t";
        }
            ofs<<endl;
    }
    ofs.close();
}
int main(int argc,char** argv){
    //初始值 左上角元素行号列号 特殊字符所在行号列号 矩阵大小
    chessBoard(0, 0, ROW, COLUM, N);
    print();
    cout<< "16*16矩阵元素较多 cmd单独一行看不全"<<endl<<
    "运行结果已经写入当前目录下homework.txt"<<endl;
}

