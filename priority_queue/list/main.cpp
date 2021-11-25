#include <iostream>

struct elem
{
    int value;
    elem *next;
} *sentinel = nullptr, *head = sentinel;

void insert(int v)
{
    elem *p = new elem();
    p->value = v;
    p->next = head;
    head = p;
}
void printAll()
{
    elem *p = head;
    while (p != sentinel)
    {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
elem *search(int v)
{
    sentinel->value = v;
    elem *p = head;
    while (p->value != v)
    {
        p = p->next;
    }
    return p == sentinel ? nullptr : p;
}

elem *delMax()
{
    if (!head)
    {
        return nullptr;
    }
    elem *pMax = head, *ppMax = nullptr;
    elem *p = head, *pp = nullptr;
    while (p->next != sentinel)
    {
        if (p->value > pMax->value)
        {
            ppMax = pp;
            pMax = p;
        }
        pp = p;
        p = p->next;
    }
    if (!ppMax)
    {
        head = pMax->next;
    }
    else
    {
        ppMax->next = pMax->next;
    }
    pMax->next = nullptr;
    return pMax;
}

int main(int argc, char const *argv[])
{
    insert(5);
    insert(10);
    insert(3);
    printAll();
    delMax();
    delMax();
    printAll();
    delMax();
    printAll();
    return 0;
}
