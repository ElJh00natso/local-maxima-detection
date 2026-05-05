#include "Calocell.h"
#include <vector>
//a strips data has a phi.low , phi.high and phi.center but y considered transform in a array 1x1
class StripsData
{
private:
   int length;
   

public:
    std::vector<Calocell> array_energy;

    StripsData(int length_)
    :length(length_){}

    void fillArrayEnergy();

    double getLength() const{
        return length;
    }

};

