#ifndef BST_H
#define BST_H
template <typename T>
class BST
{

private:

template <typename>
struct node
{
    T m_item;
    node<T>* m_left;
    node<T>* m_right;

    node(T item = T(), node<T>* left = nullptr, node<T>* right = nullptr) :
    m_item(item),
    m_left(left),
    m_right(right)
    {}

    ~node() {}
};

node<T>* root;

public:

    BST() : root(nullptr) {}

    BST(std::initializer_list<T> list) : root(nullptr)
    {
        for(T item : list) {
            insert(item);
        }
    }

    BST(const BST<T>& cmp)
    {
        copy(root, cmp.root);
    }

    BST( BST<T>&& obj)
    {
        root = obj.root;
        obj.root = nullptr;
    }

    BST& operator=(const BST<T>& other)
    {
        if(this == &other) {
            return *this;
        }
        copy(root,other.root);
        return *this;
    }
    BST& operator=(BST<T>&& other)
    {
        this->root = other.root;
        other.root = nullptr;
        return *this;
    }

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& output, BST<T1>& obj);

    friend BST operator+(BST<T>& item,T value)
    {
        BST<T> new_item;
        item.add_value(item.root, value,new_item.root);
        return new_item;
    }

    BST operator+(BST add)
    {
        BST<T> new_obj;
        std::vector<T> outitem;
        amount(root, add.root, new_obj.root, outitem);
        for(auto item : outitem) {
            new_obj.insert(item);
        }
        return new_obj;
    }

    BST operator+=(BST plusequal)
    {
        std::vector<T> outitem;
        amount(root, plusequal.root, root, outitem);
        for(auto item : outitem) {
            insert(item);
        }
        return *this;
    }

    friend bool operator==(  BST<T>& equal,BST<T>& equa)
    {
        return  equal.bool_equal(equal.root, equa.root);
    }

    bool operator!=(BST& not_equal)
    {
        return !(bool_equal(root, not_equal.root));
    }

    ~BST()
    {
        delete_root(root);
    }

    T* find(T value); // this function returns a pointer to the root of a given value
    T non_find{}; // the find function returns not_find if it does not find a value
    BST merge(BST<T> t) //this function returns two trees connected to each other
    {
        merge_function(root, t.root); // Two trees are transferred to this function
            return *this;
    }
    std::vector<T> erase_root; // The erase function is performed using this vector
    std::vector<T> print_vector; // this vector helps the ostream operator
    T get_height(); // returns the height of the tree
    T get_root_data(); // returns root
    void get_number_of_nodes(); // returns the number of roots
    void erase(T val); //removes a specific item
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    void insert(T value); //enters a value
    void clear(); // cleans the tree
    bool contains(T value); // checks if there is such a value
    bool flag = false;
    int number_nodes{}; // this variable keeps the height of the tree

private:

    void add_value(node<T>* item, T value, node<T>*& new_item); // this function can add value to an object
    bool find_function(node<T>* root, T value, T*& finD); // this function looks for whether there is a similar value
    void row(node<T>* root, int value); // this function calculates the height of the tree
    bool contains_function(node<T>* obj, T value); // this function returns true if it has found the transferred value
    void merge_function(node<T>* obj1, node<T>* obj2); // this function connects two trees
    void number_of_nodes(node<T>* obj); // returns the number of roots
    int  get__height(node<T>* height); //returns the height of the tree
    void print_root(node<T>* obj, int value); // prints the tree
    void erase_itr(T value, node<T>* root); // removes the specific value of the tree
    void erase_value(node<T>* obj); // this function helps the erase function
    bool bool_equal(node<T>*& obj1, node<T>*& obj2); // this function compares two trees
    void pushvector(const node<T>* add, std::vector<T>& outitem); // If one of the trees has no left or right node,  it must be a  into the vector
    void amount(node<T>* add1, node<T>* add2, node<T>*& add, std::vector<T>& outitem); // this function adds two trees
    void delete_root(node<T>* droot); // this function deletes the values of the tree
    void copy(node<T>*& root, node<T>* croot); // this function prints the values of a tree into another
    void push(node<T>*& root, T value); // this function adds value
    void vector_print(); // this function prints the values of the tree
};
#include "BST.hpp"
#endif
