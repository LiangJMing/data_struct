#include <cstdio>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <stack>
using namespace std;
const int INF = 1e7;	//设置无穷大的值
const int N = 100;		
int g[N][N];			
int x[N];				//记录当前路径
int bestx[N];			//记录当前最优路径
int cl;					//当前路径长度
int bestl;				//当前最短路径长度
int n, m;				//城市个数n，边数m

void Traveling(int t)
{
	if (t > n)
	{
		//到达叶子结点
		//最后一个城市与住地城市有边相连并且路径长度比当前最优值小
		// 说明找到了一条更好的路径，记录相关信息
		if (g[x[n]][1] != INF && (cl + g[x[n]][1] < bestl))
		{
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];
			bestl = cl + g[x[n]][1];
		}
	}
	else
	{
		//没有到达叶子结点
		for (int j = t; j <= n; j++)
		{	//搜索扩展结点的所有分支
			//如果第t-1个城市与第t个城市有边相连并且有可能得到更短的路径
			if (g[x[t-1]][x[j]] != INF && (cl + g[x[t-1]][x[j]] < bestl))
			{	//保存第t个要去的城市编号到x(t)中，进入到第t+1层
				swap(x[t], x[j]);//交换两个元素的值
				cl = cl + g[x[t - 1]][x[t]];
				Traveling(t + 1);//从第t+1层的扩展结点继续搜索
				cl = cl - g[x[t - 1]][x[t]];//回溯到第t层
				swap(x[t], x[j]);
			}
		}
	}
}


void init()//初始化
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
	cout << "最短路径：";
	for (int i = 1; i <= n; i++)
		cout << bestx[i] << "-->";
	cout << "1" << endl;
	cout << "最短路径长度：" << bestl;
}
int main()
{
	int u, v, w;
	cout << "输入结点数n:";
	cin >> n;
	init();
	cout << "输入景点之间的连线数：";
	cin >> m;
	cout << "依次输入两个景点u、v之间的距离w:"<<endl;
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
输入结点数n:5
输入景点之间的连线数：9
依次输入两个景点u、v之间的距离w:
1 2 3
1 4 8
1 5 9
2 3 3
2 4 10
2 5 5
3 4 4
3 5 3
4 5 20
最短路径：1-->2-->5-->3-->4-->1
最短路径长度：23请按任意键继续. . .
*/
