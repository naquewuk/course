#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed,
                       int tmp_fuelconsumption, bool tmp_strollerpresence) :
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed),
        strollerpresence(tmp_strollerpresence)
{
    checkInfo();
}


std::string Motorcycle::Info() const
{
    std::stringstream ss;

    ss << "Vehicle:\nBrand: " << Transport::getbrand()
       << "\nModel: " << Transport::getmodel()
       << "\nMaxSpeed" << Transport::getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << Transport::getFuelConsumption()
       << "\nWeight of " << Transport::getbrand() << " is about " << Transport::getWeight()
       << "\n The presence of a stroller: " << strollerpresence;
}
