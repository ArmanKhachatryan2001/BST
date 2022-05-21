#include <iostream>
#include <initializer_list>

template <typename T>
class node
{
    T m_item;
    node<T>* m_left;
    node<T>* m_right;

public:
    node(T item = T(), node<T>* left = nullptr, node<T>* right = nullptr) :
        m_item(item),
        m_left(left),
        m_right(right)
    {
    }
    ~node()
    {
    }

    node*& get_left()
    {
        return m_left;
    }
    node*& get_right()
    {
        return m_right;
    }
    T get_item()
    {
        return m_item;
    }
};

template <typename T>
class BST
{
    node<T>* root;

public:

    BST() :
        root(nullptr)
    {}

    BST(std::initializer_list<T> list) : root(nullptr)
    {

        for(T item : list) {
            insert(item);
        }
    }

    BST(const BST& cmp)
    {
        copy(root, cmp.root);
    }

    BST(BST&& move)
    {
        root = move.root;
        move.root = nullptr;
    }

    ~BST()
    {
        delete_root(root);
    }

private:

    void delete_root(node<T>* droot)
    {
        if(droot == nullptr) {
            return;
        }
        delete_root(droot->get_left());
        delete_root(droot->get_right());
        delete droot;
    }

    void copy(node<T>*& root, node<T>* croot){
        if(croot == nullptr){
            return ;
        }
        root = new node<T>(croot->get_item());
        copy(root->get_left(), croot->get_left());
        copy(root->get_right(), croot->get_right());


    }

    void push(node<T>*& root, T value)
    {
        if (root == nullptr) {
            root = new node<T>(value);
            return;
        }
        if(value < root->get_item()) {
            push(root->get_left(), value);
        }
        if(value > root->get_item()) {
            push(root->get_right(), value);
        }
    }

    void print(node<T>* _node)
    {
        if (_node == nullptr) {
            return;
        }
        print(_node->get_left());
        std::cout << _node->get_item() << " ";
        print(_node->get_right());
    }

public:
    void print()
    {
        print(root);
    }
    void insert(T value)
    {
        push(root, value);
    }
};

int main()
{
    BST<int>a = {7,6,5,4,3};
    a.insert(9);
    a.insert(10);
    a.insert(1);
    a.insert(11);
    BST<int>b = a;
    b.insert(21);
    BST<int>c(std::move(a));
    c.print();
    a.print();
    std::cout << std::endl;
    b.print();
    return 0;
}
