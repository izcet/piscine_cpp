/*=============================================================================
 * Project: Rush00 - Middle Out
 *
 * Program: Create a game with n-cursus
 *
 * Author: Sesl, Irhett, Tiny, Bemillie, Searsie
 * ==========================================================================*/
 #include "Environment.hpp"

static bool colors = TRUE;
static unsigned char  movement = 0;
static unsigned int state = 42424242;
static WINDOW *background;

Environment::Environment( void )
{
    background = newwin(Game::maxY - 2, Game::maxX - 2, 1, 1);
    return ;
}
unsigned int    Environment::starShift(void)/* random number generator */
{
    unsigned int x = state;

    x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    state = x;
    return x;
}
void    Environment::starsRnd( void )/* Displays the stars randomly in terminal*/
{
    getmaxyx(background, Game::maxY, Game::maxX);
    start_color();			/* Start color 			*/
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    if (colors)
    {
        wattron(background, COLOR_PAIR(1));
        mvwaddch(background, 0, (starShift() % Game::maxX), '*');
        colors = FALSE;
        movement++;
    }
    else
    {
        wattron(background, COLOR_PAIR(2));
        mvwaddch(background, 0, (starShift() % Game::maxX), '.');
        colors = TRUE;
        movement++;
    }
    if (movement == 10)
    {
        wattron(background, COLOR_PAIR(3));
        mvwaddch(background, 0, (starShift() % Game::maxX), '0');
        movement = 0;
    }
    wattroff(background, COLOR_PAIR(1));
    wattroff(background, COLOR_PAIR(2));
    wattroff(background, COLOR_PAIR(3));
    scrollok(background, TRUE);
    wscrl(background, -1);
    overwrite(background, stdscr);
    return ;
}

WINDOW  *Environment::getWin( void )
{
    return background;
}

Environment::~Environment( void )
{
    return ;
}
