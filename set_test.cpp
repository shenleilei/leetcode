#include<set>
using namespace std;

struct Node
{
    int key;
    int value;
    Node(int k, int v) : key(k), value(v) {}
};

struct cmp
{
    bool operator()(const Node & l, const Node & r) const 
    {
        return l.key < r.key || (l.key == r.key && l.value < r.value);
    }
};

int main()
{
    set<Node, cmp> S;
    S.insert(Node(1, 1));
}
