// duplicate remover
/*
Write a c++ function remove_duplicates(input_list) that takes a list input_list as input and removes any 
duplicate elements, preserving the original order. The function should return a new list with duplicates removed. 
remove_duplicates([1, 2, 2, 3, 4, 4, 5]) # Should return [1, 2, 3, 4, 5]
*/
#include <iostream>
using namespace std;
template <class T>
struct array{
    T* p;
    int size;
};
template <class T>
void copy_array(T* list1, T** list2, int size){
    for(int i = 0; i < size; i++){
        list2[0][i] = list1[i];
    }
}
template <class T>
void display(T* list, int size){
    for(int i = 0; i < size; i++){
        cout << ' ' << (i + 1) << ". " << list[i] << endl;
    }
}
template <class T>
void display(array<T> list){
    display(list.p, list.size);
}
template <class T>
void sort(T** list, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(list[0][i] < list[0][j]){
                swap(list[0][i], list[0][j]);
            }
        }
    }
}
template <class T>
void sort(array<T>* list){
    sort(&list->p, list->size);
}
template <class T>
void dup_rem(array<T>* list){
    sort(&list->p, list->size);
    int* duplicate_indices = new int[list->size];
    int count = 0;
    for(int i = 0; i < list->size; i++){
        for(int j = 0; j < list->size; j++){
            if(i == j)continue;
            if(list->p[i] == list->p[j]){
                if(i > j){
                    break;
                }
                duplicate_indices[count++] = j;
            }
        }
    }
    int original_size = list->size;
    T* temporary_list = new T[original_size - count];
    int count2 = 0;
    for(int i = 0; i < list->size; i++){
        bool not_duplicate = true;
        for(int j = 0; j < count; j++){
            if(i == duplicate_indices[j]){
                not_duplicate = false;
                break;
            }
        }
        if(not_duplicate){
            temporary_list[count2++] = list->p[i];
        }
    }
    delete list->p;
    list->p = new int[original_size - count];
    list->size = original_size - count;
    copy_array(temporary_list, &list->p, original_size - count);
}
template <class T>
void accept(array<T>* list){
    cout << " Enter " << list->size << " elements:\n";
    for(int i = 0; i < list->size; i++){
        cout << ' ' << (i + 1) <<". ";
        cin >> list->p[i];
    }
}
int main(){
    array<int> numbers;
    int length;
    cout << " Enter number of integers to enter: ";
    cin >> length;
    numbers.size = length;
    accept(&numbers);
    cout << " ======================================================\n";
    cout << " Original array_list\n";
    display(numbers);
    cout << "\n ======================================================\n";
    sort(&numbers);
    cout << " sorted array_list\n";
    display(numbers);
    cout << "\n ======================================================\n";
    cout << " Duplicate removed array_list\n";
    dup_rem(&numbers);
    display(numbers);
    cout << "\n ======================================================\n";
}