/*
https://leetcode.com/problems/clone-graph/submissions/
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* help(Node* node, unordered_map<Node*, Node*> &visited) {
        if (node==NULL)
            return NULL;
        auto found=visited.find(node);
        if (found!=visited.end()) {
            return found->second;
        }
        Node* cloned_node= new Node(node->val);
        visited[node]=cloned_node;
        
        for (auto x:node->neighbors) {
            (cloned_node->neighbors).push_back(help(x, visited));
        }
        return cloned_node;
        
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return help(node, visited);
    }
};
