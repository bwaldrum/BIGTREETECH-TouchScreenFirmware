#include "Home.h"
#include "includes.h"

//1��title(����), ITEM_PER_PAGE��item(ͼ��+��ǩ) 
const MENUITEMS homeItems = {
//   title
LABEL_HOME,
// icon                       label
 {{ICON_HOME,                 LABEL_HOME},
  {ICON_X_HOME,               LABEL_X_HOME},
  {ICON_Y_HOME,               LABEL_Y_HOME},
  {ICON_Z_HOME,               LABEL_Z_HOME},
  {ICON_ZERO_XYZ,             LABEL_ZERO_XYZ},
  {ICON_ZERO_XY,              LABEL_ZERO_XY},
  {ICON_ZERO_Z,               LABEL_ZERO_Z},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuHome(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&homeItems);
  storeCmd("M666 X1.2 Y1.2\n");
  while(infoMenu.menu[infoMenu.cur] == menuHome)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: storeCmd("G28\n");   break;
      case KEY_ICON_1: storeCmd("G28 X\n"); break;
      case KEY_ICON_2: storeCmd("G28 Y\n"); break;
      case KEY_ICON_3: storeCmd("G28 Z\n"); break;
      case KEY_ICON_4: storeCmd("G92 X0 Y0 Z0\n"); break;
      case KEY_ICON_5: storeCmd("G92 X0 Y0\n"); break;
      case KEY_ICON_6: storeCmd("G92 Z0\nG0 Z10\n"); break;
      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;            
    }
    loopProcess();
  }
}

