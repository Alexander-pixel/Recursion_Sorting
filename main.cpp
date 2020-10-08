#include <iostream>
#include <time.h>
using namespace std;

template <typename T, typename T1>
auto Find(T arr, T1 element, int left, int right) -> decltype(arr)
{
    int index = (left+right)/2;
    T1 middle = arr[index];
    
    if(left == index)
    {
        if(arr[left+1] == element)
        {
            return arr+(left+1);
        }
        else if (arr[left] == element)
        {
            return arr+(left);
        }
        else
        {
            return NULL;
        }
    }
    
    if(middle == element)
    {
        return arr+index;
    }
    else if (middle>element)
    {
        Find(arr, element, left, index); // рассматриваем левую часть массива
    }
    else
    {
        Find(arr, element, index, right);
    }
    
    return 0;

}

void Print(char *str, int l, int r, int level)
{
    if(level == 0)
        return;
    
    int middle = (l+r)/2;
    str[middle] = '|';
    Print(str, l, middle, level-1);
    Print(str, middle, r, level-1);
}

template <typename T>
void QuickSort(T arr, int l, int r)
{
    int i, j;
    
    i = l; // beginning of array
    j = r; // the end of array
    
    int middle = arr[(i+j)/2];
    
    do{
        while(middle > arr[i])
        {
            i++;
        }
        while(middle < arr[j])
        {
            j--;
        }
        
        if(i<=j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }while(i<j);
    
    if(i<r)
    {
        QuickSort(arr, i, r);
    }
    if(j>l)
    {
        QuickSort(arr, l, j);
    }
}

int main() {
    
    const int arrSize = 30000000;
    int* arr = new int[arrSize];
    double t1 = clock();
    
    for(int i=0; i<arrSize; i++)
    {
        arr[i] = i;
    }
    double t2 = clock() - t1;
    cout<<"Время в секундах прохождение цикла: " << t2/CLOCKS_PER_SEC << endl;
    
    t1 = clock();
    int *parr = Find(arr, 1, 0, arrSize);
    t2 = t2  = clock() - t1;
    cout<<"Время в секундах нахождения элемента: "<< t2/CLOCKS_PER_SEC << endl;
    
    if(parr == NULL)
    {
        cout<< "Элемент не найден!"<< endl;
    }
    else
    {
        cout<<"Искомый элемент: "<< *parr<<endl;
    }
    
    
    /*
    int arrSize = 1000000;
    int *arr = new int[arrSize];
    
    srand(time(NULL));
    
    for(int i=0; i<arrSize; i++)
    {
        arr[i] = rand();
    }
    
    double time1 = clock();
    QuickSort(arr, 0, arrSize-1);
    double time2 = clock() - time1;
    
    cout << time2/CLOCKS_PER_SEC;
    */
    
    delete [] arr;
    /*
    char str[66];
    str[65] = '\0';
    
    int min, max;
    min = 0;
    max = 64;
    
    str[min] = str[max] = '|';
    
    for(int i=1; i<64; i++)
    {
        str[i] = ' ';
    }
 
    cout << str << endl;
    
    for(int i=1; i<=6; i++)
    {
        Print(str, min, max, i);
        cout<<str<<endl;
        
        for(int i=1; i<64; i++)
        {
            str[i] = ' ';
        }
    }
     */
    
}
