#include <Menus/Menu.hh>

Menu::Menu(std::string font, int csize, std::string bg)
{
  extern Pipeline	g_pipeline;

  _cursor = 0;
  _background.setTexture(g_pipeline.getTexture(bg));
  _title.setFont(g_pipeline.getFont(font));
  _title.setCharacterSize(csize * TITLE_FACTOR);
}

Menu::~Menu()
{

}

void Menu::initLabel(std::string title, std::vector<std::string> items)
{
  _title.setString(title);
  for (size_t i = 0; i < items.size(); i++)
  {
    _items.push_back(sf::Text());
    _items[i].setString(items[i]);
    _items[i].setFont(*_title.getFont());
    _items[i].setCharacterSize(_title.getCharacterSize() / TITLE_FACTOR);
  }
}

void Menu::setPosition(sf::Rect<int> pos)
{
  extern sf::Vector2i	g_winsize;
  float spacing = (pos.height - (_items.size() * _items[0].getLocalBounds().height)) / _items.size();

  _position = pos;
  _title.setPosition(centerText(_title, 'X'), TITLE_Y);
  for (size_t i = 0; i < _items.size(); i++)
  {
    _items[i].setPosition(pos.left + ((pos.width / 2) - (_items[i].getLocalBounds().width / 2)),
      pos.top + (i * spacing));
  }
}

void Menu::updateNav(sf::Event event)
{
  _items[_cursor].setStyle(0);
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Down)
      _cursor += 1;
    else if (event.key.code == sf::Keyboard::Up)
      _cursor -= 1;
  }
  if (_cursor < 0)
    _cursor = static_cast<unsigned int>(_items.size() - 1);
  else if (static_cast<unsigned int>(_cursor) >= _items.size())
    _cursor = 0;
  _items[_cursor].setStyle(sf::Text::Bold);
}

void Menu::drawNav(sf::RenderWindow &win)
{
  win.draw(_background);
  win.draw(_title);
  for (size_t i = 0; i < _items.size(); i++)
    {
      win.draw(_items[i]);
    }
}
