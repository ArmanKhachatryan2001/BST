#include <iostream>
#include <initializer_list>
#include <vector>

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
        return  !(bool_equal(root, not_equal.root));
    }

    ~BST()
    {
     delete_root(root);
    }

    T* find(T value);
    void levelorder();
    bool contains(T value);
    T get_root_data();
    void get_number_of_nodes();
    T get_height();
    void inorder();
    void preorder();
    void postorder();
    void insert(T value);
    void clear();
    void erase(T val);
    bool equal = false;
    std::vector<T> v_erase;
    std::vector<T> vec;
    std::vector<T> itr;
    int number_nodes{};
    BST merge(BST<T> t)
    {
    Merge(root, t.root);
    return *this;
    }
    void begin() {
        inorder();
    }
private:

    void add_value(node<T>* item,  T value, node<T>*& new_item);
    bool find_function(node<T>* root, T value, T* finD);
    void row(node<T>* root, int value);
    void containS(node<T>* obj);
    void Merge(node<T>* obj1, node<T>* obj2);
    void number_of_nodes(node<T>* obj);
    int  get__height(node<T>* height);
    void print_root(node<T>* obj, int value);
    void erase_itr(T value, node<T>* root);
    void erase_val(node<T>* obj);
    bool bool_equal(node<T>*& obj1, node<T>*& obj2);
    void pushvector(const node<T>* add, std::vector<T>& outitem);
    void amount(node<T>* add1, node<T>* add2, node<T>*& add, std::vector<T>& outitem);
    void delete_root(node<T>* droot);
    void copy(node<T>*& root, node<T>* croot);
    void push(node<T>*& root, T value);
    void vector_print();
    bool Contains(T value);
};

int main()
{
    BST<int> a = {778,55,6,9};
    a.erase(778);
    BST<int> b = {77,55,6,3};
    std::cout << a;
      return 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& output, BST<T>& obj)
{
    obj.print_root(obj.root,1);
    for (auto item : obj.vec) {
    output << item << " ";
    }
    output << std::endl;
    return output;
}

template<typename T>
void BST<T>::levelorder()
{
    int height = get__height(root);
    for(int i = 0; i < height; ++i) {
    row(root,i);
    }
}

template<typename T>
void BST<T>::inorder()
{
    print_root(root,1);
    vector_print();
    vec.clear();
}

template<typename T>
void BST<T>::preorder()
{
    print_root(root,2);
    vector_print();
    vec.clear();
}

template<typename T>
void BST<T>::postorder()
{
    print_root(root,3);
    vector_print();
    vec.clear();
}

template<typename T>
void BST<T>::insert(T value)
{
    push(root,value);
}

template<typename T>
void BST<T>::clear()
{
    delete_root(root);
    root = nullptr;
}

template<typename T>
void BST<T>::erase(T val)
{
    erase_val(root);
    root = nullptr;
    erase_itr(val,root);
}

template<typename T>
bool BST<T>::find_function(node<T>* root, T value,T* finD)
{
    if(root == nullptr) {
    return false;
    }
    if(value == root->m_item ) {
    finD = &root->m_item;
    return true;
    }
    find_function(root->m_left, value, finD);
    find_function(root->m_right, value, finD);
}

template<typename T>
void BST<T>::row(node<T>* root, int value)
{
    if(root == nullptr) {
    return;
    }
    if(value == 0) {
    std::cout << 0 << std::endl;
    return;
    }
    if(value > 0) {
    row(root->m_left,value - 1);
    row(root->m_right,value - 1);
    }
}

template<typename T>
void BST<T>::containS(node<T>* obj)
{
    if(obj == nullptr) {
    return;
    }
    vec.push_back(obj->m_item);
    containS(obj->m_left);
    containS(obj->m_right);
}

template<typename T>
void BST<T>::Merge(node<T>* obj1, node<T>* obj2)
{
    if(obj2 == nullptr) {
    return;
    }
    push(obj1,obj2->m_item);
    Merge(obj1, obj2->m_left);
    Merge(obj1, obj2->m_right);
}

template<typename T>
void BST<T>::number_of_nodes(node<T>* obj)
{
    if (obj == nullptr) {
    return;
    }
    ++number_nodes;
    number_of_nodes(obj->m_left);
    number_of_nodes(obj->m_right);
}

template<typename T>
int BST<T>::get__height(node<T>* height)
{
    if(height == nullptr) {
    return 0;
    }
    int num = get__height(height->m_left);
    int sum = get__height(height->m_right);
    if(num > sum) {
    return num + 1;
    }
    return sum + 1;
}

template<typename T>
 void BST<T>::print_root(node<T>* obj, int value)
{
    if (obj == nullptr) {
    return;
    }
    if(value == 2) {
    vec.push_back(obj->m_item);
    }
    print_root(obj->m_left,value);
    if(value == 1) {
    vec.push_back(obj->m_item);
    }
    print_root(obj->m_right,value);
    if(value == 3) {
    vec.push_back(obj->m_item);
    }
}

template<typename T>
void BST<T>::erase_itr(T value, node<T>* root)
{
    for(auto itr = v_erase.begin(); itr != v_erase.end(); ++itr) {
    if(*itr != value) {
    insert(*itr);
    }
    }
}

template<typename T>
void BST<T>::erase_val(node<T>* obj)
{
   if (obj == nullptr) {
    return;
    }
    v_erase.push_back(obj->m_item);
    erase_val(obj->m_right);
    erase_val(obj->m_left);
    delete obj;
    obj = nullptr;
}

template<typename T>
bool BST<T>::bool_equal(node<T>*& obj1, node<T>*& obj2)
{
    if(obj1 == nullptr && obj2 == nullptr) {
    return true;
    }
    if(obj1 == nullptr) {
    equal = true;
    return false;
    }
    if(obj2 == nullptr) {
    equal = true;
    return false;
    }
    if(obj1->m_item != obj2->m_item) {
    equal = true;
    return false;
    }
    bool_equal(obj1->m_left, obj2->m_left);
    bool_equal(obj1->m_right, obj2->m_right);
    if(equal) {
    return false;
    }
    return true;
}
template<typename T>
void BST<T>::pushvector(const node<T>* add, std::vector<T>& outitem)
{
    if (add == nullptr) {
    return ;
    }
    outitem.push_back(add->m_item);
    pushvector(add->m_left, outitem);
    pushvector(add->m_right, outitem);
}

template<typename T>
void BST<T>::amount(node<T>* add1, node<T>* add2, node<T>*& add, std::vector<T>& outitem)
{
    if(add1 == nullptr && add2 == nullptr) {
    return;
    }
    if(add1 == nullptr) {
    pushvector(add2, outitem);
    return;
    }
    if(add2 == nullptr) {
    pushvector(add1, outitem);
    return;
    }
    add = new node<T>(add1->m_item + add2->m_item);
    amount(add1->m_left, add2->m_left, add->m_left, outitem);
    amount(add1->m_right, add2->m_right, add->m_right, outitem);
}

template<typename T>
void BST<T>::delete_root(node<T>* droot)
{
    if(droot == nullptr) {
    return;
    }
    delete_root(droot->m_left);
    delete_root(droot->m_right);
    delete droot;
    droot = nullptr;
}

template<typename T>
void BST<T>::copy(node<T>*& root, node<T>* croot)
{
    if(croot == nullptr){
    root = nullptr;
    return ;
    }
    root = new node<T>(croot->m_item);
    copy(root->m_left, croot->m_left);
    copy(root->m_right, croot->m_right);
}

template<typename T>
void BST<T>::push(node<T>*& root, T value)
{
    if (root == nullptr) {
    root = new node<T>(value);
    return;
    }
    if(value < root->m_item) {
    push(root->m_left, value);
    }
    if(value > root->m_item) {
    push(root->m_right, value);
    }
}

template<typename T>
void BST<T>::vector_print()
{
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
    std::cout << *it << " " ;
    }
}

template<typename T>
bool BST<T>::Contains(T value) {
    for(auto itr = vec.begin(); itr != vec.end(); ++itr) {
    if(*itr == value) {
    return true;
    }
    }
    vec.clear();
    return false;
}

template<typename T>
T BST<T>::get_height()
{
    T height_value = get__height(root);
    return height_value;
}

template<typename T>
void BST<T>::get_number_of_nodes()
{
    number_of_nodes(root);
    std::cout << number_nodes <<std::endl;
}

template<typename T>
T BST<T>::get_root_data()
{
    if(root == nullptr) {
    return 0;
    }
    return root->m_item;
}

template<typename T>
bool BST<T>::contains(T value)
{
    containS(root);
    return Contains(value);
}

template<typename T>
T* BST<T>::find(T value)
{
    T* finD;
    if(!find_function(root, value, finD)) {
    std::cout << "There is no such number" << std::endl;
    finD = nullptr;
    return finD;
    }
    return finD;
}

template<typename T>
void BST<T>::add_value(node<T>* item,  T value, node<T>*& new_item)
{
    if(item == nullptr) {
        return;
    }
    new_item = new node<T>(item->m_item + value);
    add_value(item->m_left, value, new_item->m_left);
    add_value(item->m_right, value, new_item->m_right);
}
