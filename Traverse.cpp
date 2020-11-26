#include <iostream>
#include <stack>
#define ELEM char
using namespace std;
struct Node
{
    Node *LChild;
    Node *RChild;
    ELEM value;
    Node(ELEM curr)
    {
        this->value = curr;
        this->LChild = this->RChild = NULL;
    }
};
void PreOrder(Node *n )
{
    cout << "先序遍历的结果为：" << endl;
    stack<Node *> s;
    s.push(n);
    Node *top;
    while (!s.empty())
    {
        top = s.top();
        s.pop();
        cout << top->value << endl;
        if (top->RChild)
            s.push(top->RChild);
        if (top->LChild)
            s.push(top->LChild);
    }
}
void InOrder(Node *n)
{
    cout << "中序遍历的结果为：" << endl;
    stack<Node *> s;
    Node *curr = n;
    while (NULL != curr || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->LChild;
        }
        cout << s.top()->value << endl;
        curr = s.top()->RChild;
        s.pop();
    }
}
void postOrderIterative(struct Node *root)
{
    cout << "后序遍历的结果为：" << endl;
    if (root == NULL)
        return;
    stack<Node *> s;
    do
    {
        while (root)
        {
            if (root->RChild)
                s.push(root->RChild);
            s.push(root);
            root = root->LChild;
        }
        root = s.top();
        s.pop();
        if (root->RChild && !s.empty() && s.top() == root->RChild)
        {
            s.pop();
            s.push(root);
            root = root->RChild;
        }
        else
        {
            cout << root->value << endl;
            root = NULL;
        }
    } while (!s.empty());
}
int main()
{
    Node a('a'), b('b'), c('c'), d('d'), e('e'), f('f');
    a.LChild = &b;
    a.RChild = &c;
    b.LChild = &d;
    b.RChild = &e;
    c.LChild = &f;
    InOrder(&a);
    PreOrder(&a);
    postOrderIterative(&a);
    return 0;
}