#ifndef ENVIRONMENT_HPP
# define ENVIRONMENT_HPP

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#include <curses.h>
#include "Game.hpp"

class   Environment
{
        //char    stars[256];
        public:

                Environment( void );
                void    starsRnd( void );
                unsigned int    starShift( void );
                WINDOW  *getWin( void );
                ~Environment( void );

        private:
        //                unsigned int _characters;
        protected:
        //        bool    asteroid(int x, int y);
};

#endif
