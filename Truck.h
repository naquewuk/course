#include "Transport.h"

class Truck : public Transport{
public:
    Truck(std::string tmp_brand, std::string tmp_model, int tmp_weight, int tmp_maxspeed, int tmp_fuelconsumption,
          int tmp_carrying_capacity);

    ~Truck() {};

    int getcarryingcapacity() const { return carrying_capacity; }

    void setcarryingcapacity( int m_carrying_capacity) { carrying_capacity = m_carrying_capacity; }

    std::string Info() const override;

protected:
    void checkInfo() override;

private:
    int carrying_capacity;

};