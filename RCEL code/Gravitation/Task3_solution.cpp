#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "matplotlibcpp.h"

using namespace std; 
namespace plt = matplotlibcpp;

// Declaring global constants
const double G = 6.67408e-11;             // Gravitational constant
const double SUN_MASS = 1.989e30;         // Mass of the sun
const double SUN_RADIUS = 695700000.0;    // Radius of the sun
const double SUN_X0 = 0;                  // X coordinate of the sun
const double SUN_Y0 = 0;                  // Y coordinate of the sun
const double SUN_VX0 = 0;                 // X component of the sun's velocity
const double SUN_VY0 = 0;                 // Y component of the sun's velocity
const double EARTH_MASS = 5.972e24;       // Mass of the Earth
const double EARTH_RADIUS = 6371000.0;    // Radius of the Earth
const double EARTH_X0 = -147095000000.0;  // X coordinate of the Earth
const double EARTH_Y0 = 0.0;              // Y coordinate of the Earth
const double EARTH_VX0 = 0.0;             // X component of Earth's velocity
const double EARTH_VY0 = -30038.6;        // Y component of Earth's velocity
const double dt = 86400.0;                // 1 earth day in seconds

class Body {          // The class
  public:             // Access specifier
    string Name;        
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double Mass;
    double Radius;
        
    //Function
    void compute_acc(double x,double y,double & ax,double & ay);
    void step(double dt, Body * sun);
};

void Body::compute_acc(double x,double y,double & ax,double & ay){
    ax = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (x-pos_x)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
    ay = G*SUN_MASS/(pow(pos_x-x,2)+pow(pos_y-y,2)) * (y-pos_y)/sqrt(pow(pos_x-x,2)+pow(pos_y-y,2));
}
void Body::step(double dt, Body * sun){
    double k1x, k1y, k2x, k2y, k3x, k3y, k4x, k4y;
    double k1vx, k1vy, k2vx, k2vy, k3vx, k3vy, k4vx, k4vy;
    
    // Computing coefficients for 4th order Runge-Kutta integrator
    k1x = vel_x;
    k1y = vel_y;    
    sun->compute_acc(pos_x, pos_y, k1vx, k1vy);    // k1vx, k1vy
    k2x = vel_x - dt/2 * (k1vx);
    k2y = vel_y - dt/2 * (k1vy);    
    sun->compute_acc( pos_x + dt/2 * k1x , pos_y + dt/2 * k1y , k2vx , k2vy);    // k2vx, k2vy
    k3x = vel_x - dt/2 * (k2vx);
    k3y = vel_y - dt/2 * (k2vy);    
    sun->compute_acc( pos_x + dt/2 * k2x , pos_y + dt/2 * k2y , k3vx , k3vy);    // k3vx, k3vy
    k4x = vel_x - dt * (k3vx);
    k4y = vel_y - dt * (k3vy);    
    sun->compute_acc( pos_x + dt * k3x , pos_y + dt * k3y , k4vx , k4vy);        // k4vx, k4vy
    
    // finding position and velocity at next time step using Runge-Kutta Numerical Integration
    pos_x = pos_x + dt/6 * (k1x + 2*k2x + 2*k3x + k4x);
    pos_y = pos_y + dt/6 * (k1y + 2*k2y + 2*k3y + k4y);
    vel_x = vel_x - dt/6 * (k1vx + 2*k2vx + 2*k3vx + k4vx);
    vel_y = vel_y - dt/6 * (k1vy + 2*k2vy + 2*k3vy + k4vy);
}

int main(){
  double Ax, Ay;
  // <Your code goes here>
  Body earth, sun;      // creating the two celestial bodies
  // updating attributes
  earth.Name = "Earth";
  earth.pos_x = EARTH_X0;
  earth.pos_y = EARTH_Y0; 
  earth.vel_x = EARTH_VX0;
  earth.vel_y = EARTH_VY0;
  earth.Mass = EARTH_MASS;
  earth.Radius = EARTH_RADIUS;
  // updating attributes
  sun.Name = "Sun";
  sun.pos_x = SUN_X0;
  sun.pos_y = SUN_Y0; 
  sun.vel_x = SUN_VX0;
  sun.vel_y = SUN_VY0;
  sun.Mass = SUN_MASS;
  sun.Radius = SUN_RADIUS;

  // This block of code generates the output. Its a nice and easy self-check
  cout << "    1st Body\n";
  cout << "Name:\t" << earth.Name << "\n";
  cout << "X:\t" << earth.pos_x << " m" << "\n";
  cout << "Y:\t" << earth.pos_y << " m" << "\n";
  cout << "V_x:\t" << earth.vel_x << " m/s" << "\n";
  cout << "V_y:\t" << earth.vel_y << " m/s" << "\n";
  cout << "Mass:\t" << earth.Mass << " Kg" << "\n";
  cout << "Radius:\t" << earth.Radius << " m" << "\n";
  cout << "    2nd Body\n";
  cout << "Name:\t" << sun.Name << "\n";
  cout << "X:\t" << sun.pos_x << " m" << "\n";
  cout << "Y:\t" << sun.pos_y << " m" << "\n";
  cout << "V_x:\t" << sun.vel_x << " m/s" << "\n";
  cout << "V_y:\t" << sun.vel_y << " m/s" << "\n";
  cout << "Mass:\t" << sun.Mass << " Kg" << "\n";
  cout << "Radius:\t" << sun.Radius << " m" << "\n";



  return 0;
}