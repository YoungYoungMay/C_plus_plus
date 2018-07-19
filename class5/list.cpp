//带头带环的双向链表
    //-》无死角
#include <iostream>
using namespace std;

typedef int DataType;

struct ListNode
{
    ListNode* _next;
    ListNode* _prev;
    DataType _data;

    ListNode(DataType x)
        :_data(x)
         ,_next(NULL)
         ,_prev(NULL)
    {}
};

class List
{
    typedef ListNode Node;
    public:
        List()//构造函数
            :_head(new Node(DataType()))//匿名对象?
        {
            cout<<"List()"<<endl;
            _head->_next = _head;
            _head->_prev = _head;
        }

        List(const List& l)//拷贝构造函数
        {
            cout<<"List(const List& l)"<<endl;
            _head = new Node(DataType());
            _head->_prev = _head;
            _head->_next = _head;
            Node* cur = l._head->_next;
            while(cur != l._head)
            {
                this->PushBack(cur->_data);
                cur = cur->_next;
            }
            //注意:这里并没有返回值
        }

        List& operator=(const List& l)
        {
            cout<<"List& operator=(const List& l)"<<endl;
            if(this != &l)
            {
               this->Clear();
               Node* cur = l._head->_next;
               while(cur != l._head)
               {
                   this->PushBack(cur->_data);
                   cur = cur->_next;
               }
            }
            return *this;
        }

        ~List()
        {
            cout<<"~List"<<endl;
            Clear();
            delete _head;
            _head = NULL;
        }

        void PushBack(DataType x)
        {
            Node* new_node = new Node(x);
            Node* back = _head->_prev;
            back->_next = new_node;
            new_node->_prev = back;
            new_node->_next = _head;
            _head->_prev = new_node;
        }

        void PushFront(DataType x)
        {
            Node* new_node = new Node(x);
            Node* front = _head->_next;
            new_node->_next = front;
            front->_prev = new_node;
            _head->_next = new_node;
            new_node->_prev = _head;
        }

        void PopBack()
        {
            if(Empty())
                return;
            Node* to_delete = _head->_prev;
            Node* pre = to_delete->_prev;
            pre->_next = _head;
            _head->_prev = pre;
            delete to_delete;
        }

        void PopFront()
        {
            if(Empty())
                return;
            Node* to_delete = _head->_next;
            Node* nex = to_delete->_next;
            _head->_next = nex;
            nex->_prev = _head;
            delete to_delete;
        }

        Node* Find(DataType x)
        {
            Node* cur = _head->_next;
            while(cur != _head)
            {
                if(cur->_data == x)
                    return cur;
            }
            return NULL;
        }

        void Insert(Node* pos, DataType x)
        {
            if(pos==NULL || pos==_head)
            {
                cout<<"Insert()->permission denied"<<endl;
                return;
            }
            //注意：这里很容易写错
            Node* new_node = new Node(x);
            Node* pre = pos->_prev;
            pre->_next = new_node;
            new_node->_prev = pre;
            new_node->_next = pos;
            pos->_prev = new_node;
        }

        void Erase(Node* pos)
        {
            if(Empty())
            {
                return; 
            }
            if(pos==NULL || pos==_head)
            {
                cout<<"Erase()->permission denied"<<endl;
                return;
            }
            Node* pre = pos->_prev;
            Node* nex = pos->_next;
            pre->_next = nex;
            nex->_prev = pre;
            delete pos;
        }

        void Clear()//清理数据
        {
            Node* cur = _head->_next;
            while(cur != _head)
            {
                //这里要注意顺序，要先把下一个结点保存起来，才可以进行删除操作
                Node* next_node = cur->_next;
                delete cur;
                cur = next_node;
            }
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
        
        bool Empty()
        {
            return _head->_prev==_head;
        }

        Node* head()
        {
            return _head;
        }

    private:
        Node* _head;
};

void Test()
{
    List l;
    l.PushBack(2);
    l.PushFront(1);
    l.PushBack(3);
    l.PushBack(4);
    l.PushFront(5);
    l.PushFront(6);
    l.Print();

    l.PopBack();
    l.Print();
    l.PopFront();
    l.Print();
    
    l.Insert(l.head()->_next->_next, 9);
    l.Print();
    l.Erase(l.head()->_next);
    l.Print();
    cout<<endl;

    List l1;
    l1 = l;
    l1.Print();
    cout<<endl;

    List l2 = l;
    l2.Print();

}

int main()
{
    Test();
    return 0;
}
