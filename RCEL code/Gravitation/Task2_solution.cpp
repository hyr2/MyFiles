#include <iostream>
#include <cmath>
#include <string> 

using namespace std;   

class Body {          // The class
  public:             // Access specifier
    string Name;        
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double Mass;
    double Radius;
    
    // <Your code goes here>
    void Body::compute_acc(double x,double y,double & ax,double & ay){
    ax = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (x-pos_x)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
    ay = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (y-pos_y)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
    }
};

int main(){
    
    return 0;
}
