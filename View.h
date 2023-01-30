#ifndef VIEW_H
#define VIEW_H

#include "defs.h"

/*
   Class       : View
   Description : This class is the view class responsible for presenting a UI.
*/
class View {
   public:
    void showMenu(int&) const;
    void printStr(string) const;
    void readInt(int&) const;
    void readStr(string&) const;

   private:
};

#endif