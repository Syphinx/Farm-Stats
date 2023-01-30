#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "CompareBehaviour.h"
#include "Map.h"
#include "ReportData.h"

/*
    Class       : ReportGenerator
    Description : This abstract control class serves as a base class for the hierarchy of control objects responsible for report generation.
*/
class ReportGenerator {
   public:
    virtual ~ReportGenerator();
    /*
        Function: populateCollection
        Purpose : This virtual function is implemeneted by every concrete class derived from this base class to compute the corresponding report.
    */
    virtual void compute() = 0;
    /*
        Function: printReport
        Purpose : This virtual function is implemeneted by every concrete class derived from this base class to output to both standard output and a file the corresponding report generated.
    */
    virtual void printReport() = 0;
    /*
        Function: populateCollection
        Purpose : This static function populates both the main collection of records, 
                  as well as several maps organized to cater for generation of specific reports.
    */
    static void populateCollection();
    static void cleanup();

   protected:
    static Map<int> yearMap;
    static Map<string> regionMap;
    static Map<string> animalMap;
    static vector<Record *> recordCollection;
};

#endif