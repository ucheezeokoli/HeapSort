#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int MaxHeapify(vector<int>& FreeSpace, int i, int size)
{
    int left  = (2*i) + 1;
    int right = (2*i) + 2;
    int largest = i;
    int temp; 

    if (left <= size)
    {
        if (FreeSpace.at(left) > FreeSpace.at(i))
        {
            largest = left;
        }
        else
        {
            largest = i;
        }
    }
    
    if (right <= size)
    {
        if (FreeSpace.at(right) > FreeSpace.at(largest))
        {
            largest = right;
        }
    }
    
    if (largest != i)
    {
        temp = FreeSpace.at(i);
        FreeSpace.at(i) = FreeSpace.at(largest);
        FreeSpace.at(largest) = temp;
        MaxHeapify(FreeSpace, largest, size);
    }
       
}

int BuildMaxHeap(vector<int>& FreeSpace, int size)
{
    int i;
    for (i = (FreeSpace.size() / 2); i >= 0; i--)
    {
        MaxHeapify(FreeSpace, i, size);
    }
}

int HeapSort(vector<int>& FreeSpace, int size)
{
    BuildMaxHeap(FreeSpace, size);
    int i, temp;
    for (i = size; i >= 1; i--)
    {
        temp = FreeSpace.at(0);
        FreeSpace.at(0) = FreeSpace.at(i);
        FreeSpace.at(i) = temp;
        size--;
        MaxHeapify(FreeSpace, 0, size);
    }
}

int main()
{
    int start = 0;
    int size;
    cin >> size;

    vector<int> FreeSpace(size); // DECLARE VECTOR WITH SIZE FROM INPUT

    // FILL VECTOR W/ VALUES
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> FreeSpace.at(i);
    }

    size--;

    HeapSort(FreeSpace, size);

    for (i = 0; i < FreeSpace.size(); i++)
    {
        cout << FreeSpace.at(i) << ";";
    }
}