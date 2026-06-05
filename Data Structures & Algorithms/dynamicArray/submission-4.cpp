class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;
public:

    DynamicArray(int capacity) : capacity(capacity) {
        arr = new int[capacity];
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity){
            resize();
        }
        arr[size] = n;
        size++;

    }

    int popback() {
        if(size > 0){
            size--;
        }
        return arr[size];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for(int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;

    }

    int getCapacity() {
        return capacity;
    }
};