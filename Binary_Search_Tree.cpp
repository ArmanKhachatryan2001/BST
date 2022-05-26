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
    BST() :
        root(nullptr)
    {}

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
    BST( BST<T>&& obj)     {
        root = obj.root;
        obj.root = nullptr;
    }
    BST& operator=(BST<T>& other)
    {
        copy(root,other.root);
        return *this;
    }
    BST& operator=(BST<T>&& other)
    {
        this->root = other.root;
        other.root = nullptr;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& output, BST<T>& obj)
    {
        obj.inorder();
        return output;
    }

    BST operator+(BST add)
    {
        BST<T> new_obj;
        amount(root, add.root, new_obj.root);
        return new_obj;
    }

    BST operator+=(BST plusequal)
    {
        amount(root, plusequal.root, root);
        return *this;
    }

    bool operator==( BST& equal)
    {
        bool true_false = bool_equal(root, equal.root);
        if(true_false) {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(BST& not_equal)
    {
        bool  equal = bool_equal(root, not_equal.root);
        if(equal) {
            return false;
    }
        else
        {
            return true;
        }
    }

    ~BST()
    {
        delete_root(root);
    }


    T* find(T value) {
        find_function(root, value);
        if(*finD != value) {
        std::cout << "There is no such number" << std::endl;
        finD = nullptr;
        }
        return finD;
    }

    void levelorder()
    {
       int height = get__height(root);
       for(int i = 0; i < height; ++i) {
            row(root,i);
       }
    }

    void contains(T value)
    {
         containS(root);
         Contains(value);
    }

    BST merge(BST<T> t) {
        Merge(root, t.root);
        return *this;
    }

    void get_root_data()
    {
        get_rooT_data(root);
    }
    void get_number_of_nodes()
    {
        number_of_nodes(root);
        std::cout << number_nodes <<std::endl;
    }
    void get_height()
    {
      int height_value = get__height(root);
      std::cout << height_value << std::endl;
    }
    void inorder()
    {
        print_root(root,1);
        vector_print();
        vec.clear();
    }
    void preorder()
    {
        print_root(root,2);
        vector_print();
        vec.clear();
    }
    void postorder()
    {
        print_root(root,3);
        vector_print();
        vec.clear();
    }
    void insert(T value)
    {
        push(root,value);
    }
    void clear()
    {
        delete_root(root);
        root = nullptr;
    }
    void erase(T val)
    {
        erase_val(root);
        root = nullptr;
        erase_itr(val,root);
    }
    bool equal = false;
    std::vector<T> v_erase;
    std::vector<T> vec;
    int number_nodes{};
    T* finD;

private:
    void find_function(node<T>* root, T value)
    {
        if(root == nullptr) {
            return ;
        }
        if(value == root->m_item ) {
            finD = &root->m_item;
        }
        find_function(root->m_left, value);
        find_function(root->m_right, value);
    }

    void row(node<T>* root, int value)
    {
        if(root == nullptr) {
            return;
        }
        if(value == 0) {
            get_rooT_data(root);
        }
        if(value > 0) {
            row(root->m_left,value - 1);
            row(root->m_right,value - 1);
        }
    }

    void containS(node<T>* obj)
    {
        if(obj == nullptr) {
            return;
        }
        vec.push_back(obj->m_item);
        containS(obj->m_left);
        containS(obj->m_right);
    }

    void Merge(node<T>* obj1, node<T>* obj2)
    {
        if(obj2 == nullptr) {
            return;
        }
        push(obj1,obj2->m_item);
        Merge(obj1, obj2->m_left);
        Merge(obj1, obj2->m_right);
    }

    void get_rooT_data(node<T>* root)
    {
        if(root != nullptr) {
            std::cout << root->m_item << " ";
            return;
        }
    }

    void number_of_nodes(node<T>* obj)
    {
        if (obj == nullptr) {
            return;
        }
        ++number_nodes;
        number_of_nodes(obj->m_left);
        number_of_nodes(obj->m_right);
    }

    int get__height(node<T>* height)
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

    void print_root(node<T>* obj, int value)
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

    void erase_itr(T value, node<T>* root)
    {
    for(auto itr = v_erase.begin(); itr != v_erase.end(); ++itr) {
       if(*itr != value) {
        push(root, *itr);
        }
       if(*itr == value) {
        v_erase.erase(itr);
        itr--;
       }
     }
    }

    void erase_val(node<T>* obj)
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

    bool bool_equal(node<T>*& obj1, node<T>*& obj2)
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
            return false;
        }
        bool_equal(obj1->m_left, obj2->m_left);
        bool_equal(obj1->m_right, obj2->m_right);
        if(equal) {
            return false;
        }
        return true;
    }

    void amount(node<T>* add1, node<T>* add2, node<T>*& add = nullptr)
    {
        if(add1 == nullptr && add2 == nullptr) {
            return;
        }
        if(add1 == nullptr) {
            add = new node<T>(add2->m_item);
            amount(nullptr, add2->m_left, add->m_left);
            amount(nullptr, add2->m_right, add->m_right);
            return;
        }
        if(add2 == nullptr) {
            add = new node<T>(add1->m_item);
            amount(add1->m_left, nullptr, add->m_left);
            amount(add1->m_right, nullptr, add->m_right);
            return;
        }
        add = new node<T>(add1->m_item + add2->m_item);
        amount(add1->m_left, add2->m_left, add->m_left);
        amount(add1->m_right, add2->m_right, add->m_right);
    }

    void delete_root(node<T>* droot)
    {
        if(droot == nullptr) {
            return;
        }
        delete_root(droot->m_left);
        delete_root(droot->m_right);
        delete droot;
        droot = nullptr;
    }

    void copy(node<T>*& root, node<T>* croot)
    {
        if(croot == nullptr){
            return ;
        }
        root = new node<T>(croot->m_item);
        copy(root->m_left, croot->m_left);
        copy(root->m_right, croot->m_right);
    }

    void push(node<T>*& root, T value)
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
    void vector_print()
    {
        for(auto it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " " ;
        }
    }

    void Contains(T value) {
        bool true_false;
        for(auto itr = vec.begin(); itr != vec.end(); ++itr) {
            if(*itr == value) {
                true_false = true;
                continue;
            }
         }
        vec.clear();
        if(true_false == 1) {
        std::cout << "1" << std::endl;
        } else {
        std::cout << "0" << std::endl;
        }
    }
};

int main()
{
    //node<int>oo; /// default constuctor
    BST <int>a= {15,13,14,20,7,2,8}; // initializer list
    int* arr = a.find(7);/////find()
    std::cout << a << std::endl;;//;??
    *arr = 99;
    std::cout << a << std::endl;;
    //std::cout << *pp;
    //a.get_height(); //// get_heiget()
   // a.find(2);////////////////?????????????????????????
    BST<int>c = {99,55,88};//= a; /// copy constructor
    a.contains(99); ///////////////////contains()
   // a.levelorder(); /////////// levelorder()
    //a.merge(c); ///////// merge()
   // c.clear();///////////////clear
    //a.insert(99);//////////// insert
    //c += a;/////////////////// operator +=
    //BST<int>d = a + c; ///////// operator +
    //std::cout << (c == a);
    //a.inorder(); /////////////// inorder()
    //std::cout  << std::endl;
    //a.preorder(); //////////////// preorder()
    //std::cout  << std::endl;
    //a.postorder(); //////////////// postorder()
    //a.get_number_of_nodes();/////////get_number_of_nodes ()
    //a.get_root_data(); ////////////// get_root_data()
    //std::cout  << std::endl;
    //a.levelorder();////???????
    //BST<int>b(std::move(a));//////// move
    //c = std::move(a); ///// move operator  =
    //c = a;  ////////////  copy operator =
    /*if(a == c){ //////// operator ==
        std::cout << " yes == " << std::endl;
    //c.insert(33);
    }
    if(a != c) { ////// operator !=
        std::cout << "yes != " << std::endl;
    }*/
    //a.erase(9);///////erase (x)
    // std::cout << c  << "\n" << a  << std::endl;////cout operator <<
    //std::cout << a << std::endl;
    return 0;
}
