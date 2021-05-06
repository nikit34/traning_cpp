#include <iostream>


class A{
    public:
        A(){
            std::cout << "A()" << std::endl;
        }
        ~A(){
            std::cout << "~A()" << std::endl;
        }
};

template<typename T>
class UniquePtr {
    public:
        UniquePtr(){
            ptr = nullptr;
        }
        UniquePtr(T* ptr){
            this->ptr = ptr;
        }
        UniquePtr(UniquePtr&& ref) {
            this->ptr = ref.ptr;
            ref.ptr = nullptr;
        }
        UniquePtr& operator=(UniquePtr&& ref){
            this->ptr = ref.ptr;
            ref.ptr = nullptr;
            return *this;
        }

        ~UniquePtr(){
            delete this->ptr;
        }

        // prohibits constructor of copy
        UniquePtr(const UniquePtr&) = delete;
        // throught equally
        UniquePtr& operator=(const UniquePtr&) = delete;

    private:
        T* ptr;
};


int main() {
    {
         // worked
        UniquePtr<A> a_ptr(new A);
        decltype(a_ptr) b_ptr = std::move(a_ptr);

        // this do prohibitions on constructors
        // decltype(a_ptr) b_ptr(a_ptr);
        // decltype(a_ptr) b_ptr = a_ptr;
    }
    return 0;
}