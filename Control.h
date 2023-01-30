#ifndef CONTROL_H
#define CONTROL_H

#include "AnimalCanBreakdown.h"
#include "FarmRegBreakdown.h"
#include "HorsesPoniesSubreg2016.h"
#include "ReportGenerator.h"
#include "View.h"

/*
    Class       : Control
    Description : This class is the control class responsible for controlling the flow of this program,
                  that is computing reports requested of the user.
*/

class Control {
   public:
    Control();
    ~Control();

    /*
        Function: launch
        Purpose : Uses view to display a UI to the user, from which it will call upon the required functions
                  from the user with user given input.
    */
    void launch();

   private:
    View view;
    vector<ReportGenerator*> reports;
};

#endif
