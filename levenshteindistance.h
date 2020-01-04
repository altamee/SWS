#ifndef LEVENSHTEINDISTANCE_H
#define LEVENSHTEINDISTANCE_H

#include <qstring.h>

class LevenshteinDistance
{
public:
    LevenshteinDistance();

    int GetDistance(QString firstWord, int lengthFirst, QString secondWord, int lengthSecond);
    int minimum(int firstNum, int secondNum, int thirdNum);
private:
};

#endif // LEVENSHTEINDISTANCE_H
