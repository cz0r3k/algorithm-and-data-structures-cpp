#include <iostream>

struct node
{
    int key;
    node *left;
    node *right;
    node(int key, node *left, node *right)
    {
        this->key = key;
        this->left = left;
        this->right = right;
    }
} *root = nullptr;

node **Search(int v)
{
    node **p = &root;
    while ((*p) && (*p)->key != v)
    {
        if ((*p)->key > v)
        {
            p = &((*p)->left);
        }
        else
        {
            p = &((*p)->right);
        }
    }
    return p;
}

node *Insert(int v)
{
    node *&p = *Search(v);
    if (!p)
    {
        p = new node(v, nullptr, nullptr);
    }
    return p;
}

node *GetRightMin(node *root)
{
    if (!root)
    {
        return nullptr;
    }
    node *p = root->right;
    while (p->left)
    {
        p = p->left;
    }
    return p;
}

node *Delete(int v)
{

    node **p = Search(v);
    node ***parent_pointer = &p;
    node *out_node = *p;
    if (!*p)
    {
        return nullptr;
    }
    if (!(*p)->left && !(*p)->right)
    {
        **parent_pointer = nullptr;
    }
    else if (!(*p)->left)
    {
        **parent_pointer = (*p)->right;
    }
    else if (!(*p)->right)
    {
        **parent_pointer = (*p)->left;
    }
    else
    {
        node *right_min = Delete(GetRightMin(*p)->key);
        node *left = (**parent_pointer)->left;
        **parent_pointer = right_min;
        (**parent_pointer)->left = left;
    }
    out_node->left = nullptr;
    out_node->right = nullptr;
    return out_node;
}

int main(int argc, char const *argv[])
{
    Insert(1);
    node *p = Delete(1);
    std::cout << p->key << std::endl;
    Insert(2);
    node *p1 = *Search(1);
    if (!p1)
    {
        std::cout << "p1 null" << std::endl;
    }
    p1 = *Search(2);
    std::cout << p1->key << std::endl;

    Insert(1);
    Insert(3);
    node *p2 = Delete(2);
    node *toor = root;
    std::cout << root->key << std::endl;
    return 0;
}
