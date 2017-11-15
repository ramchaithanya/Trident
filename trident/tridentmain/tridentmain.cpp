#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "../Menu_Base_Class/menu_base_class.h"
#include "../Menu_Show_Image/menu_show_image.h"
#include "../Menu_Compress_Image/menu_compress_image.h"
class Main_Menu
{
public:
  void add_item(std::unique_ptr<menu_item> item) { items.push_back(std::move(item)); }
  void go()
  {
    std::cout << "Choose: \n";
    std::for_each(items.begin(), items.end(), [](std::unique_ptr<menu_item> const& item)
    {
      std::cout << "\t" << item->item_text() << "\n";
    });
    std::cout << "\n\n\tYour choice: ";
    int choice; /*= get_number_from_console();*/
    std::cin>>choice;
    if (items.size() > choice) items[choice]->go();
  }
  std::string item_text() const { return text_; }
private:
  std::string text_;
  std::vector<std::unique_ptr<menu_item> > items;
};
int main()
{
  Main_Menu top_item;
  top_item.add_item(std::unique_ptr<menu_item> (new Show_Image));
  top_item.add_item(std::unique_ptr<menu_item>(new Compress_Image));
  top_item.go();
}
