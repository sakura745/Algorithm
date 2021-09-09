//
// Created by bas on 9/9/21.
//
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};


ListNode* generateLinkedList(int MaxSize, int MaxValue){

    srand(time(0));

    ListNode* dum = new ListNode(-1);//define dummy node
    ListNode* ptr = dum;//using traversal vector
    for(int i = 0; i < MaxSize; i++){
        ptr->next = new ListNode(rand() % MaxValue + 1);//赋值
        ptr = ptr->next;//下移
    }
    ptr = dum->next;//遍历之后，将ptr设为linkedlist 的head node
    delete dum;
    return ptr;
}

void printLinkedList(ListNode* head){
    if(head == nullptr) return;
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){
    int MaxSize = 10;
    int MaxValue = 10;
    ListNode* head = generateLinkedList(MaxSize, MaxValue);
    printLinkedList(head);
    return 0;
}
