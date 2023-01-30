#ifndef RECORD_H
#define RECORD_H

#include "defs.h"

/*
    Class       : Record
    Description : This class is responsible for storing a single record (line), about farm and animals statistics
                  for a given year, region, abricultural sub-region, and type of animal.
*/

class Record {
    friend ostream& operator<<(ostream&, Record&);

   public:
    Record(int, string, string, string, int, int);
    ~Record();

    int getYear() const;
    string getRegion() const;
    string getSubRegion() const;
    string getAnimalType() const;
    int getNumFarms() const;
    int getNumAnimals() const;

   private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};

#endif
