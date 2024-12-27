// https://leetcode.com/problems/merge-in-between-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *firstMergeHead, *temp = list1, *temp2 = list2;

        for (int i = 1; i <= b + 1; i++)
        {
            if (a == i)
            {
                firstMergeHead = temp;
            }
            temp = temp->next;
        }

        firstMergeHead->next = list2;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;

        return list1;
    }
};