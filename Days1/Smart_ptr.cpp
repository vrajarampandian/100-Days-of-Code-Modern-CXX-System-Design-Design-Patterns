#include<iostream>
using namespace std;

template <typename T>
class Uniqueptr
{
    private:
        // Raw pointer that this object exclusively owns.
        T *ptr;
    public:
        // Take ownership of the incoming raw pointer.
        explicit Uniqueptr(T *p = nullptr) : ptr(p) {}
        ~Uniqueptr()
        {
            // Release the owned object when the smart pointer goes out of scope.
            delete ptr;
        }

        // Unique ownership means copying is not allowed.
        Uniqueptr(const Uniqueptr &) = delete;
        Uniqueptr &operator=(const Uniqueptr &) = delete;


        Uniqueptr(Uniqueptr && other)
        {
            cout << "call Move constructor" <<"\n";
            // Transfer ownership from the source object to this one.
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        Uniqueptr & operator=(Uniqueptr && other)
        {
            if(this != &other)
            {
                // Free the currently owned object before taking new ownership.
                delete *ptr;

                ptr = other.ptr;
                other.ptr = nullptr;
            }
        }

        T& operator*() const {
            return *ptr;
        }
        T* operator->() const{
            return ptr;
        }
        T* get() const {
            return ptr;
        }

};

class Test
{
    public:
    Test() {
        cout << "constructor" << "\n";
    }
    ~Test() {
        cout << "Destructor" << "\n";
    }

    void sayhello() {
        cout << "Hello test" << "\n";
    }
};

int main()
{
    // Create a smart pointer that owns a Test object.
    Uniqueptr<Test> tobj(new Test());
    tobj->sayhello();

    // Ownership moves from tobj to tobj2.
    Uniqueptr<Test> tobj2 = std::move(tobj);
    
    // After the move, the old smart pointer should no longer own anything.
    if(tobj.get() == nullptr)
        cout << "p1 is null after move";

    return 0;
}
