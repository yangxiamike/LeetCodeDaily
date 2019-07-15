//
//  sort list.cpp
//  Leetcode
//
//  Created by xiayang on 2019/7/15.
//  Copyright © 2019 xiayang. All rights reserved.
//

#include <stdio.h>

//O(Nlog(N))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head, *p2 = head->next;
        while (p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
            if (p2->next != nullptr)
                p2 = p2->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p2 = sortList(p2);
        p1 = sortList(head);
        head = merge(p1, p2);
        return head;
    }
    ListNode* merge(ListNode* p1, ListNode* p2){
        ListNode result(0), *curr = &result;
        while (p1 != NULL && p2 != nullptr){
            if (p1->val < p2->val){
                curr->next = p1;
                p1 = p1->next;
            }
            else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if (p1 != nullptr)
            curr->next = p1;
        else if (p2 != nullptr)
            curr->next = p2;
        return result.next;
    }
};
