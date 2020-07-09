#include <iostream>
using namespace std; 

// <Your code goes here>
class car {
  public:
    int weight;
    string color;
    string body;
    double fuel;
  
  void refuel(double add_fuel){
    fuel = fuel + add_fuel;
  }
};

int main(){
  
  return 0;
}