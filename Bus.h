#include "Transport.h"

class Bus : public Transport{
public:
    Bus(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
        int tmp_passengersnumber, bool tmp_conditionerpresence, bool tmp_recliningseats, int tmp_visionsconvenience, int tmp_maxbaggageforpassenger);

    int getPassengersNumber() const { return passengersnumber; }
    bool getConditionPresense() const { return conditionpresense; }
    bool getRecliningSeats() const { return recliningseats; }
    int getVisionsConvenience() const { return visionsconvenience; }
    int getMaxBaggageForPassenger() const { return maxbaggageforpassenger; }

    void setPassengersNumber(int passengersnumber) { this->passengersnumber = passengersnumber; }
    void setConditionPresense(int conditionpresense ){ this->conditionpresense = conditionpresense; }
    void setRecliningSeats(int recliningseats){ this->recliningseats = recliningseats; }
    void setVisionsConvenience(int visionsconvenience) { this->visionsconvenience = visionsconvenience; }
    void setMaxBaggageForPassenger(int maxbaggageforpassenger) { this->maxbaggageforpassenger = maxbaggageforpassenger; }

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int passengersnumber;
    bool conditionpresense;
    bool recliningseats;
    int visionsconvenience;
    int maxbaggageforpassenger;
};