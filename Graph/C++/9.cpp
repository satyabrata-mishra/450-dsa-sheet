#include <vector>
#include <map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    Node *clone(Node *node, map<Node *, Node *> &track)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (track.find(node) != track.end())
        {
            return track[node];
        }
        Node *copy = new Node(node->val);
        track[node] = copy;
        for (Node *neighbour : node->neighbors)
        {
            copy->neighbors.push_back(clone(neighbour, track));
        }
        return copy;
    }

public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> track;
        return clone(node, track);
    }
};