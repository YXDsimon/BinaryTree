#include <iostream>
#include <queue>
#define ELEM int
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

void LevelTraversalCheck(Node *root)
{
    queue<Node *> Q;
    Node *current;
    Q.push(root);
    bool Complete = true; //标记二叉树是否完整的标志
    int mode = false;
    while (!Q.empty())
    {
        current = Q.front();
        Q.pop();
        cout << current->value << endl;
        if (current->LChild)
        {
            Q.push(current->LChild);
            if (mode && Complete)
                Complete = false;
        }
        else
        {
            if (current->RChild)
                Complete = false;
            else
                mode = true; //进入检查模式，一旦接下来任何节点不是叶子节点，即可判断该二叉树不完整
        }
        if (current->RChild)
            Q.push(current->RChild);
    }
    if (Complete)
        cout << "该二叉树是完整二叉树" << endl;
    else
        cout << "该二叉树是不完整二叉树"<< endl;
}
int main()
{
    Node *T1=new Node(1);
    T1->LChild=new Node(2);
    T1->RChild=new Node(3);
    T1->LChild->LChild=new Node(4);
    T1->LChild->RChild=new Node(5);
    T1->RChild->LChild=new Node(6);

    Node *T2=new Node(1);
    T2->LChild=new Node(2);
    T2->RChild=new Node(3);
    T2->LChild->LChild=new Node(4);
    T2->LChild->RChild=new Node(5);
    T2->LChild->RChild->RChild=new Node(7);
    T2->RChild->LChild=new Node(6);
    LevelTraversalCheck(T1);
    LevelTraversalCheck(T2);
    return 0;
}