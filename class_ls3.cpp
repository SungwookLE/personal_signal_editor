#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.141591

// TODO: Declare abstract class VehicleModel
  // TODO: Declare virtual function Move()
class VehicleModel{
    public:
    virtual void Move(double vect, double thet)  =0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel{
    public:
    void Move(double vect, double thet)  override {
         theta += thet;
         x+=vect*cos(theta);
         y+=vect*cos(theta);
         return; }

    double x;
    double y;
    double theta;
};
  // TODO: Override the Move() function
  // TODO: Define x, y, and theta

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel{
    public:
    void Move(double vect, double thet)  override { theta += vect/L * tan(thet); x+=vect*cos(theta); y+=vect*cos(theta);}

   
    double x;
    double y;
    double theta;
    double L=5;

};
  // TODO: Override the Move() function
  // TODO: Define L


// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI/9);
  bicycle.Move(10, PI/9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
  return 0;
}