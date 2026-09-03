class Solution {
    Node* cloned[101] = {};

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (cloned[node->val])
            return cloned[node->val];

        Node* copy = new Node(node->val);
        cloned[node->val] = copy;

        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};
