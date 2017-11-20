
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;

#define inf 0xFFFFFFFF      //����Ϊ���ɴ�
#define VertexData unsigned int  //��������
#define UINT  unsigned int
//#define vexCounts 5  //��������
//#define vexCounts 4  //��������
#define vexCounts 11  //��������

char* vextex[] = { "v1", "v2", "v3", "v4", "v5", "v6","v7","v8", "v9","v10" ,"v11"};

void AdjMatrix(unsigned int adjMat[][vexCounts])  //�ڽӾ����ʾ��
{
    for (int i = 0; i < vexCounts; i++)   //��ʼ���ڽӾ���
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
    vector<VertexData> vexset; //�Ѿ��ҵ����·���Ķ��㼯
    vector<UINT> dist(vexCounts); //û�б��ҵ����·���Ķ��������Ϣ
    vector<vector<VertexData> > path(vexCounts); //ÿ����������·����Ϣ  //�ڽӾ��� ���ԶԱ��ڽ�����ķ���
    for (unsigned int i = 0; i < vexCounts; i++)
    {
        dist[i] = adjMat[s][i];  //��ʼ������
        if (dist[i] != inf)
        {
            path[i].push_back(s);  //�洢���·��
            path[i].push_back(i);
        }
    }
    vexset.push_back(s); //��ʼ�Ѷ���s����vexset

    for (unsigned int n = 1; n <= vexCounts-1; n++)
    {
        UINT min = inf;
        UINT k = inf;
        for (int i = 0; i < vexCounts;i++) //Ѱ����һ�����·��
        {
            if (find(vexset.rbegin(),vexset.rend(),i) == vexset.rend() && dist[i] < min)
            {
                k = i;
                min = dist[i];
            }
        }
        vexset.push_back(k); //�����·���������vexset��
        for (int i = 0; i < vexCounts;i++)  //����dist
        {
            /*���vexset���Ƿ��Ѿ��ж���i,��i�����·���Ƿ��Ѿ��ҵ���
            ���û���ҵ������ж��Ƿ���Ҫ�������·��*/
            if (find(vexset.rbegin(), vexset.rend(), i) == vexset.rend()
                && adjMat[k][i] != inf && dist[k]+ adjMat[k][i] < dist[i])
            {
                dist[i] = dist[k] + adjMat[k][i];   //���� ���ڼ�����Ԫ�صĿɵ������
                path[i] = path[k];    //����i �����·��Ϊ newp(�¼�����)��·��
                path[i].push_back(i);
            }
        };

        //���ڹ۲죬���ÿ����������·�������������������㼰�����
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
{   //�ڽӾ����ʼ��
//    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,5000,5000}, {5000,0,1,2,5000}, {5000,5000,0,9,2}, {5000,5000,5000,0,2}, {5000,5000,5000,5000,0}};

//    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,5000}, {5000,0,1,2}, {5000,5000,0,9}, {5000,5000,5000,0}};

    unsigned int  adjMat[vexCounts][vexCounts] = { {0,2,3,4,inf,inf,inf,inf,inf,inf,inf}, {inf,0,3,inf,7,2,inf,inf,inf,inf,inf}, {inf,inf,0,inf,inf,9,2,inf,inf,inf,inf},
                                                    {inf,inf,inf,0,inf,inf,2,inf,inf,inf,inf}, {inf,inf,inf,inf,0,inf,inf,3,3,inf,inf}, {inf,inf,inf,inf,inf,0,1,inf,3,inf,inf},
                                                    {inf,inf,inf,inf,inf,inf,0,inf,5,1,inf}, {inf,inf,inf,inf,inf,inf,inf,0,inf,inf,3}, {inf,inf,inf,inf,inf,inf,inf,inf,0,inf,2}, {inf,inf,inf,inf,inf,inf,inf,inf,2,inf,2}, {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,0},};
    cout << "Dijkastra : V1" << endl;
    cout << "Start"<<"\t"<<"End"<<"\t"<<"Length"<<"\t"<<"NodeList"<<endl;
    ShortestPath_DJS(adjMat, 0); //V1�����Ϊ0.
    return 0;
}
