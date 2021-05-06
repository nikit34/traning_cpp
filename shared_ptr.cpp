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
            this->counter = new Counter(1);
        }
        SharedPtr(const SharedPtr& ref){
            this->Reset();
            this->ptr = ref;
            this->cointer->count = ref.counter;
            ++this->cointer->count;
        }
        SharedPtr& operator=(const SharedPtr& ref){
            this->Reset();
            this->ptr = ref;
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
        struct Counter{
            int count = 0;

            ~Counter(){
                std::cout << "~Counter()";
            }
        };

        T* ptr = nullptr;
        Counter* counter = nullptr;
};

void func(){
    SharedPtr<A> ptr;
}

int main() {
    {
        func();


        // worked
        UniquePtr<A> a_ptr(new A);
        decltype(a_ptr) b_ptr = std::move(a_ptr);

        // this do prohibitions on constructors
        // decltype(a_ptr) b_ptr(a_ptr);
        // decltype(a_ptr) b_ptr = a_ptr;
    }
    return 0;
}