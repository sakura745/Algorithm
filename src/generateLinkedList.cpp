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


ListNode* generateRandomLinkedList(int MaxSize, int MaxValue){
    srand(time(0));
    ListNode* dum = new ListNode(-1);//define dummy node
    ListNode* ptr = dum;//using generate Linked List
    for(int i = 0; i < MaxSize; i++){
        ptr->next = new ListNode(rand() % MaxValue + 1);//赋值
        ptr = ptr->next;//下移
    }
    ptr = dum->next;//生成List之后，将ptr设为linkedlist 的head node
    delete dum;
    return ptr;
}

void printLinkedList(ListNode* head){
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}

int main(){
    int MaxSize = 10;
    int MaxValue = 10;
    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
    printLinkedList(head);

    //手动链表
    ListNode* text;
    text = new ListNode(1);
    text->next = new ListNode(2);
    text->next->next = new ListNode(3);
    text->next->next->next = new ListNode(4);
    text->next->next->next->next = new ListNode(5);
    text->next->next->next->next->next = new ListNode(6);
    text->next->next->next->next->next->next = new ListNode(7);
    text->next->next->next->next->next->next = text->next;//环

    return 0;
}
