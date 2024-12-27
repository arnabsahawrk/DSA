// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* class Solution
{
public:
    int sizeOfLL(ListNode *node)
    {
        int count = 0;
        while (node != NULL)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        int sizeOfA = sizeOfLL(headA);
        int sizeOfB = sizeOfLL(headB);

        ListNode *tempA = headA, *tempB = headB;

        if (sizeOfA > sizeOfB)
        {
            int difference = sizeOfA - sizeOfB;
            while (difference--)
            {
                tempA = tempA->next;
            }
        }
        else if (sizeOfB > sizeOfA)
        {
            int difference = sizeOfB - sizeOfA;
            while (difference--)
            {
                tempB = tempB->next;
            }
        }

        while (tempA != NULL && tempB != NULL)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
}; */

// Optimize Version
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA, *tempB = headB;
        while (tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;

            if (tempA == tempB)
                return tempA;

            if (tempA == NULL)
                tempA = headA;
            if (tempB == NULL)
                tempB = headB;
        }

        return tempA;
    }
};