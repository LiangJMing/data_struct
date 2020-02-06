#### 容器--stack

> 栈

| 方法                  | 说明               |
| --------------------- | ------------------ |
| bool empty()          | 栈为空，返回true   |
| size_type size()      | 返回栈中元素数目   |
| T& top()              | 返回栈顶元素的引用 |
| void push(const T& x) | 在栈顶插入x        |
| void pop()            | 删除栈顶元素       |



> 洛谷题目
>
> 后缀表达式https://www.luogu.com.cn/problem/P1449

~~~c++
#include <bits/stdc++.h>
using namespace std;
stack<int> n;
char ch;
int s,x,y;
int main()
{
    while(ch!='@')
    {
        ch=getchar();
        switch(ch)
        {
            case '+':x=n.top();n.pop();y=n.top();n.pop();n.push(x+y);break;
            case '-':x=n.top();n.pop();y=n.top();n.pop();n.push(y-x);break;
            case '*':x=n.top();n.pop();y=n.top();n.pop();n.push(x*y);break;
            case '/':x=n.top();n.pop();y=n.top();n.pop();n.push(y/x);break;
            case '.':n.push(s);s=0;break;
            default :s=s*10+ch-'0';break;
        }
    }
    printf("%d\n",n.top());
    return 0;
}
~~~

