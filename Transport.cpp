#include "Transport.h"

Transport::Transport(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumtion, int tmp_comfort) :
    brand(tmp_brand),
    model(tmp_model),
    weight(tmp_weight),
    maxSpeed(tmp_maxSpeed),
    fuelConsumption(tmp_fuelConsumtion),
    comfort(tmp_comfort)

{
    checkInfo();
}

std::string Transport::Info() const
{
    std::stringstream ss;

    ss << "Trasport:\nBrand: " << brand
       << "\nModel: " << model
       << "\nMax Speed of " << brand << ": " << maxSpeed
       << "\nFuel Consumption(per 100 km): " << fuelConsumption
       << "\nWeight of " << brand << " is about: " << weight
       << "\nComfort: " << comfort;

    return ss.str();
}

void Transport::checkInfo()
{
    if(weight <= 0)
        throw std::invalid_argument("Error..\nWeight cannot be less than 0.");

    if(maxSpeed <= 0)
        throw std::invalid_argument("Error..\nMax speed cannot be so small.");

    if(fuelConsumption <= 0 )
        throw std::invalid_argument("Error..\nWrong fuel consumption.");
}