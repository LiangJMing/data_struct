#### hash记录搜索的bfs

> 洛谷题目
>
> 幻象迷宫https://www.luogu.com.cn/problem/P1363
>
> 求是否能走出带障碍的地图，特点为地图可重复，当在同幅地图循环走时不能认为走出无穷远



**思路**

> 如果能够两次走到不同地图的相同点，说明能够走到无穷远
>
> 如何表征在不同幅地图到达相同的环境点？
>
> 从起点开始广度优先搜索，走过的路打上hash值，在不同地图上实际坐标有不同的值
>
> 当在不同的实际坐标到达相同的环境点，说明可依靠其地图的可重复性走无穷远的路



~~~c++
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <queue>
#include "string.h"
#include "stdio.h"


using namespace std;

int n, m;
int ne[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int book[1510][1510];
char s[1510][1510];

struct p {
	int x, y;
};

int f(int x, int y) {
	return (x + n * 4) / n * 131 + (y + m * 4) / m * 13;
}

bool bfs(int x, int y)
{
	queue<p> q;
	q.push(p{ x, y });
	book[x][y] = f(x, y);

	while (!q.empty())
	{
		p u = q.front();
		p v;
		q.pop();
		for (int i = 0;i < 4;i++)
		{	
            //实际坐标
			v.x = u.x + ne[i][0];
			v.y = u.y + ne[i][1];
            
            //环境坐标
			int tx = (v.x + n * 4) % n;
			int ty = (v.y + m * 4) % m;
            
            //实际坐标生成的hash值
			int t = f(v.x, v.y);
			if (s[tx][ty] == '#') continue;  //障碍
			if (!book[tx][ty]) book[tx][ty] = t, q.push(v);  //第一次到达该环境
			else if (book[tx][ty] != t) return 1;  //第二次到达该环境，如果不是同幅地图
		}
	}
	return 0;
}

int main()
{	
	while (cin>>n>>m)
	{
		memset(book, 0, sizeof(book));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				cin >> s[i][j];

		//寻找起点S
		int x, y;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (s[i][j] == 'S') {
					x = i, y = j;
					break;
				}
			}
		}
		if (bfs(x, y)) printf("Yes\n");
		else printf("No\n");
	}

	getchar();
	cin.get();
	return 0;
}

~~~

