#ifndef MENUITEM_HH_
#define MENUITEM_HH_

#include <memory>
#include <string>
#include "Terminal.hh"
#include "DataFile.hh"

#define TARGET_SEPARATOR  ":"

/*!
 * @brief Holds menu entry data
 */
class MenuItem
{
public:
  enum Type {
    Button,
    Input
  };

  MenuItem(xml_node &data);
  MenuItem(std::string label);

  static std::shared_ptr<MenuItem> create(xml_node &data);

  void toggleHover();

  virtual bool isSelectable();
  virtual void select();
  virtual void render();

protected:
  bool _hover;
  std::string _id;
  std::string _label;
};

/*!
 * @brief Acts as a button
 */
class MenuButton : public MenuItem
{
public:
  enum Type {
    Goto,
    Script
  };
  MenuButton(xml_node &data);

  virtual bool isSelectable();
  virtual void select();

private:
  Type _type;
  std::string _target, _path;
};

/*!
 * @brief Acts as a text input
 */
class MenuInput : public MenuItem
{
public:
  MenuInput(xml_node &data);

  virtual bool isSelectable();
  virtual void select();
  std::string getData();
  virtual void render();

private:
  std::string _data;
};


#endif /* !MENUITEM_HH_ */