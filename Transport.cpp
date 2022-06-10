#include "Transport.h"

Transport::Transport(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumtion ) :
    brand(tmp_brand),
    model(tmp_model),
    weight(tmp_weight),
    maxspeed(tmp_maxspeed),
    fuelconsumption(tmp_fuelconsumtion)

{
    checkInfo();
}

std::string Transport::Info() const
{
    std::stringstream ss;

    ss << "Trasport:\nBrand: " << brand
       << "\nModel: " << model
       << "\nMax Speed of " << brand << ": " << maxspeed
       << "\nFuel Consumption(per 100 km): " << fuelconsumption
       << "\nWeight of " << brand << " is about: " << weight;

    return ss.str();
}

void Transport::checkInfo()
{
    if(weight <= 0)
        throw std::invalid_argument("Error..\nWeight cannot be less than 0.");

    if(maxspeed <= 0)
        throw std::invalid_argument("Error..\nMax speed cannot be so small.");

    if(fuelconsumption <= 0 || fuelconsumption >= 100)
        throw std::invalid_argument("Error..\nWrong fuel consumption.");
}