#ifndef TEMPERATUREINDICATOR_H
#define TEMPERATUREINDICATOR_H
#include <iostream>

using namespace std;

class TemperatureIndicator
{
    public:
        TemperatureIndicator();
        virtual ~TemperatureIndicator();
        void setTempValue(int tempValue);
        int getTempValue();

        friend ostream & operator<<(ostream & os, const TemperatureIndicator & t);
        friend istream & operator>>(istream & is, TemperatureIndicator & ti);
    
    protected:
    private:
    int tempValue;
};

#endif // TEMPERATUREINDICATOR_H
