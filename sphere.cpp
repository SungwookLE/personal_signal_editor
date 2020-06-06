#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere {
 public:
  // Constructor
  Sphere(int radius): radius_(radius) {volume_=pow(Radius(),3)*pi_ *4/3;}
  float Radius() const { return radius_;}
  float Volume() const { 
      std::cout << pow(Radius(),3)*pi_ *4/3<< std::endl;
      return volume_;}
  void Radius(int radius) {radius_=radius;}


  // Accessors

 private:
  // Private members
  float const pi_{3.141592};
  float radius_;
  float volume_;

  void validation(){
      if (radius_ < 0 || volume_ < 0)
        throw std::invalid_argument("NO");
  }

};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);


  sphere.Radius(3);
  sphere.Volume();
}