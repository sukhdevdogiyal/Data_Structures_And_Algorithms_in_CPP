#include <iostream>
using namespace std;
class Nstack
{
public:
    int *arr;
    int size;
    int k;
    int *top;
    int *next;
    int freespot;
    Nstack(int s, int n)
    {
        size = s;
        k = n;
        arr = new int[size];
        top = new int[k];
        next = new int[size];
        freespot = 0;
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }

    bool push(int x, int m)
    {
        // check overflow condition
        if (freespot == -1)
            return false;

        // find index
        int index = freespot;

        // insert in array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        // underflow condition
        if (top[m - 1] == -1)
            return -1;

        // find index
        int index = top[m - 1];

        // update top
        top[m - 1] = next[index];

        // update next
        next[index] = freespot;

        // update freespot
        freespot = index;

        return arr[index];
    }
};

int main(int argc, char const *argv[])
{
    Nstack s1 = Nstack(6, 3);
    cout << "Push 10 in stack 2 : " << s1.push(10, 2) << endl;
    cout << "Push 20 in stack 1 : " << s1.push(20, 1) << endl;
    cout << "Push 30 in stack 2 : " << s1.push(30, 2) << endl;
    cout << "Push 40 in stack 1 : " << s1.push(40, 1) << endl;
    cout << "Pop in stack 2 : " << s1.pop(2) << endl;
    cout << "Push 50 in stack 1 : " << s1.push(50, 1) << endl;
    cout << "Pop in stack 1 : " << s1.pop(1) << endl;
    cout << "Next freespot : " << s1.freespot << endl;
    cout << "Pop in stack 1 : " << s1.pop(1) << endl;
    cout << "Next freespot : " << s1.freespot << endl;
    return 0;
}
