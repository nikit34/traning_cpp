#include <iostream>


template<typename T>
class UniquePtr {
    public:
        UniquePtr(){
            ptr = nullptr;
        }
        UniquePtr(T* ptr){
            this->ptr = ptr;
        }

    private:
        T* ptr;
};

int main() {
    return 0;
}