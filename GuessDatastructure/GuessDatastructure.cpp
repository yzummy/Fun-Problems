// GuessDatastructure.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

bool myfunction(int i, int j) { return i < j; }

int main()
{

  bool isQueue = true, isImp = false, isStack = true, isPQueue = true;
  int num;
  string snum;
  int command, value;
  

  while (scanf("%d",&num) != EOF)
  {
    //num = atoi(snum.c_str());
    int values[1000];
    queue <int> que;
    priority_queue<int> pque;
    stack<int> stakk;
    isQueue = true, isImp = false, isStack = true, isPQueue = true;
    for (int i = 0; i < num; i++)
    {
      cin >> command >> value;
      values[i] = value;
      if (command == 1)
      {
        que.push(value);
        pque.push(value);
        stakk.push(value);
      }
      else {
        if (find(values, values + i, value) == values + i)
        {
          isImp = true;
        }
        else if (que.size() <= 0) {
          isImp = true;
        }
        else {
          if (isQueue && que.front() != value) {
            isQueue = false;
          }
          que.pop();
          if (isPQueue && pque.top() != value) {
            isPQueue = false;
          }
          pque.pop();
          if (isStack && stakk.top() != value) {
            isStack = false;
          }
          stakk.pop();
        }

      }
    }

    if (isImp)
    {
      cout << "impossible\n";
    }
    else if ((isStack && isQueue) || (isStack && isPQueue) || (isPQueue && isQueue))
    {
      cout << "not sure\n";
    }
    else if (isStack) {
      cout << "stack\n";
    }
    else if (isQueue) {
      cout << "queue\n";
    }
    else if (isPQueue) {
      cout << "priority queue\n";
    }
    else {
      cout << "impossible\n";
    }



  }
  

  return 0;
}

