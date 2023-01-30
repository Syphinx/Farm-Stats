#ifndef ANIMALCANBREAKDOWN_H
#define ANIMALCANBREAKDOWN_H

#include "ReportGenerator.h"

/*
    Class       : AnimalCanBreakdown
    Description : This concrete class is a report derived from the reportgenerator class responsible for generating and listing 
                  the animal type percentage breakdown for Canada, and for each animal type, the percentage change from 2011 to 2016
*/
class AnimalCanBreakdown : public ReportGenerator {
   public:
    AnimalCanBreakdown();
    ~AnimalCanBreakdown();

    /*
        Function: compute
        Purpose : Computes the necessary statistics needed to populate the reportdata
    */
    virtual void compute();
    virtual void printReport();

   private:
    ReportData<float> *repData;
    void formatData(float, string);

    /*  
        Function: getAnimDenom
        Purpose : Computes and returns by reference the denominator for the requested animal
        In      : String corresponding to the animal being searched for, or the total.
        Out  : Float by which the denominator if found is returned through.
    */
    void getAnimDenom(int, float &);
};

#endif