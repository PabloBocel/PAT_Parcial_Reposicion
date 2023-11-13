
#include "Ejercicio01.h"
#include "Node.h"

Node<int>* reverseList(Node<int>* head) {
    Node<int>* prev = nullptr;
    Node<int>* current = head;
    Node<int>* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node<int>* dummyHead = new Node<int>(0);
    Node<int>* p = l1, * q = l2, * curr = dummyHead;
    int carry = 0;
    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->value : 0;
        int y = (q != nullptr) ? q->value : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new Node<int>(sum % 10);
        curr = curr->next;
        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }
    if (carry > 0) {
        curr->next = new Node<int>(carry);
    }

    Node<int>* result = reverseList(dummyHead->next);
    return result;
}













