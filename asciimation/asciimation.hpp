/* asciimation.hpp
   =========

   Interface definition for the Asciimation class, which handles the creation
   of a sprite-based asciimation movie.

 */

#ifndef ASCIIMATION_HPP_INCLUDED
#define ASCIIMATION_HPP_INCLUDED

#include <string>
#include "sprite.hpp"


/**
 * \class Asciimation
 * \brief Holds the contents of an ASCIImation movie
 *
 * \details
 * Stores an array of characters that will be displayed to the screen, and
 * a Sprite that will be added to the screen.
 *
 */

using std::string;

class Asciimation {
public:
    static const size_t MOVIE_WIDTH = 80;
    static const size_t MOVIE_HEIGHT = 40; 
    Asciimation(string inputFile, int topLeftRow, int topLeftColumn, bool scrolling);

  void clearContents();

  /**
     * \brief Creates the current display showing the sprite
     * \post The current display contents are up to date and
     * ready to display to the screen.
     */
    void updateContents();

    /**
     * \brief generates an animated GIF of the requested duration
     * \post
     */
    void generateAnimation(string framesDirectory,
                           int totalFrames,
                           int animationFramerate);

    /**
     * \brief Exports the current display contents to a text file
     * \post file [fileName] contains an ASCII art rendering
     * of the current display buffer.
     */
    void exportSingleFrame(string fileName);

    void printFrame();
    void moveRight(); 

private:
    // The sprite to display in this movie.
   Sprite sprite_;

    // The characters to display on the screen.
   char frame_[MOVIE_HEIGHT*MOVIE_WIDTH]; //previously named currDiplayedChar
};

#endif // ifndef ASCIIMATION_HPP_INCLUDED
