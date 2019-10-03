#include <cstdio>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <stack>
using namespace std;
const int INF = 1e7;	//����������ֵ
const int N = 100;		
int g[N][N];			
int x[N];				//��¼��ǰ·��
int bestx[N];			//��¼��ǰ����·��
int cl;					//��ǰ·������
int bestl;				//��ǰ���·������
int n, m;				//���и���n������m

void Traveling(int t)
{
	if (t > n)
	{
		//����Ҷ�ӽ��
		//���һ��������ס�س����б���������·�����ȱȵ�ǰ����ֵС
		// ˵���ҵ���һ�����õ�·������¼�����Ϣ
		if (g[x[n]][1] != INF && (cl + g[x[n]][1] < bestl))
		{
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];
			bestl = cl + g[x[n]][1];
		}
	}
	else
	{
		//û�е���Ҷ�ӽ��
		for (int j = t; j <= n; j++)
		{	//������չ�������з�֧
			//�����t-1���������t�������б����������п��ܵõ����̵�·��
			if (g[x[t-1]][x[j]] != INF && (cl + g[x[t-1]][x[j]] < bestl))
			{	//�����t��Ҫȥ�ĳ��б�ŵ�x(t)�У����뵽��t+1��
				swap(x[t], x[j]);//��������Ԫ�ص�ֵ
				cl = cl + g[x[t - 1]][x[t]];
				Traveling(t + 1);//�ӵ�t+1�����չ����������
				cl = cl - g[x[t - 1]][x[t]];//���ݵ���t��
				swap(x[t], x[j]);
			}
		}
	}
}


void init()//��ʼ��
{
	bestl = INF;
	cl = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1; j <= n;j++)
		{
			g[i][j] = INF;
			g[j][i] = INF;
		}
	for (int i = 0;i <= n;i++)
	{
		x[i] = i;
		bestx[i] = 0;
	}
}

void print()
{
	cout << "���·����";
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "-->";
	cout << "1" << endl;
	cout << "���·�����ȣ�" << bestl;
}
int main()
{
	int u, v, w;
	cout << "��������n:";
	cin >> n;
	init();
	cout << "���뾰��֮�����������";
	cin >> m;
	cout << "����������������u��v֮��ľ���w:"<<endl;
	for (int i = 1; i <= m;i++)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	Traveling(2);
	print();
	system("pause");
	return 0;
}
/*
��������n:5
���뾰��֮�����������9
����������������u��v֮��ľ���w:
1 2 3
1 4 8
1 5 9
2 3 3
2 4 10
2 5 5
3 4 4
3 5 3
4 5 20
���·����1-->2-->5-->3-->4-->1
���·�����ȣ�23�밴���������. . .
*/