# The target "sprite.o" has two dependency: "sprite.cpp" and "sprite.hpp".
# Make will confirm that the dependency is up to date and then it will run
# the command on the following line to generate "sprite.o".
# .o stands for object file

sprite.o: sprite.cpp sprite.hpp
	clang++ -c -o sprite.o -g -std=c++1z -pedantic -Wall -Wextra sprite.cpp

# The target "movie-helper.o" has two dependencies "movie-helper.cpp" and "movie-helper.hpp"
# "movie-helper.hpp" Make will make sure that the command runs if either of these
# files have changed since the last time Make had to make "movie-helper.o"
# (Note the -c in the command, this means that clang will not link, but will
# just comile into an object (.o) file.  We are naming that output file
# movie-helper.o
movie-helper.o: movie-helper.cpp movie-helper.hpp
	clang++ -c -o movie-helper.o -g -std=c++1z -pedantic -Wall -Wextra movie-helper.cpp 

# The target "asciimation.o" has two dependencies "asciimation.cpp" and "asciimation.hpp"
# "asciimation.hpp" Make will make sure that the command runs if either of these
# files have changed since the last time Make had to make "asciimation.o"
# (Note the -c in the command, this means that clang will not link, but will
# just comile into an object (.o) file.  We are naming that output file
# asciimation.o
asciimation.o: asciimation.cpp asciimation.hpp movie-helper.hpp sprite.hpp
	clang++ -c -o asciimation.o -g -std=c++1z -pedantic -Wall -Wextra asciimation.cpp


# The target "our-movie.o" has two dependencies "our-movie.cpp" and "our-movie.hpp"
# "our-movie.hpp" Make will make sure that the command runs if either of these
# files have changed since the last time Make had to make "our-movie.o"
# (Note the -c in the command, this means that clang will not link, but will
# just comile into an object (.o) file.  We are naming that output file
# our-movie.o
our-movie.o: our-movie.cpp asciimation.hpp sprite.hpp
	clang++ -c -o our-movie.o -g -std=c++1z -pedantic -Wall -Wextra our-movie.cpp	
	
# The target "generateMovie" has four dependencies "our-movie.o" "asciimation.o" "movie-helper.o" "sprite.o" 
#  Make will make sure these two dependencies are up to date and
# then it will run the commend on the following line, to compile an executable
# and give it the name "generateMovie"
generateMovie: our-movie.o asciimation.o sprite.o movie-helper.o
	clang++ -o generateMovie our-movie.o asciimation.o sprite.o movie-helper.o -lstdc++fs

# This is a "dummy" target.  When we tell Make to make clean, it has no
# dependencies and it will just run the command below, which removes all object
# files and the executable (if they exist).
clean:
	rm -rf *.o generateMovie
