/**
 * CSC232 - Data Structures
 * Missouri State University
 *
 * @file    csc232.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Function implementations as needed for CSC232 assignments and demos.
 * @version v2022.12.26
 * @date    Spring 2023
 */

#include "csc232.h"

int factorial(int number)
{
    return number > 1 ? factorial(number - 1) * number : 1;
}

bool read_data(const std::string& input_file)
{
    // Open the file for reading
    std::ifstream data_file{ input_file, std::ios::in };

    if (!data_file)
    {
        std::cout << "Could not open \"" << input_file << "\"" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Successfully opened \"" << input_file << "\"";

        std::cout << "... will now close this file" << std::endl;
        if (data_file.is_open())
        {
            data_file.close();
        }
    }
    return true;
}

int binarySearch( const int anArray[], int first, int last, int target )
{
    int index { 0 };
    if ( first > last )
    {
        // target is not in the array
        index = -1;
    }
    else
    {
        // if target is in anArray, anArray[first] <= target <= anArray[last]
        int mid{ first + (last - first) / 2 }; // why not (first + last) / 2
        if ( target == anArray[ mid ])
        {
            // target found at anArray[mid]
            index = mid;
        }
        else if ( target < anArray[mid] )
        {
            // target is possibly somewhere in lower half of anArray
            index = binarySearch( anArray, first, mid - 1, target );
        }
        else
        {
            // target is possibly somewhere in upper half of anArray
            index = binarySearch( anArray, mid + 1, last, target );
        }
    } // end else
    return index;
} // end binarySearch
