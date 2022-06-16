#include "Bus.h"

Bus::Bus(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption, int tmp_comfort,
             int tmp_passengersNumber, bool tmp_conditionPresence, bool tmp_recliningSeats, int tmp_seatingComfort,
             int tmp_maxBaggageForPassenger) :
        Transport(tmp_brand, tmp_model, tmp_weight, tmp_fuelconsumption, tmp_maxspeed, tmp_comfort),
        passengersNumber(tmp_passengersNumber),
        conditionPresense(tmp_conditionPresence),
        recliningSeats(tmp_recliningSeats),
        seatingComfort(tmp_seatingComfort),
        maxBaggageForPassenger(tmp_maxBaggageForPassenger)

{
    checkInfo();
}

std::string Bus::Info() const
{
    return "Vehicle:\nBrand: " + getBrand()
       + "\nModel: " + getModel()
       + "\nMaxSpeed" + std::to_string(getMaxSpeed())
       + "\nFuel Consumption(per 100 km): " + std::to_string(getFuelConsumption())
       + "\nWeight of " + getBrand() + " is about " + std::to_string(getWeight())
       + "\nMax number of a passengers: " + std::to_string(passengersNumber)
       + "\nCondition Presence: " + std::string((conditionPresense == true) ? "Yes." : "No.")
       + "\nPresense of reclining seats: " + std::string((recliningSeats == true) ? "Yes." : "No.")
       + "\nVision Convenience: " + std::to_string(seatingComfort)
       + "\nMax baggage for one passenger: " + std::to_string(maxBaggageForPassenger);
}

void Bus::checkInfo()
{
    Transport::checkInfo();

    if(passengersNumber <= 0)
        throw std::invalid_argument("Error..\nPassengers number can't be equal or less than 0.");

    if(seatingComfort < 0)
        throw std::invalid_argument("Error..\nGrade can't be less than 0.");

    if(maxBaggageForPassenger <= 0)
        throw std::invalid_argument("Error..\nMax baggage for passenger can't be equar or less than 0.");

}


