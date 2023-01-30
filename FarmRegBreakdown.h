#ifndef FARMREGBREAKDOWN_H
#define FARMREGBREAKDOWN_H

#include "ReportGenerator.h"

/*
    Class       : FarmRegBreakdown
    Description : This concrete class is a report derived from the reportgenerator class responsible for generating and listing the
                  regional percentage breakdown of farms that hosted animals of each type in 2016.
*/
class FarmRegBreakdown : public ReportGenerator {
   public:
    FarmRegBreakdown();
    ~FarmRegBreakdown();
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
        Function: computeDenoms
        Purpose : calculates the denominators needed for each region-animal pair initially to reduce redundant computation, and through the use of
                  a parallel vector structure, stores this data for retrieval in the primary compute function. An animal at index i corresponds to 
                  the denomintor (total farms hosting said animal across every region) at index i in the vector of denoms.
    */
    void computeDenoms();

    /*
        Function: grabDenom
        Purpose : Finds the index correlating with the animal for which the denominator needs to be retrieved from, and returns by reference this value.
        In      : String corresponding to the animal being searched for, or the total.
        Out  : Float by which the denominator if found is returned through.
    */
    void grabDenom(string, float &);
    void cleanup();
    vector<float> reportDenoms;
};

#endif