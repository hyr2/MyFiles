#include <iostream>
using namespace std; 

class car {
  public:
    unsigned int weight;
    string color;
    string body;
    double fuel;
  
    void refuel(double add_fuel){
      fuel = fuel + add_fuel;
    }
};

int main(){
  
  // <Your code goes here>
  
  car Lexus_ES350_FTG7677;   // Create object of type car
  car Tesla_Model3_CCV2544;  // Create a second object of type car
  
  // Add attributes
  Lexus_ES350_FTG7677.weight = 3649;
  Lexus_ES350_FTG7677.color = "Atomic Silver";
  Lexus_ES350_FTG7677.body = "Sedan";
  Lexus_ES350_FTG7677.fuel = 16.13;
  Tesla_Model3_CCV2544.weight = 3552;
  Tesla_Model3_CCV2544.color = "Pearl White";
  Tesla_Model3_CCV2544.body = "Sedan";
  Tesla_Model3_CCV2544.fuel = 13.75;
  
  cout << "Before refueling: ";
  cout << Lexus_ES350_FTG7677.fuel << " gal\n";
  Lexus_ES350_FTG7677.refuel(1.35);
  cout << "After refueling: ";
  cout << Lexus_ES350_FTG7677.fuel << " gal\n"; 
  
  
  return 0;
}
