#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    Node* next;
};

unordered_map<int, Node*> hashTable;

int hashFunction(int key) {
    return key % 10;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = NULL;
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node
temp = hashTable[index];
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
}
int main() {
insert(12);
insert(25);
insert(36);
insert(49);
insert(50);
for (int i = 0; i < 10; i++) {
Node* temp = hashTable[i];
while (temp != NULL) {
cout << temp->key << " ";
temp = temp->next;
}
cout << endl;
}
return 0;
}
