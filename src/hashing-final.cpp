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
        cout << "3. Exit" << endl;
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
