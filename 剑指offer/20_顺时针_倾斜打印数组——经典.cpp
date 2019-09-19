/*
思路:
从外到内,每次打印一圈

四个变量:  top bottom left right

while( left<=right && top<=bottom )
a[top][left] ==>  a[top][right]
a[top-1][right] ==> a[bottom][right]
a[bottom][right-1] ==> a[bottom][left]      //判断 if(top!=bottom)
a[bottom-1][left] ==> a[top-1][left]        //判断 if(right!=left)

//为打印下一圈做准备
top++;
left++;
bottom--;
right--;
//////////////////////////////////////////////////////////////////////////

对角线打印数组:
row行 col列
1     2     3    
4     5     6
7     8     9
输出:
3
2     6
1     5     9
4     8 
7

//遍历j次
for(int i=0,j=col-1;  j>=0  ;j--)
    // cout A[i][j]  这里是每一行的开始
    for(int k=i,l=j; k<=row-1&&l<=col-1; k++,l++)
        coutA[k][l]                                     

//遍历i次
for(int i=1,j=0;  i<=row-1; i++)
    //每行的开始
    for(int k=i,l=j;  k<=row-1&&l<=cur-1;  k++,l++)     //不越界
        cout A[k][l]