
// This header file is under development

#include <queue>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class Tree : public Node
{
    Node *root = NULL;
    void inOrder();
    void preOrder(Node *root, std::vector<int>&);
    void postOrder(Node *root, std::vector<int>&);

public:
    Tree(int data)
    {
        this->root = new Node();
        this->root->data = data;
        this->root->left = NULL;
        this->root->right = NULL;
    }
    ~Tree();
    void addNode(int data);
    void getInOrderTraversal();
    std::vector<int> getPreOrderTraversal();
    std::vector<int> getPostOrderTraversal();

};
void Tree::inOrder()
{
    if(this->root == NULL)
        return
    this->root->left->inOrder();
    std::cout<<root->data<<" ";
    this->root->left->inOrder();
}
/*
void Tree::preOrder(Node *root, std::vector<int> &process)
{
    if(!root)
        return
    process.push_back(root->data);
    inOrder(root->left, process);
    inOrder(root->right, process);
}
void Tree::postOrder(Node *root, std::vector<int> &process)
{
    if(!root)
        return
    inOrder(root->left, process);
    inOrder(root->right, process);
    process.push_back(root->data);
}
*/
void Tree::getInOrderTraversal()
{
    if(this->root == NULL)
        return;
    inOrder(this->root);

}
void Tree::addNode(int data)
{
    if(!(this->root))
    {
        this->root = new Node();
        this->root->data = data;
        this->root->left = NULL;
        this->root->right = NULL;
        return;
    }
    Node *new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    std::queue<Node *> store;
    store.push(this->root);

    while(!store.empty())
    {
        Node *temp = store.front();
        std::cout<<temp->data<<" ";
        store.pop();

        if (temp->left != NULL)
            store.push(temp->left);
        else
        {
            temp->left = new_node;
            return;
        }

        if (temp->right != NULL)
            store.push(temp->right);
        else
        {
            temp->right = new_node;
            return;
        }
    }
}




