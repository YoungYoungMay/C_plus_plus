//对list容器实现迭代器以访问list-》带头的双向循环链表

#include <iostream>
using namespace std;

template<class T>
struct ListNode
{
    ListNode<T>* _next;
    ListNode<T>* _prev;
    T _data;

    ListNode(const T& x)
        :_prev(NULL)
         ,_next(NULL)
         ,_data(x)
    {}
};

template<class T>
struct _ListIterator//迭代器
{
    typedef ListNode<T> Node;
    typedef _ListIterator<T> Self;
    Node* _node;
    _ListIterator(Node* node)
        :_node(node)
    {}

    T& operator*()//迭代器中的解引用
    {
        return _node->_data;
    }

    Self operator++()
    {
        _node = _node->_next;
        return *this;
    }

    bool operator !=(const Self& s)
    {
        return _node != s._node;
    }
};

template<class T>
class List
{
    typedef ListNode<T> Node;
    public:
        typedef _ListIterator<T> Iterator;
        Iterator Begin()//迭代器的begin()
        {
            return Iterator(_head->_next);
        }

        Iterator End()//迭代器的end()
        {
            return Iterator(_head);
        }

        List()
        {
            _head = new Node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }

        void PushBack(const T& x)//尾插
        {
            Insert(End(), x);
        }

        void Insert(Iterator pos, const T& x)
        {
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* new_node = new Node(x);

            prev->_next = new_node;
            new_node->_prev = prev;
            new_node->_next = cur;
            cur->_prev = new_node;
        }

    private:
        Node* _head;
};

void Test()
{
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    l.PushBack(4);

    List<int>::Iterator it = l.Begin();
    while(it != l.End())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}

int main()
{
    Test();
    return 0;
}
