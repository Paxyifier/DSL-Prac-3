#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = index;
    do {
        if (hashTable[i] == -1) {
            hashTable[i] = key;
            return;
        }
        i = (i + 1) % TABLE_SIZE;
    } while (i != index);
    cout << "Error: Hash table is full." << endl;
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
    insert(12);
    insert(25);
    insert(36);
    insert(49);
    insert(50);
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << hashTable[i] << " ";
    }
    cout << endl;
    return 0;
}
