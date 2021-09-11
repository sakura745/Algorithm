//
// Created by bas on 9/10/21.
//

#ifndef ALGRITHOM_INTERSECTIONNODE_H
#define ALGRITHOM_INTERSECTIONNODE_H
//给定两个链表(确定无环)。请判断如果两个链表相交，则返回第一个节点；如果不相交，则返回Null

//法一： 用双指针循环无限循环，但是时间较长
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(NULL == headA || NULL == headB) return NULL;

        //判断是否相交
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1->next != nullptr){
            cur1 = cur1->next;
        }
        while(cur2->next != nullptr){
            cur2 = cur2->next;
        }
        if(cur1 != cur2) return nullptr;

        //寻找第一个节点，时间较长
        cur1 = headA, cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1 != NULL ? cur1->next : headA;
            cur2 = cur2 != NULL ? cur2->next : headB;
        }
        return cur1;
    }
};


//法二:分别遍历链表，通过末尾node判断是否有相交，若相等，则有相交
//无循环 双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(nullptr == headA || nullptr == headB) return NULL;
        ListNode* cur1 = headA, *cur2 = headB;
        int n = 0;//用来计算两个列表的长度差值
        while(cur1->next != nullptr){
            n++;
            cur1 = cur1->next;
        }
        while(cur2->next != nullptr){
            n--;
            cur2 = cur2->next;
        }
        if(cur1 != cur2) return nullptr;//判断是否相交
        cur1 = n > 0 ? headA : headB;//通过用差值来确认长的链表为cur1
        cur2 = cur1 == headA ? headB : headA;//根据上一行来判断另一个较短的为cur2
        n = abs(n);
        //使长的链表先运动差值，保证两个链表同步长度
        while(n != 0){
            n--;
            cur1 = cur1->next;
        }
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur2;
    }
};

#endif //ALGRITHOM_INTERSECTIONNODE_H
