#ifndef BUS_H
#define BUS_H

#include "Transport.h"

class Bus : public Transport{
public:
    Bus(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort,
        int tmp_passengersNumber, bool tmp_conditionPresence, bool tmp_recliningSeats, int tmp_seatingComfort, int tmp_maxBaggageForPassenger);

    ~Bus() {};

    int getPassengersNumber() const { return passengersNumber; }
    bool getConditionPresense() const { return conditionPresense; }
    bool getRecliningSeats() const { return recliningSeats; }
    int getSeatingComfort() const { return seatingComfort; }
    int getMaxBaggageForPassenger() const { return maxBaggageForPassenger; }

    void setPassengersNumber(int tmp_passengersnumber) { passengersNumber = tmp_passengersnumber; }
    void setConditionPresense(int tmp_conditionpresense ){ conditionPresense = tmp_conditionpresense; }
    void setRecliningSeats(int tmp_recliningseats){ recliningSeats = tmp_recliningseats; }
    void setSeatingComfort(int tmp_seatingcomfort) { seatingComfort = tmp_seatingcomfort; }
    void setMaxBaggageForPassenger(int tmp_maxbaggageforpassenger) { maxBaggageForPassenger = tmp_maxbaggageforpassenger; }

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int passengersNumber;
    bool conditionPresense;
    bool recliningSeats;
    int seatingComfort;
    int maxBaggageForPassenger;
};

#endif