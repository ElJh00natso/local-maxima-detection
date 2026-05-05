#include <vector>
#include <iostream>
#include <random>
#include <sstream>
#include "ERatioAthAlgTool.h"




int main(){
    //array data
    StripsData strips_array(100);
    
    //method to fill data to array_energy
    strips_array.fillArrayEnergy();

    //this is for debug
    std::stringstream ss;
    for(auto& energy : strips_array.array_energy){
        ss << energy.getEnergy() << " ";
    }
    std::cout << ss.str() << std::endl;


}

void StripsData::fillArrayEnergy(){
    
    //This is for the data, because i cant use here the data o .root archives that i use in Athena
    std::random_device rd;
    std::mt19937 gen(rd());
    //range 25 -- 125
    std::uniform_int_distribution<> dist(25,125);
    
    array_energy.clear();
    array_energy.reserve(length);
    
    for(int i = 0; i< length; i++ ){
        array_energy.emplace_back(Calocell((dist(gen)), i));
    }
}

void ERatioAthAlgTool::searchMaxLocal(const StripsData& data, std::vector<Calocell>& maxlocal){
    // a local maxima is a Calocell where their companions has less energy
    for(int i = 1; i < data.getLength() - 1;){
        if(data.array_energy[i].getEnergy()>data.array_energy[i-1].getEnergy() &&
           data.array_energy[i].getEnergy()>data.array_energy[i+1].getEnergy() )
           {
            //if you find a local maxima the next Calocell itsn´t a local maxima
            maxlocal.push_back(data.array_energy[i]);
            i+=2;
           }else{
            i++;
           }
    }
    
    std::stringstream localmaxima;
    for(auto& max : maxlocal){
        localmaxima << max.getEnergy() << " ";
    }
    std::cout<< localmaxima.str()<< std::endl;

}



void ERatioAthAlgTool::realCandidates(std::vector<Calocell> maxlocal){

}




