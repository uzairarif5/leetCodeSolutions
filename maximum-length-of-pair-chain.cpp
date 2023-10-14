#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node { 
public: 
    vector<int> value; 
    Node* next;
    int index;

    Node(vector<int> data, Node * newNext) { 
        this->value = data; 
        this->next = newNext; 
    }

};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        Node * curNode = new Node(pairs[0], NULL);
        Node * headerNode = new Node({NULL,NULL}, curNode);
        int i;
        for(i=1;i<pairs.size();i++){
            curNode = headerNode->next;
            Node * prevNode = headerNode;
            bool inserted = false;
            while(!inserted){
                if(curNode==NULL){ //reached tail
                    curNode = new Node(pairs[i], NULL);
                    prevNode->next = curNode;
                    inserted = true;
                }
                if(pairs[i][0] < curNode->value[0]){//first value of pair < first value of current node
                    Node * tempNode = new Node(pairs[i], curNode);
                    prevNode->next = tempNode;
                    inserted = true;
                }
                prevNode = prevNode->next;
                curNode = curNode->next;
            }
            curNode = headerNode->next;
        }

        int counter = 0;
        while(curNode!=NULL){
            curNode->index = counter;
            curNode = curNode->next;
            counter += 1;
        }

        vector<vector<int>> pairChildren;
        pairChildren.resize(pairs.size());
        for(i=0;i<pairs.size();i++){
            counter = 1;
            headerNode = headerNode->next;
            curNode = headerNode->next;
            int compareVal = headerNode->value[1];
            while(curNode!=NULL){
                if(compareVal<curNode->value[0]) pairChildren[i].push_back(curNode->index);
                curNode = curNode->next;
                counter += 1;
            }
        }

        int maxPathArr[pairs.size()];
        maxPathArr[pairs.size()-1] = 1;
        for(i = 0;i<pairs.size()-1;i++) maxPathArr[i] = 0;
        for(i = pairChildren.size()-2;i>=0;i--){
            if(pairChildren[i].size()){
                for(int j =0;j<pairChildren[i].size();j++){
                    if(maxPathArr[pairChildren[i][j]] >= maxPathArr[i]) maxPathArr[i] = maxPathArr[pairChildren[i][j]]+1;
                }
            }
            else{maxPathArr[i] = 1;}
        }        
        int maxPath = 0;
        for(i=0;i<pairs.size();i++) if(maxPath < maxPathArr[i]) maxPath = maxPathArr[i];
        return maxPath;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> pairs;
    pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout <<"sol: "<< sol.findLongestChain(pairs) << endl;
    pairs = {{10, 20}, {7, 8}, {4, 5}};
    cout  <<"sol: "<< sol.findLongestChain(pairs) << endl;
    pairs = {{3, 4}, {1, 2}, {2, 3}, {6, 7}};
    cout  <<"sol: "<< sol.findLongestChain(pairs) << endl;
    pairs = {{8,9} ,{-10,-8}, {-5,0}, {6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    cout  <<"sol: "<< sol.findLongestChain(pairs) << endl;
    pairs = {{5,9},{-1,8},{-6,-2},{8,9},{4,8},{3,6},{2,6},{5,9},{-1,6},{-8,-7}};
    cout  <<"sol: "<< sol.findLongestChain(pairs) << endl;
    return 0;
}
