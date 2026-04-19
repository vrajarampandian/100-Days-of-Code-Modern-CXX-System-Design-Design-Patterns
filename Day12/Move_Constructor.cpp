#include<iostream>
using namespace std;

class Resource
{
    int *data;
    public:
    Resource(int v){
        data = new int(v);
    }
    Resource(Resource && obj)
    {
        data = obj.data;
        obj.data = nullptr;
        cout << "Move Constructor" << "\n";
    }
    ~Resource()
    {
        delete data;
    }
};

int main()
{
    Resource R1(30);
    Resource R2 = std::move(R1); //move
    //Without Move Constructor - Expensive (deep copy)
    return 0;
}