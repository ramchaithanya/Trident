#ifndef MENU_SHOW_IMAGE_H
#define MENU_SHOW_IMAGE_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "../Menu_Base_Class/menu_base_class.h"
class Show_Image:public menu_item
{
public:
  std::string item_text() const ;
  void go();
};
#endif /* MENU_SHOW_IMAGE_H */
