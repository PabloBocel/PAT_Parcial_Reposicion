
#include "Ejercicio01.h"
#include "Node.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2) {
    Node<int>* result = nullptr;
    Node<int>* current = nullptr;

    int carry = 0;

    while (l1 || l2 || carry) {
        int num1 = (l1) ? l1->value : 0;
        int num2 = (l2) ? l2->value : 0;

        int sum = num1 + num2 + carry;
        carry = sum / 10;

        if (!result) {
            result = new Node<int>(sum % 10);
            current = result;
        }
        else {
            current->next = new Node<int>(sum % 10);
            current = current->next;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return result;
}



