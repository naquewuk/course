#include "Truck.h"

Truck::Truck(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption,
             int tmp_carryingCapacity):
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelConsumption, tmp_maxSpeed),
        carryingCapacity(tmp_carryingCapacity)
{
    checkInfo();
}


std::string Truck::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << getBrand()
       << "\nModel: " << getModel()
       << "\nMaxSpeed" << getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << getFuelConsumption()
       << "\nWeight of " << getBrand() << " is about " << getWeight()
       << "\nCarrying_capacity: " << carryingCapacity;

    return ss.str();
}

void Truck::checkInfo(){

    Transport::checkInfo();

    if(carryingCapacity <= 0)
        throw std::invalid_argument("Error..\nCarrying Capacity can't be equal or less than 0");
}

