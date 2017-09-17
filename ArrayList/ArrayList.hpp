#ifndef ArrayList_hpp
#define ArrayList_hpp

template <typename T>
class ArrayList
{
public:
    ArrayList(int arraySize, int arrayIncrement);
    ArrayList(const ArrayList & copyList);
    ~ArrayList();
    void checkArray(int elementsToAdd);
    void addToEnd(T value);
    void insert(T Value, int index);
    void removeAt(int index);
    void removeAll(T value);
    int getSize();
    void printArray();
    //public
    
private:
    int currentSize;
    int totalSize;
    int increment;
    
    T * array;
    //private
};

#endif
