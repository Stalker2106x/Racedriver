#include "Terminal.hh"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#ifdef __GNUC__
#include <unistd.h>
#endif
#ifdef _MSC_VER
#include <windows.h>
#endif

std::unique_ptr<Terminal> Terminal::instance = nullptr;

Terminal::Terminal()
{
	_screen = initscr(); // Start Xcurses window
	setFullscreen();
	setCanonical(true);
	keypad(_screen, TRUE);
	curs_set(2); //Block cursor
	initColors();
	Terminal::instance = std::unique_ptr<Terminal>(this);
}

Terminal::~Terminal()
{
	endwin();	//Close Xcurses
}

Terminal &Terminal::get()
{
	return (*instance.get());
}

void Terminal::initColors()
{
	if (has_colors() == FALSE)
	{
		std::cerr << "Your terminal does not support color\n";
		throw std::runtime_error("COLOR_ERROR");
	}
	start_color();
	init_pair(BASE_PAIR, COLOR_RED, COLOR_BLACK);
}

void Terminal::setFullscreen()
{
	resize_term(2000, 2000);
	getmaxyx(_screen, _rows, _cols); // Get the largest physical screen dimensions
	_rows *= 0.75f;
	_cols *= 0.75f;
	resize_term(_rows, _cols);
}

void Terminal::clearScreen()
{
  wclear(_screen);
}

void Terminal::blit()
{
	refresh(); //Print all bufferized data
}

void Terminal::setCanonical(bool set = true)
{
  (set ? cbreak() : nocbreak());
}

void Terminal::setStdinTimeout(int milliseconds = -1)
{
	wtimeout(_screen, milliseconds);
}

void Terminal::print(const std::string &str, int attrs)
{
	if (attrs != 0) attron(attrs);
	waddstr(_screen, str.c_str());
	if (attrs != 0) attroff(attrs);
	blit();
}

void Terminal::printAt(Point point, const std::string &str)
{
	mvwaddstr(_screen, point.y, point.x, str.c_str());
	blit();
}

WINDOW *Terminal::addChildWindow(Point pos, Point size)
{
	WINDOW *win = subwin(_screen, size.y, size.x, pos.y, pos.x);
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(win);
  return (win);
}

//I/O Streaming

Terminal &operator<<(Terminal &term, const std::string str)
{
  return (term << str.c_str());
}

Terminal &operator<<(Terminal &term, int data)
{
  return (term << std::to_string(data));
}

Terminal &operator<<(Terminal &term, const char *str)
{
  term.print(str);
  return (term);
}

/*
Terminal &operator<<(Terminal &term, void (Terminal::*fptr)(int))
{
	(term.*fptr)();
	return (term);
}
*/