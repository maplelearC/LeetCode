//
// Created by 24191 on 2022/9/28.
//
/*

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

注意：
你只能使用队列的基本操作 —— 也就是push to back、peek/pop from front、size 和is empty这些操作。
你所使用的语言也许不支持队列。你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。

示例：
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
*/
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> qIn;
    queue<int> qOut;

    MyStack()
    {

    }

    void push(int x)
    {
        qIn.push(x);
    }

    int pop()
    {
        while (qIn.size() > 1)
        {
            qOut.push(qIn.front());
            qIn.pop();
        }

        int res = qIn.front();
        qIn.pop();
        qIn = qOut;
        while (!qOut.empty())
        {
            qOut.pop();
        }
        return res;
    }

    int top()
    {

        return qIn.back();
    }

    bool empty()
    {
        cout << qIn.front() << endl;
        return qIn.empty();
    }
};


int main()
{
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // 返回 2
    cout << myStack.pop() << endl; // 返回 2
    cout << myStack.pop() << endl; // 返回 2
    cout << myStack.empty() << endl; // 返回 False

    return 0;
}