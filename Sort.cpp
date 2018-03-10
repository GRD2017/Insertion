#include <iostream>

using namespace std;

template <typename T>
void printArray(T * array, int size, const std::string& space)
{
    for (int i = 0; i != size; ++i)
    {
        if (i != size - 1)
            std::cout << array[i] << space;
        else
            std::cout << array[i];
    }

    std::cout << std::endl;
}

template <typename T>
void numberSort(T * array, int size)
{
    printArray(array, size, " ");

    for (int i = 1; i != size; ++i)
    {
        std::cout << std::endl << "Iteration: " << i << std::endl;

        T tmp = array[i];
        int j = i - 1;

        bool bDone = false;
        do
        {
            if ( array[j] > tmp )
            {
                array[j+1] = array[j];
                printArray(array, size, " ");
                j -= 1;

                if (j < 0)
                    bDone = true;
            }
            else
                bDone = true;
        }
        while (!bDone);

        array[j+1] = tmp;
        printArray(array, size, " ");
    }

    printArray(array, size, "-");
}

int main()
{
    int array[] = {1, -2, 50, 2, 45, 6, 10, 20, -4, 5}; //Array to sort
    int size = sizeof(array)/sizeof(int);

    numberSort<int> (array, size);
}
