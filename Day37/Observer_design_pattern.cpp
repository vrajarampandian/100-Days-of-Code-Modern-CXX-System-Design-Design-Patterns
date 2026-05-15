#include<iostream>
#include<vector>
using namespace std;

class Observer
{
    public:
    virtual void update(string str) = 0;
    virtual ~Observer() = default;
};

class Subscriber : public Observer
{
    string name;
    public:
    Subscriber(string n) : name(n){}
    void update(string str) override
    {
        cout << name << " received: " << str << "\n";
    }
};

class Youtubechannel
{
    vector<Observer*> observers;
    public:
    void subscribe(Observer *ob)
    {
        observers.push_back(ob);       
    }
    void notify(string msg) {
        for(auto o : observers) {
            o->update(msg);
        }
    }
};

int main()
{
    Youtubechannel channel;
    Subscriber   s1("Raja");
    Subscriber s2("Ram");
    channel.subscribe(&s1);
    channel.subscribe(&s2);
    channel.notify("New video upload");
    return 0;
}
