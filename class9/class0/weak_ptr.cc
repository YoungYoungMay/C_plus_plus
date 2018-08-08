//智能指针-》weak_ptr(boost)

#include <iostream>
#include <vector>
#include "shared_ptr.cc"
using namespace std;

template<class T>
class WeakPtr
{
    public:
        WeakPtr(const SharedPtr<T>& sp)
            :_ptr(sp._ptr)
        {}

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

    private:
        T* _ptr;
};

//循环引用
struct ListNode
{
    //ListNode* _prev;
    //ListNode* _next;

    //SharedPtr<ListNode> _next;
    //SharedPtr<ListNode> _prev;

    WeakPtr<ListNode> _next;
    WeakPtr<ListNode> _prev;

    ListNode()
        :_prev(NULL)
         ,_next(NULL)
    {}

    ~ListNode()
    {
        cout<<"~ListNode()"<<endl;
    }
};

void TestWeakPtr()
{
    //ListNode* cur = new ListNode;
    //ListNode* next = new ListNode;
    //cur->_next = next;
    //next->_prev = cur;

    SharedPtr<ListNode> cur(new ListNode);
    SharedPtr<ListNode> next(new ListNode);

    //循环引用
    cur->_next = next;
    next->_prev = cur;

}

int main()
{
    TestWeakPtr();
    return 0;
}
