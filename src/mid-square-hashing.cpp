#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;
const int LEN = 100;
int countDigit(int num){
    int i = 0;
    while (num != 0){
        i++;
        num/=10;
    }
    return i;
}
int extractDigits(int x, int count){
    return (int) fmod(x,pow(10,count/2+1))/pow(10,count/2-1);
}
int hashf(int x)
    {
        int square = x*x;
        int count = countDigit(square);
        if (count>2){
            return fmod(square, pow(10,count/2+1))/ pow(10,count/2-1);
        }
        return square;
    }

class HashArray
{
protected:
    int arr[LEN];
    int countDigit(int num){
        int i = 0;
        while (num != 0){
            i++;
            num/=10;
        }
        return i;
    }
    int hash(int x)
    {
        int square = x*x;
        int count = this->countDigit(square);
        if (count>2){
            return fmod(square, pow(10,count/2+1))/ pow(10,count/2-1);
        }
        return square;
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
    HashArray(){
        for(int i = 0;i<LEN;i++)
            this->arr[i]=NULL;
    }
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
                 cout << "Cannot add hash due to collision with other members" <<  endl;
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
         cout <<  endl;
    }
};

int main()
{
    int x;

    bool run =true;
    int op = 0;
    HashArray hashArray;
    while (run)
    {
         cout << "1. Insert" <<  endl;
         cout << "2. Display" <<  endl;
         cout << "3. Exit" <<  endl;
         cout << "Enter your choice" <<  endl;
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
