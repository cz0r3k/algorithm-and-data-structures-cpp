#include <iostream>

struct elem
{
    int value;
    elem *next;
} *head = nullptr;

void insertOrd(int v)
{
    elem *pNew = new elem();
    pNew->value = v;
    elem **p = &head;
    while ((*p) != nullptr && (*p)->value > v)
    {
        p = &((*p)->next);
    }
    pNew->next = *p;
    *p = pNew;
}

elem *delMax()
{
    if (!head)
    {
        return head;
    }
    elem *p = head;
    head = head->next;
    return p;
}

elem *getMax()
{
    return head;
}
void printRev(elem *p)
{
    if (!p)
    {
        return;
    }
    printRev(p->next);
    std::cout << p->value << " ";
}
void print(elem *p)
{
    while (p)
    {
        std::cout << p->value << " ";
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{
    insertOrd(6);
    insertOrd(4);
    insertOrd(10);
    printRev(head);
    std::cout << '\n';
    print(head);
    std::cout << '\n';
    delMax();
    print(head);
    std::cout << '\n';
    delMax();
    delMax();
    delMax();
    print(head);
    std::cout << '\n';
    return 0;
}
