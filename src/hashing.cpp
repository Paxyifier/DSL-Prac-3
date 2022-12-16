#include <iostream>
using namespace std;
const int LEN = 29;
class HashArray
{
protected:
    int arr[29] = {NULL};
    int hash(int x)
    {
        return arr[x] % LEN;
    }
    int insertCollision(int hash)
    {
        for (int i = hash; i < LEN; i++)
        {
            if (arr[i] == NULL)
            {
                return i;
            }
        }
        return -1;
        // mod
        // mid square
        // multiplication
        // folding
    }
    int findCollision(int hash, int k)
    {
        for (int i = hash+1; i < LEN; i++)
        {
            if (arr[i] == k){
                return i;
            }
        }
    }
    int removeCollision(int hash, int k){
        for (int i = hash+1; i < LEN; i++)
        {
            if (this->hash(arr[i])==hash){
                for (int j = i+1; j < LEN; j++){
                    if (this->hash(arr[j])==hash){
                        arr[j-1] = arr[j];
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
    }

public:
    void insert(int x)
    {
        int hash = this->hash(x);
        if (arr[hash] == NULL)
        {
            arr[hash] = x;
        }
        else
        {
            int collide = this->insertCollision(hash);
            if (collide != -1)
            {
                arr[collide] = x;
            }
            else
            {
                cout << "Cannot add hash due to collision with other members" << endl;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < LEN; i++)
        {
            if (arr[i] != NULL)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    int search(int k)
    {
        int hash = this->hash(k);
        if (arr[hash] == NULL)
        {
            return -1;
        }
        else if (arr[hash] == k)
        {
            return hash;
        }
        else
        {
            return this->findCollision(hash, k);
        }
    }
    int remove(int k){
        int hash = this->hash(k);
        if (arr[hash] == k){
            arr[hash] = NULL;
            return 1;
        }
        else {
            this->removeCollision(hash,k);
        }
    }
};

int main()
{
    bool run =true;
    int op = 0;
    HashArray hashArray;
    while (run)
    {
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Search" << endl;
        cout << "4. Remove" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int x;
                cout << "Enter the element to be inserted : " ;
                cin >> x;
                hashArray.insert(x);
                break;
            }
            case 2:
            {
                cout << "The elements in hashArray are : " ;
                hashArray.display();
                break;
            }
            case 3:
            {
                int k;
                cout << "Enter the element to be searched: " ;
                cin >> k;
                op = hashArray.search(k);
                if (op == -1) {
                    cout << "Element not found" << endl;
                }
                break;
            }
            case 4:
            {
                int k;
                cout << "Enter the element to be removed : ";
                cin >> k;
                hashArray.remove(k);
                break;
            }
            case 5:
            {
                run = false;
                break;
            }
            default:
            {
                run = false;
                break;
            }
        }
    }
    return 0;
}
