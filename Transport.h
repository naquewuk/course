#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

class Transport{
public:
    Transport(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption);

    virtual std::string getbrand() const { return brand; }
    virtual std::string getmodel() const { return model; }
    virtual int getWeight() const { return weight; }
    virtual int getMaxSpeed() const { return maxspeed; }
    virtual int getFuelConsumption() const { return fuelconsumption; }

    void setbrand(std::string tmp_brand) { brand = tmp_brand; }
    void setmodel(std::string tmp_model) { model = tmp_model; }
    void setWeight(int tmp_weight) { weight = tmp_weight; }
    void setMaxSpeed(int tmp_maxspeed) {maxspeed = tmp_maxspeed; }
    void setFuelConsumtion(int tmp_fuelconsumption) { fuelconsumption = tmp_fuelconsumption; }

    virtual std::string Info() const;

protected:
    virtual void checkInfo();

private:
    std::string brand;
    std::string model;
    int weight;
    int fuelconsumption;
    int maxspeed;
};

