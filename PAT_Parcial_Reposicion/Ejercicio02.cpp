#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    if (head == nullptr || k == 1) {
        return head;
    }

    Node<char>* dummy = new Node<char>();  
    dummy->next = head;
    Node<char>* pre = dummy;
    Node<char>* cur = head;
    int count = 0;
    
    while (head != nullptr) {
        count++;
        head = head->next;
    }

    while (count >= k) {
        Node<char>* prev = nullptr;
        Node<char>* tail = cur;

        for (int i = 0; i < k; ++i) {
            Node<char>* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        pre->next = prev;
        tail->next = cur;
        pre = tail;
        count -= k;
    }

    return dummy->next;
}
