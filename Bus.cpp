#include "Bus.h"

Bus::Bus(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
             int tmp_passengersnumber, bool tmp_conditionerpresence, bool tmp_recliningseats, int tmp_visionsconvenience, int tmp_maxbaggageforpassenger) :
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed),
        passengersnumber(tmp_passengersnumber),
        conditionpresense(tmp_conditionerpresence),
        recliningseats(tmp_recliningseats),
        visionsconvenience(tmp_visionsconvenience),
        maxbaggageforpassenger(tmp_maxbaggageforpassenger)

{
    checkInfo();
}

std::string Bus::Info() const
{
    std::stringstream ss;

    return "Vehicle:\nBrand: " + Transport::getbrand()
       + "\nModel: " + Transport::getmodel()
       + "\nMaxSpeed" + std::to_string(Transport::getMaxSpeed())
       + "\nFuel Consumption(per 100 km): " + std::to_string(Transport::getFuelConsumption())
       + "\nWeight of " + Transport::getbrand() + " is about " + std::to_string(Transport::getWeight())
       + "\nMax number of a passengers: " + std::to_string(passengersnumber)
       + "\nCondition Presence: " + std::string((conditionpresense == true) ? "Yes." : "No.")
       + "\nPresense of reclining seats: " + std::string((recliningseats == true) ? "Yes." : "No.")
       + "\nVision Convenience: " + std::to_string(visionsconvenience)
       + "\nMax baggage for one passenger: " + std::to_string(maxbaggageforpassenger);
}

void Bus::checkInfo()
{
    Transport::checkInfo();

    if(passengersnumber <= 0)
        throw std::invalid_argument("Error..\nPassengers number can't be equal or less than 0.");

    if(visionsconvenience < 0)
        throw std::invalid_argument("Error..\nGrade can't be less than 0.");

    if(maxbaggageforpassenger <= 0)
        throw std::invalid_argument("Error..\nMax baggage for passenger can't be equar or less than 0.")

}


