#include <iostream>

#include "ArrayListWrapper.hpp"

using namespace std;

int main()
{
    ArrayList<int> arrayList(5, 5);
    arrayList.addToEnd(1);
    arrayList.addToEnd(2);
    arrayList.addToEnd(3);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(4, 3);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(5, 0);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(6, 3);
    arrayList.insert(7, 4);
    arrayList.insert(8, 0);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.removeAt(0);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(9, 4);
    arrayList.insert(10, 0);
    arrayList.insert(11, 9);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.removeAt(4);
    arrayList.removeAt(8);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(69, 3);
    arrayList.insert(69, 4);
    arrayList.insert(69, 0);
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.insert(69, arrayList.getSize());
    arrayList.printArray();
    cout << "-----------" << endl;
    arrayList.removeAll(69);
    arrayList.printArray();
    cout << "-----------" << endl;
    
    ArrayList<int> newList(arrayList);
    newList.printArray();
    cout << "-----------" << endl;
    
    cout << "taco14";
    
    return 0;
}
