#ifndef TERMINAL_HH_
#define TERMINAL_HH_

#include <string>
#include <memory>
#include "Utils.hh"
#ifdef _WIN32
  #undef MOUSE_MOVED
  #include <pdcurses/curses.h>
#elif __linux__
  #include <curses.h>
#endif

#define BASE_PAIR     1

class Terminal
{
public:
  Terminal();
  ~Terminal();

  static Terminal &get();

  void initColors();
  void clearScreen();
  void blit();
  void setFullscreen();
  void setCanonical(bool set);
  void setStdinTimeout(int milliseconds);
  void print(const std::string &str, int attrs = 0);
  void printAt(Point point, const std::string &str);
  WINDOW *addChildWindow(Point pos, Point size);

  static std::unique_ptr<Terminal> instance;

  friend Terminal &operator<<(Terminal &term, const std::string str);
  friend Terminal &operator<<(Terminal &term, int data);
  friend Terminal &operator<<(Terminal &term, const char *str);

private:
  WINDOW *_screen;
  int _rows;
  int _cols;
};

#endif /* !TERMINAL_HH_ */
