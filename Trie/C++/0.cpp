#include <string>
using namespace std;
class Node
{
    Node *links[26];
    bool isLast = false;

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        isLast = true;
    }

    bool getEnd()
    {
        return isLast;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (char i : word)
        {
            if (!node->containsKey(i))
            {
                node->put(i, new Node());
            }
            node = node->get(i);
        }
        node->setEnd();
    }

    bool search(string &word)
    {
        Node *node = root;
        for (char i : word)
        {
            if (!node->containsKey(i))
            {
                return false;
            }
            node = node->get(i);
        }
        return node->getEnd();
    }

    bool isPrefix(string &word)
    {
        Node *node = root;
        for (char i : word)
        {
            if (!node->containsKey(i))
            {
                return false;
            }
            node = node->get(i);
        }
        return true;
    }
};
int main()
{
    return 0;
}
