#include<iostream>
#include<tuple> // for tuple
using namespace std;

class RowDefinition {
    public:
    // Overload + operator to add two Box objects.
    constexpr int operator[](const string& key) {
        return 0;
    }
};

int main()
{
    string s = "123";

    RowDefinition rd;
    constexpr int a = rd[s];

    // Declaring tuple
    tuple <char, int, float> geek;
  
    // Assigning values to tuple using make_tuple()
    geek = make_tuple('a', 10, 15.5);

    // Printing initial tuple values using get()
    cout << "The initial values of tuple are : ";
   
    cout << get<a>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;
  
    // Use of get() to change values of tuple
    get<0>(geek) = 'b';
    get<2>(geek) =  20.5;
  
     // Printing modified tuple values
    cout << "The modified values of tuple are : ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;
  
    return 0;
}
