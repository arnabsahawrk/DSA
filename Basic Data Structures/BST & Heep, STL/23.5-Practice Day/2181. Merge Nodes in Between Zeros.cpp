// https://leetcode.com/problems/merge-nodes-in-between-zeros/
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
    ListNode *mergeNodes(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *newHead = nullptr, *newTail = nullptr;

        head = head->next;
        int sum = 0;
        while (head != nullptr)
        {
            sum += head->val;
            if (head->val == 0)
            {
                ListNode *newNode = new ListNode(sum);

                if (newTail == nullptr)
                {
                    newHead = newNode;
                    newTail = newNode;
                }
                else
                {
                    newTail->next = newNode;
                    newTail = newNode;
                }
                sum = 0;
            }
            head = head->next;
        }

        return newHead;
    }
};