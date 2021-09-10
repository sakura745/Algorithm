//
// Created by bas on 9/8/21.
//

#ifndef MAIN_LINKEDLIST_PALINDROME_H
#define MAIN_LINKEDLIST_PALINDROME_H

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//法一 笔试
//先用快慢指针找到中点位置，将后半部分push stack，在弹出stack与head比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        //注意起点的位置
        ListNode *fast = head;
        ListNode *slow = head->next;

        //&&左操作数的条件要比&&右操作数的条件先达到，左操作数相当右操作数的一个if语句
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        stack<ListNode*> stack;
        while(slow != nullptr){
            stack.push(slow);
            slow = slow->next;
        }
        while(!stack.empty()){
            if(stack.top()->val != head->val){
                return false;
            }
            stack.pop();
            head = head->next;
        }
        return true;
    }
};

//法二：面试
//反转列表而不是push stack pop stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(nullptr == head->next || nullptr == head) return true;
        ListNode* fast = head, *slow = head->next;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * reverL = reverseList(slow);
        while(reverL != nullptr){
            if(head->val != reverL->val){
                return false;
            }
            head = head->next;
            reverL = reverL->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head){
        if(nullptr == head->next || nullptr == head) return head;
        ListNode *pre = nullptr, *cur = head;
        while(cur != nullptr){
            ListNode* tmp = cur->next;//断开cur与cur下一个node的link
            cur->next = pre;//将cur指向pre反向link
            pre = cur;//pre移动到cur位置
            cur = tmp;//cur移动到tmp位置
        }
        head->next = cur;//将反转的链表恢复，为了使链表正常，无修改。
        return pre;
    }
};

#endif //MAIN_LINKEDLIST_PALINDROME_H
