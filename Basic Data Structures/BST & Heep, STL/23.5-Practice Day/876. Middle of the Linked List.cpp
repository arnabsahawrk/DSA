// https://leetcode.com/problems/middle-of-the-linked-list/
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
    int sizeOfLL(ListNode *node)
    {
        int count = 0;
        while (node)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode *middleNode(ListNode *head)
    {
        int size = ceil(sizeOfLL(head) / 2);

        while (head && size--)
        {
            head = head->next;
        }

        return head;
    }
};