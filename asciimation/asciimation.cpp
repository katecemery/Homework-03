/**
 * \file movie.cpp
 * \author CS 70 Provided Code
 *
 * \brief Implements the Movie class
 *
 * \details
 *
 * \remarks
 *
 */

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "movie-helper.hpp"
#include "asciimation.hpp"
#include "sprite.hpp"

using std::string;
using std::cerr;
using std::endl;
using std::ofstream;

Asciimation::Asciimation(string inputFile, int topLeftRow, int topLeftColumn, bool scrolling) : 
sprite_(inputFile,topLeftRow,topLeftColumn,scrolling)
{ 
} 

void Asciimation::clearContents()
{ 
    size_t area = MOVIE_WIDTH*MOVIE_HEIGHT; 
    for(size_t i = 0; i < area; ++i) {
        frame_[i] = ' '; 
    }
}

void Asciimation::moveRight() { 
    int topLeftRow = sprite_.getTopLeftRow();
    int topLeftColumn = sprite_.getTopLeftColumn();
    if(topLeftColumn + 1 ==  MOVIE_WIDTH) {
        topLeftColumn = 0;
    }
    else { 
        topLeftColumn++;
    }
    sprite_.setLocation(topLeftRow,topLeftColumn);
}

void Asciimation::updateContents()
{
    // Clear contents by writing a space everywhere, so that we don't keep
    // old contents around when the display updates.

    //Call clearContents() to overwrite all of the old content
    // with spaces
    clearContents();
    
    // TODO: Call moveRight() (once it exists).
    if(sprite_.getScrolling()) {
        moveRight();
    }

    // Loop through all of the characters in the sprite and copy them to
    // the right spot in the movie's character array.
     
    size_t movieRow = 0;
    size_t movieColumn = 0;
    
    for (size_t spriteRow = 0; spriteRow < Sprite::SPRITE_HEIGHT; 
        ++spriteRow) {
        for(size_t spriteColumn = 0; spriteColumn < Sprite::SPRITE_WIDTH; 
            ++spriteColumn) {
            // Fill in this loop so that the contents of the sprite
            // for this location end up in the right spot in the 
            // asciimation object's contents.
            size_t topLeftRow = sprite_.getTopLeftRow();
            size_t topLeftColumn = sprite_.getTopLeftColumn(); 

            movieRow = spriteRow + topLeftRow; 
            movieColumn = (spriteColumn + topLeftColumn) % MOVIE_WIDTH; 
            
            frame_[movieRow*MOVIE_WIDTH + movieColumn] = sprite_.getCharAt(spriteRow,spriteColumn);
        }
    }
}

/**
 * \brief Generates a sequence of frames and converts them into an animation.
 * \param totalFrames is the number of frames of animation to generate
 * \param animationFramerate is given in frames per second
 */
void Asciimation::generateAnimation(string framesDirectory,
                                    int totalFrames,
                                    int animationFramerate)
{


    // specify a base name for each frame's ASCII text file
    const string FRAME_NAME = "frame-";

    // specify the file name for our generated animated GIF
    const string OUTPUT_FILENAME = "./our-movie.gif";

    for (int f = 0; f < totalFrames; ++f) {
        // Copy contents to the screen
        updateContents();
        printFrame();

        // copy the movie's characters to an ASCII art text file
        string frameNumberStr = std::to_string(f);
        string outputFileName = framesDirectory
                                + FRAME_NAME + frameNumberStr + ".txt";

        exportSingleFrame(outputFileName);
    }

    // use helper function to generate the animated gif!
    convertFramesToAnimation(framesDirectory,
                             totalFrames, animationFramerate,
                             FRAME_NAME, OUTPUT_FILENAME);
}

void Asciimation::exportSingleFrame(string fileName)
{
    // Loop through all of the characters in the current character array and
    // copy them to an ASCII text file; then, export (save) that file.

    //Fill in the implementation of exportSingleFrame
    ofstream outputfile(fileName);
    for(size_t movieRow = 0; movieRow < MOVIE_HEIGHT; ++movieRow) {
        for(size_t movieColumn = 0; movieColumn < MOVIE_WIDTH; ++movieColumn) { 
            outputfile << frame_[movieRow*MOVIE_WIDTH + movieColumn];
        }  
        outputfile << endl;       
    }
}

void Asciimation::printFrame() { 
for(size_t movieRow = 0; movieRow < MOVIE_HEIGHT; ++movieRow) {
        for(size_t movieColumn = 0; movieColumn < MOVIE_WIDTH; ++movieColumn) { 
            std::cout << frame_[movieRow*MOVIE_WIDTH + movieColumn];
        }  
       std::cout << endl;       
    }
}
