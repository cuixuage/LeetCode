/* R ���� L ���� U ���� D ����  ������һϵ���ַ��ƶ����ܷ�ص�ԭ�㣿*/
// for(char c : string)  �����ַ����÷���


//һ��AC
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
