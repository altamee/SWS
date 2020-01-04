#include "levenshteindistance.h"
#include <algorithm>

/**
 * @brief LevenshteinDistance::LevenshteinDistance constructor
 */
LevenshteinDistance::LevenshteinDistance()
{
}

/**
 * @brief LevenshteinDistance::GetDistance get the levenshtein distance between two words recursivley
 * @param firstWord The first word
 * @param secondWord The second word
 * @return The distance between the two words
 */
int LevenshteinDistance::GetDistance(QString firstWord, int lengthFirst, QString secondWord, int lengthSecond)
{
    int distance = 0;

    // empty string
    if (lengthFirst == 0) return lengthFirst;
    if (lengthSecond == 0) return lengthSecond;

    // check if last letter needs to be changed
    if (firstWord[lengthFirst - 1] != secondWord[lengthSecond - 1])
        distance = 1;

    int deleteFirst = GetDistance(firstWord, lengthFirst - 1, secondWord, lengthSecond);
    int deleteSecond = GetDistance(firstWord, lengthFirst, secondWord, lengthSecond - 1);
    int deleteBoth = GetDistance(firstWord, lengthFirst - 1, secondWord, lengthSecond - 1);

    return minimum(deleteFirst + 1, deleteSecond + 1, deleteBoth + distance);

}

/**
 * @brief LevenshteinDistance::minimum get the minimum of three numbers
 * @param firstNum  the first number to compare
 * @param secondNum the second number to compare
 * @param thirdNum the third number ot compare
 * @return the smallest of the three
 */
int LevenshteinDistance::minimum(int firstNum, int secondNum, int thirdNum)
{

    int min = (firstNum < secondNum) ? firstNum : secondNum;
    min = (thirdNum < min) ? thirdNum : min;

    return min;
}
