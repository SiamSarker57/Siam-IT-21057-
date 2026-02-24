#include <bits/stdc++.h>
using namespace std;


struct Node {
    string name;
    int cost; 
    bool solved; 

     
    vector<vector<Node*>> childrenOptions;
    vector<int> edgeCosts; 

    Node(string n, int h) : name(n), cost(h), solved(false) {}
};


vector<Node*> allNodes;


int calculateCost(Node* u) {
    if (u->solved || u->childrenOptions.empty()) {
        return u->cost;
    }

    int bestCost = INT_MAX;
    int bestOptionIndex = -1;

    
    for (int i = 0; i < u->childrenOptions.size(); ++i) {
        int currentOptionCost = u->edgeCosts[i]; 
        vector<Node*>& option = u->childrenOptions[i];

    
        for (Node* child : option) {
            currentOptionCost += calculateCost(child);
        }

        if (currentOptionCost < bestCost) {
            bestCost = currentOptionCost;
            bestOptionIndex = i;
        }
    }

    
    u->cost = bestCost;
    return bestCost;
}

void aStar(Node* root) {
    cout << "Expanding Node: " << root->name << " | Initial Heuristic: " << root->cost << endl;
    int minCost = calculateCost(root);
    cout << "Updated Cost for " << root->name << ": " << minCost << endl;
    root->solved = true;
}

int main() {
    
    Node* A = new Node("A", 100); 
    Node* B = new Node("B", 6);
    Node* C = new Node("C", 12);
    Node* D = new Node("D", 10);
    Node* E = new Node("E", 4);
    Node* F = new Node("F", 4);

    
    A->childrenOptions.push_back({B});
    A->edgeCosts.push_back(1);
 
    A->childrenOptions.push_back({C, D});
    A->edgeCosts.push_back(1);

     
    B->childrenOptions.push_back({E, F});
    B->edgeCosts.push_back(1);

     

    cout << "Starting AO* Search..." << endl;
     
    aStar(A);
    cout << "Final Cost of Optimal Solution: " << A->cost << endl;

    return 0;
}