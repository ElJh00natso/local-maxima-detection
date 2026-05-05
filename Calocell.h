
//The calocell are the energy in each cell in module 1 of the electromagnetic calorimeter
class Calocell{
    private:
        int energy;
        int position;

    public:
        Calocell(int _energy, int _position)
        :energy(_energy), position(_position){}

        double getEnergy() const{
            return energy;
        }
        
};