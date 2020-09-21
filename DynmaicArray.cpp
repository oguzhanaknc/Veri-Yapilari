#include<iostream>
#include<string>

using namespace std;

template<class T>
class A {
private:
    int len = 0;   // 0-(n-1) index değerleri.
    int cap = 0; // 1-n kullanıcıların gördüğü
    T *arr; //genel dizi

public:
    A(int cap) {
        cout << "Constructor Called" << endl;
        if (cap <= 0) {
            throw runtime_error("sadasd");
        }
        this->cap = cap;
        this->arr = new T[cap];
    }

    void set(int index, T elem) {
        arr[index] = elem;
    }

    T get(int index) {
        return arr[index];
    }

    bool isEmpty() {
        return this->size() == 0;
    }

    int size() {
        return this->len;
    }

    void clear() {
        for (int i = 0; i < len; i++) arr[i] = null;
        len = 0;
    }

    void add(T elem) {
        if (len + 1 >= cap) {
            if (cap == 0) cap = 1;
            else cap *= 2;
            T *new_arr = new T[cap];
            for (int i = 0; i < len; i++) {
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }

        arr[len++] = elem;
    }

    T removeAt(int rm_index) {
        if (rm_index > this->len || rm_index < 0) {
            throw out_of_range("ss");
        }
        T data = arr[rm_index];
        T *new_arr = new T[len - 1];
        for (int i = 0; i < len - 1; i++) {
            if (rm_index == i) {
                new_arr[i] = arr[i + 1];
            } else {

                new_arr[i] = arr[i];
            }
        }
        len--;
        arr = new_arr;
        return data;
    }

    int indexOf(T obj) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == obj) {
                return i;
            }
        }
        return -1;
    }

    bool contains(T elem) {
        return indexOf(elem) != -1;
    }

};

int main() {
    A<int> a(1);
    a.add(98);
    a.add(76);
    a.add(23);
    for (int i = 0; i < a.size(); ++i) {
        cout << a.get(i) << endl;
    }

    int yes = a.removeAt(1);
    cout << "-*/-*/-*/-*/-*/-*/-*/-*/-" << yes << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a.get(i) << endl;
    }

    return 0;
}