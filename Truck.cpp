#include "Truck.h"

Truck::Truck(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
             int tmp_carrying_capacity):
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed),
        carrying_capacity(tmp_carrying_capacity)
{
    checkInfo();
}


std::string Truck::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << Transport::getbrand()
       << "\nModel: " << Transport::getmodel()
       << "\nMaxSpeed" << Transport::getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << Transport::getFuelConsumption()
       << "\nWeight of " << Transport::getbrand() << " is about " << Transport::getWeight()
       << "\nCarrying_capacity: " << carrying_capacity;

    return ss.str();
}
void Truck::checkInfo(){

    Transport::checkInfo();

    if(carrying_capacity <= 0)
        throw std::invalid_argument("Error..\nCarrying Capacity can't be equal or less than 0");
}

