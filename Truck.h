#ifndef TRUCK_H
#define TRUCK_H

#include "Transport.h"

class Truck : public Transport{
public:
    Truck(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort,
          int tmp_carryingCapacity);

    ~Truck() {};

    int getCarryingCapacity() const { return carryingCapacity; }

    void setCarryingCapacity( int tmp_carryingCapacity) { carryingCapacity = tmp_carryingCapacity; }

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int carryingCapacity;

};

#endif