/* R 右行 L 左行 U 上移 D 下移  在所给一系列字符移动后能否回到原点？*/
// for(char c : string)  遍历字符串好方法


//一次AC
bool judgeCircle(string moves)
{
    int i=0,j=0;
    for(char c : moves)
    {
        if(c=='R') i+=1;
        else if(c=='L') i-=1;
        else if(c=='U') j +=1;
        else if(c=='D') j-=1;
    }
    return i==0&&j==0 ? 1:0;
}
