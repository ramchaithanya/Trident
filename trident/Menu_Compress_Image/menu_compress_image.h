#ifndef MENU_COMPRESS_IMAGE_H
#define MENU_COMPRESS_IMAGE_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "../Menu_Base_Class/menu_base_class.h"

class Compress_Image:public menu_item
{
public:
  std::string item_text() const;
  void go();
};

#endif /* MENU_COMPRESS_IMAGE_H */
