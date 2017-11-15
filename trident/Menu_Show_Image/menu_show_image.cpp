#include "menu_show_image.h"

std::string Show_Image::item_text() const 
{ 
	return "display greeting"; 
}
void Show_Image::go() 
{ 
	std::cout << "Hello there, Mr. User."; 
}
