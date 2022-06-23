#pragma once

#include "Transport.h"

class Motorcycle : public Transport{
public:
    Motorcycle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort,
               bool tmp_strollerPresence);

    ~Motorcycle() {};

    std::string getStrollerPresence(){ return (strollerPresence == true) ? "Yes." : "No." ; }

    void setStrollerPresence(bool tmp_strollerpresence) { strollerPresence = tmp_strollerpresence; }

    bool canTransport(int passengersnumber, int baggage) override;

    int prior() const override;

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    bool strollerPresence;
};