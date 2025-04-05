#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *nxt = head->next;
        head->next = nullptr;

        ListNode *last = reverseList(nxt);
        last->next = head;
        return last;
    }
};

int main(int, char **)
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    Solution s;
   ListNode* a= s.reverseList(root);

    std::cout << "Hello, from cpplean!\n";
}