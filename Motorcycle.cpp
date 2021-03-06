#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,int tmp_comfort,
                        bool tmp_strollerpresence) :
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_maxspeed, tmp_fuelconsumption, tmp_comfort),
        strollerPresence(tmp_strollerpresence)
{
    checkInfo();
}

bool Motorcycle::canTransport(int passengersnumber, int baggage)
{
    return passengersnumber <= 2 && baggage <= 15;
}

std::string Motorcycle::Info() const
{
    std::stringstream ss;

    ss << "Motorcycle:\nBrand: " << getBrand()
       << "\nModel: " << getModel()
       << "\nMaxSpeed: " << getMaxSpeed()
       << "\nFuel Consumption(per 100 km): " << getFuelConsumption()
       << "\nWeight of " << getBrand() << " is about " << getWeight()
       << "\nThe presence of a stroller: " << ((strollerPresence == 1) ? "Yes." : "No.")
       << "\nComfort: " << getComfort();

    return ss.str();
}

void Motorcycle::checkInfo(){
    Transport::checkInfo();
}

int Motorcycle::prior() const {
    return 100;
}
