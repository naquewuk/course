#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>

class Transport{
public:
    Transport(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxSpeed, int tmp_fuelConsumption, int tmp_comfort);

    ~Transport() {};

    virtual std::string getBrand() const { return brand; }
    virtual std::string getModel() const { return model; }
    virtual int getWeight() const { return weight; }
    virtual int getMaxSpeed() const { return maxSpeed; }
    virtual int getFuelConsumption() const { return fuelConsumption; }
    virtual int getComfort() const {return comfort; }

    void setBrand(std::string tmp_brand) { brand = tmp_brand; }
    void setModel(std::string tmp_model) { model = tmp_model; }
    void setWeight(int tmp_weight) { weight = tmp_weight; }
    void setMaxSpeed(int tmp_maxspeed) {maxSpeed = tmp_maxspeed; }
    void setFuelConsumtion(int tmp_fuelconsumption) { fuelConsumption = tmp_fuelconsumption; }
    void setComfort(int tmp_comfort){ comfort = tmp_comfort; }

    virtual std::string Info() const;

    enum Type{
        Vehicle,
        Motorcycle,
        Truck,
        Bus
    };

    Type getType() const { return type; }

protected:
    Type type;

    virtual void checkInfo();

private:
    std::string brand;
    std::string model;
    int weight;
    int maxSpeed;
    int fuelConsumption;
    int comfort;
};

#endif

