//
// Created by sakura on 11/09/2021.
//
#include <iostream>
#include <assert.h>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode * next):val(x), next(next){}
};

void printLinkedList(ListNode* head){
    ListNode * cur = head;

    while(cur != nullptr){

        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
class Solution{
public:
    ListNode* getLoopIntersection(){

    }
};
int main(){

    ListNode* text;
    text = new ListNode(1);
    text->next = new ListNode(2);
    text->next->next = new ListNode(3);
    text->next->next->next = new ListNode(4);
    text->next->next->next->next = new ListNode(5);
    text->next->next->next->next->next = new ListNode(6);
    text->next->next->next->next->next->next = new ListNode(7);

    ListNode* text1;
    text1 = new ListNode(8);
    text1->next = new ListNode(9);
    text1->next->next = new ListNode(10);
    text1->next->next->next = new ListNode(11);
    text1->next->next->next->next = new ListNode(12);
    text1->next->next->next->next->next = new ListNode(13);
    text1->next->next->next->next->next->next = new ListNode(14);

    text->next->next->next = text1->next->next->next->next;//Intersection or not

    printLinkedList(text);
    printLinkedList(text1);

    Solution A;

    assert(A.getIntersectionNode(text, text1) != 0);
    cout << "That has intersection and position is at " << A.getIntersectionNode(text, text1)->val ;

}

