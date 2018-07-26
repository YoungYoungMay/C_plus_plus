//模板实现list(带头带环的双向链表)

#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
struct ListNode
{
    ListNode<T>* _next;
    ListNode<T>* _prev;
    T _data;
    
    ListNode(const T& x)
    :_data(x)
    ,_prev(NULL)
    ,_next(NULL)
    {}
};

template<class T>
class List
{
        typedef ListNode<T> Node;
    public:
        List()//构造
        {
            _head = new Node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }

        void Insert(Node* pos, const T& x)//在pos的前面插入
        {
            assert(pos != NULL);
            Node* pre = pos->_prev;
            Node* new_node = new Node(x);
            pre->_next = new_node;
            new_node->_prev = pre;
            new_node->_next = pos;
            pos->_prev = new_node;
        }

        void Erase(Node* pos)
        {
            //头结点不能删除，除非是要删除整个链表结构
            assert(pos!=NULL && pos!=_head);
            Node* pre = pos->_prev;
            Node* nex = pos->_next;
            pre->_next = nex;
            nex->_prev = pre;
            delete pos;
        }

        void PushBack(const T& x)
        {
            Insert(_head, x);
        }

        void PushFront(const T& x)
        {
            Insert(_head->_next, x);
        }

        void PopBack()
        {
            Erase(_head->_prev);
        }

        void PopFront()
        {
            Erase(_head->_next);
        }

        Node* Back()
        {
            assert(!Empty());
            return _head->_prev;
        }

        T& Front()
        {
            assert(!Empty());
            return _head->_next->_data;
        }

        size_t Size()
        {
            size_t size = 0;
            Node* cur = _head->_next;
            while(cur != _head)
            {
                ++size;
                cur = cur->_next;
            }
            return size;
        }

        bool Empty()
        {
            return _head->_next == _head;
        }

        void Print()
        {
            Node* cur = _head->_next;
            while(cur != _head)
            {
                cout<<cur->_data<<" ";
                cur = cur->_next;
            }
            cout<<endl;
        }

    protected:
        Node* _head;
};

void Test()
{
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    l.Print();
    l.Insert(l.Back(), 4);
    l.Print();
    l.Erase(l.Back());
    l.Print();
}

int main()
{
    Test();
    return 0;
}
