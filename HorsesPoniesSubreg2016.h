#ifndef HORSESPONIESSUBREG2016
#define HORSESPONIESSUBREG2016

#include "ReportGenerator.h"

/*
    Class       : HorsesPoniesSubreg2016
    Description : This concrete class is a report derived from the reportgenerator class responsible for generating and listing 
                  the sub-region, within each region, that hosted the highest number of horses and ponies in 2016.
*/
class HorsesPoniesSubreg2016 : public ReportGenerator {
   public:
    HorsesPoniesSubreg2016();
    ~HorsesPoniesSubreg2016();
    /*
        Function: compute
        Purpose : Computes the necessary statistics needed to populate the reportdata
    */
    virtual void compute();
    virtual void printReport();

   private:
    ReportData<int> *repData;
    void formatData(int, string);
};

#endif
