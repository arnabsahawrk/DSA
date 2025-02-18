// https://www.naukri.com/code360/problems/maximum-equal-stack-sum_1062571
#include <bits/stdc++.h>
using namespace std;
int getSum(stack<int> st)
{
    int sum = 0;

    while (!st.empty())
    {
        sum += st.top();

        st.pop();
    }

    return sum;
}
int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3)
{
    int sum1 = getSum(stk1);
    int sum2 = getSum(stk2);
    int sum3 = getSum(stk3);

    while (sum1 != sum2 || sum2 != sum3)
    {
        if (sum1 >= sum2 && sum1 >= sum3)
        {
            sum1 -= stk1.top();

            stk1.pop();
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= stk2.top();

            stk2.pop();
        }
        else
        {
            sum3 -= stk3.top();

            stk3.pop();
        }
    }

    return sum1;
}