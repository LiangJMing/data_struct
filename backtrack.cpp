#include <cstdio>
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <stack>
using namespace std;
#define M 105
int i, j, n, W;  //n��ʾn����Ʒ�� w��ʾ���ﳵ������
double w[M], v[M];  //w[i]��ʾ��i����Ʒ�������� v[i]��ʾ��i����Ʒ�ļ�ֵ
bool x[M];		//x[i]��ʾ��i����Ʒ�Ƿ���빺�ﳵ
double cw;		//��ǰ����
double cp;		//��ǰ��ֵ
double bestp;	//��ǰ���ż�ֵ
bool bestx[M];	//��ǰ���Ž�

double Bound(int i)
{
	//ʣ����ƷΪ��i - n����Ʒ
	int rp = 0;
	while (i <= n)
	{
		rp += v[i];
		i++;
	}
	return cp + rp;
}

void Backtrack(int t)	//	���������ռ�����t��ʾ��ǰ��չ����ڵ�t��
{
	if (t > n)	//�Ѿ�����Ҷ�ӽ��
	{
		for (j = 1; j <= n; j++)
		{
			bestx[j] = x[j];	//���浱ǰ���Ž�
		}
		bestp = cp;
		return;
	}
	if (cw + w[t] <= W)	//���������������������������
	{
		x[t] = 1;
		cw += w[t];
		cp += v[t];
		Backtrack(t + 1);
		cw -= w[t];			//Ϊʲô����Ҫ����ȥ�أ�
		cp -= v[t];			//��Ϊ���滹��һ��if�ж�
	}
	if (Bound(t + 1) > bestp) //����������
	{
		x[t] = 0;
		Backtrack(t + 1);
	}
}

void Knapsack(double W, int n)
{
	//��ʼ��
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
		cout << "���빺�ﳵ����Ʒ����ֵΪ��" << bestp << endl;
		cout << "���е���Ʒ�����빺�ﳵ��";
		return;
	}
	Backtrack(1);
	cout << "���빺�ﳵ����Ʒ������ֵΪ��" << bestp << endl;
	cout << "���빺�ﳵ����Ʒ���Ϊ��";
	for (i = 1;i <= n;i++)
	{
		if (bestx[i] == 1)
			cout << i << " ";
	}
	cout << endl;
}

int main()
{
	cout << "������Ʒ�ĸ���n:";
	cin >> n;
	cout << "���빺�ﳵ������W:";
	cin >> W;
	cout << "������ÿ����Ʒ������w�ͼ�ֵv,�ÿո�ֿ���";
	for (i = 1; i <= n;i++)
		cin >> w[i] >> v[i];
	Knapsack(W, n);
	system("pause");
	return 0;
}
/*
��������
n:4
W:10
2 6 5 3 4 5 2 4
���
15
1 3 4

*/