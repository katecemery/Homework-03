/**
 * \file our-movie.cpp
 * \author CS 70 Provided Code
 *
 * \brief Provides the main() function for creating and running
 * a specific asciimation movie.
 *
 * \details
 *
 * \remarks
 *
 */

#include <iostream>
#include "asciimation.hpp"
#include "sprite.hpp"


void makeOurMovie()
{
    Asciimation ascii("spriteImages/mystery1.txt",15,10);
    ascii.generateAnimation("frames/",60,20);
    ascii.printFrame();
}


int main()
{
    makeOurMovie();
    return 0;
}
