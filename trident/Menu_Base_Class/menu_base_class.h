#ifndef MENU_BASE_CLASS_H
#define MENU_BASE_CLASS_H
#include <iostream>
class menu_item
{
public:
  virtual ~menu_item() {}
  virtual std::string item_text() const = 0;
  virtual void go() = 0;
};
#endif /* MENU_BASE_CLASS_H */

