#pragma once

#include "Transport.h"

class Motorcycle : public Transport{
public:
    Motorcycle(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
               bool tmp_strollerpresence);

    ~Motorcycle() {};

    bool getstrollerpresence(){ return strollerpresence; }

    void setstrollerpresence(bool m_strollerpresence) { strollerpresence = m_strollerpresence;}

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    bool strollerpresence;


};