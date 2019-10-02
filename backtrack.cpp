#include <cstdio>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <stack>
using namespace std;
#define M 105
int i, j, n, W;  //n表示n个物品， w表示购物车的重量
double w[M], v[M];  //w[i]表示第i个物品的重量， v[i]表示第i个物品的价值
bool x[M];		//x[i]表示第i个物品是否放入购物车
double cw;		//当前重量
double cp;		//当前价值
double bestp;	//当前最优价值
bool bestx[M];	//当前最优解

double Bound(int i)
{
	//剩余物品为第i - n种物品
	int rp = 0;
	while (i <= n)
	{
		rp += v[i];
		i++;
	}
	return cp + rp;
}

void Backtrack(int t)	//	用于搜索空间数，t表示当前扩展结点在第t层
{
	if (t > n)	//已经到达叶子结点
	{
		for (j = 1; j <= n; j++)
		{
			bestx[j] = x[j];	//保存当前最优解
		}
		bestp = cp;
		return;
	}
	if (cw + w[t] <= W)	//如果满足限制条件则搜索左子树
	{
		x[t] = 1;
		cw += w[t];
		cp += v[t];
		Backtrack(t + 1);
		cw -= w[t];			//为什么这里要减回去呢？
		cp -= v[t];			//因为下面还有一个if判断
	}
	if (Bound(t + 1) > bestp) //搜索右子树
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void Knapsack(double W, int n)
{
	//初始化
	cw = 0;
	cp = 0;
	bestp = 0;
	double sumw = 0.0;
	double sumv = 0.0;
	for (i = 1;i <= n;i++)
	{
		sumv += v[i];
		sumw += w[i];
	}
	if (sumw <= W)
	{
		bestp = sumv;
		cout << "放入购物车的物品最大价值为：" << bestp << endl;
		cout << "所有的物品均放入购物车。";
		return;
	}
	Backtrack(1);
	cout << "放入购物车的物品的最大价值为：" << bestp << endl;
	cout << "放入购物车的物品序号为：";
	for (i = 1;i <= n;i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}

int main()
{
	cout << "输入物品的个数n:";
	cin >> n;
	cout << "输入购物车的容量W:";
	cin >> W;
	cout << "请输入每个物品的重量w和价值v,用空格分开：";
	for (i = 1; i <= n;i++)
		cin >> w[i] >> v[i];
	Knapsack(W, n);
	system("pause");
	return 0;
}
/*
测试数据
n:4
W:10
2 6 5 3 4 5 2 4
输出
15
1 3 4

*/