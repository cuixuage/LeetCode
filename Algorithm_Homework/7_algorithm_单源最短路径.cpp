
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

#define inf 0xFFFFFFFF      //设置为不可达
#define VertexData unsigned int  //顶点数据
#define UINT  unsigned int
//#define vexCounts 5  //顶点数量
//#define vexCounts 4  //顶点数量
#define vexCounts 11  //顶点数量

char* vextex[] = { "v1", "v2", "v3", "v4", "v5", "v6","v7","v8", "v9","v10" ,"v11"};

void AdjMatrix(unsigned int adjMat[][vexCounts])  //邻接矩阵表示法
{
    for (int i = 0; i < vexCounts; i++)   //初始化邻接矩阵
        for (int j = 0; j < vexCounts; j++)
        {
            if(j==i) adjMat[i][j]=0;
            else adjMat[i][j]=inf;
        }
    adjMat[0][1] = 20; adjMat[0][2] = 50; adjMat[0][3] = 30;
    adjMat[1][2] = 25; adjMat[1][5] = 70;
    adjMat[2][4] = 25; adjMat[2][5] = 50;
    adjMat[3][2] = 40; adjMat[3][4] = 55;
    adjMat[4][5] = 10; adjMat[4][6] = 70;
    adjMat[5][6] = 50;
}

void ShortestPath_DJS(unsigned int adjMat[][vexCounts],unsigned int s)
{
    vector<VertexData> vexset; //已经找到最短路径的顶点集
    vector<UINT> dist(vexCounts); //没有被找的最短路径的顶点距离信息
    vector<vector<VertexData> > path(vexCounts); //每个顶点的最短路径信息  //邻接矩阵 可以对比邻接链表的方法
    for (unsigned int i = 0; i < vexCounts; i++)
    {
        dist[i] = adjMat[s][i];  //初始化距离
        if (dist[i] != inf)
        {
            path[i].push_back(s);  //存储最短路线
            path[i].push_back(i);
        }
    }
    vexset.push_back(s); //初始把顶点s加入vexset

    for (unsigned int n = 1; n <= vexCounts-1; n++)
    {
        UINT min = inf;
        UINT k = inf;
        for (int i = 0; i < vexCounts;i++) //寻找下一条最短路径
        {
            if (find(vexset.rbegin(),vexset.rend(),i) == vexset.rend() && dist[i] < min)
            {
                k = i;
                min = dist[i];
            }
        }
        vexset.push_back(k); //把最短路径顶点加入vexset中
        for (int i = 0; i < vexCounts;i++)  //更新dist
        {
            /*检测vexset中是否已经有顶点i,即i的最短路径是否已经找到。
            如果没有找到，则判定是否需要更新最短路径*/
            if (find(vexset.rbegin(), vexset.rend(), i) == vexset.rend()
                && adjMat[k][i] != inf && dist[k]+ adjMat[k][i] < dist[i])
            {
                dist[i] = dist[k] + adjMat[k][i];   //更新 不在集合中元素的可到达距离
                path[i] = path[k];    //更新i 的最短路线为 newp(新加入结点)的路线
                path[i].push_back(i);
            }
        };

        //便于观察，输出每个顶点的最短路径经过的所有其他顶点及其距离
        cout<<"v1"<<"\t"
            <<vextex[path[k][path[k].size()-1]]<<"\t"
            <<dist[k]<<"\t"
            ;
        for (int i = 0; i < path[k].size();i++)
        {
            if(i==0) cout << vextex[path[k][i]] ;
            else cout << ","<<vextex[path[k][i]] ;
        }
        cout<<endl;

    }
}

int main()
{   //邻接矩阵初始化
//    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,5000,5000}, {5000,0,1,2,5000}, {5000,5000,0,9,2}, {5000,5000,5000,0,2}, {5000,5000,5000,5000,0}};

//    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,5000}, {5000,0,1,2}, {5000,5000,0,9}, {5000,5000,5000,0}};

    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,4,inf,inf,inf,inf,inf,inf,inf}, {inf,0,3,inf,7,2,inf,inf,inf,inf,inf}, {inf,inf,0,inf,inf,9,2,inf,inf,inf,inf},
                                                    {inf,inf,inf,0,inf,inf,2,inf,inf,inf,inf}, {inf,inf,inf,inf,0,inf,inf,3,3,inf,inf}, {inf,inf,inf,inf,inf,0,1,inf,3,inf,inf},
                                                    {inf,inf,inf,inf,inf,inf,0,inf,5,1,inf}, {inf,inf,inf,inf,inf,inf,inf,0,inf,inf,3}, {inf,inf,inf,inf,inf,inf,inf,inf,0,inf,2}, {inf,inf,inf,inf,inf,inf,inf,inf,2,inf,2}, {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,0},};
    cout << "Dijkastra : V1" << endl;
    cout << "Start"<<"\t"<<"End"<<"\t"<<"Length"<<"\t"<<"NodeList"<<endl;
    ShortestPath_DJS(adjMat, 0); //V1的序号为0.
    return 0;
}
