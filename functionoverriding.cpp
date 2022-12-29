#include <iostream>
using namespace std;
class Mammal {
    public:
    void eat() 
    {
        cout << "Mammals eat...";
        }
        };
        class Cow: public Mammal {
            public:
            void eat() {
                cout << "Cows eat grass...";
                }
                };
                int main(void) {
                    Cow c = Cow();
                    c.eat();
                    return 0;
                }