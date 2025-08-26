struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    Node* segregate(Node* head) {
        int zero = 0,one = 0,two = 0;
        while(head != nullptr){
            int data = head->data;
            if(data == 0)
                ++zero;
            else if(data == 1)
                ++one;
            else
                ++two;
            head = head->next;
        }
        Node *ans = new Node(0);
        Node *dummy = ans;
        while(zero--){
            dummy->next = new Node(0);
            dummy = dummy->next;
        }
        while(one--){
            dummy->next = new Node(1);
            dummy = dummy->next;
        }
        while(two--){
            dummy->next = new Node(2);
            dummy = dummy->next;
        }
        return ans->next;
    }
};