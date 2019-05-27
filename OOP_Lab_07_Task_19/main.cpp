/*
 19. На основі контейнера vector побудувати одновимірний масив цілих чисел. Виконати
 операції введення елементів у масив, послідовний пошук заданого елемента у масиві і
 виведення його номера, виведення масиву на екран.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

void Output(vector<int> &MyVector);
void Search(vector<int> &MyVector, int N, int *I);

int main()
{
    
    vector<int> MyVector;
    
    ifstream o;
    o.open("/Users/dmytrenkoshome/Downloads/Xcode/OOP/OOP_Labs/OOP_Lab_07/OOP_Lab_07_Task_19/OOP_Lab_07_Task_19/file.txt");
    if (!o.is_open())
    {
        cout<<"\tThe file isn't open"<< endl;
    }
    else
    {
        cout<<"\tThe file is open"<< endl;
        int s;
        while (o >> s)
        {
            MyVector.push_back(s);
        }
    }
    
    int n = 11,i;
    Search(MyVector,n,&i);
    cout << "Елемент " << n <<" знаходиться під номером "<<(i+1)<<endl;
    Output(MyVector);
    int timer = clock();
    cout << "Програма працювала: " << ((float)timer) / CLOCKS_PER_SEC << " секунд" << endl;
    o.close();
    
    return 0;
}

void Search(vector<int> &MyVector, int N, int *I)
{
    bool f = false;
    for (vector<int>::iterator i = MyVector.begin(); i != MyVector.end(); i++)
    {
        if(N == *i)
        {
            f = true;
            *I = i - MyVector.begin();
            break;
        }
    }
}

void Output(vector<int> &MyVector)
{
    for (vector<int>::iterator i = MyVector.begin(); i != MyVector.end(); i++)
    {
        cout << *i << endl;
    }
}
