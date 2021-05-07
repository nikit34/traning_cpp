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
class SharedPtr{
    public:
        SharedPtr(){
            this->ptr = nullptr;
            this->counter = new Counter{ 1 };
        }
        SharedPtr(T* ptr){
            this->ptr = ptr;
            this->counter = new Counter{ 1 };
        }
        SharedPtr(const SharedPtr& ref){
            this->Reset();
            this->ptr = ref.ptr;
            this->cointer->count = ref.counter;
            ++this->cointer->count;
        }
        SharedPtr& operator=(const SharedPtr& ref){
            this->Reset();
            this->ptr = ref.ptr;
            this->cointer->count = ref.counter;
            ++this->cointer->count;
            return *this;
        }

        ~SharedPtr(){
            this->Reset();
        }

        void Reset(){
            if (this->counter){
                if (--this->counter->count == 0) {
                    delete this->ptr;
                    delete this->counter;
                }
            }
        }

    private:
        struct Counter {
            int count = 0;

            ~Counter(){
                std::cout << "~Counter()";
            }
        };

        T* ptr = nullptr;
        Counter* counter = nullptr;
};

void func(){
    SharedPtr<A> ptr(new A);
    auto ptr1 = ptr;
    auto ptr2 = ptr;
    auto ptr3 = ptr;
    return;
}

int main() {
    func();

    return 0;
}