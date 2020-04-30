#include <stdio.h>
#include "list.h"
typedef char * string;
int getNum(string text);
int getNum(string text){
  int num;
  printf("%s",text);
  scanf("%d",&num);
  return num;
};
void display_main_menu(){
  string text = "Main Menu\n---------\n\n(a) add a number to the end of the list\n(m) exit\n\nPlease enter the alphabet of the operation you would like to perform\n" ;
  printf("%s",text);
}

int main(void)
{
  List_ptr list = create_list();
  char index;
  display_main_menu();
  scanf("%c", &index);
  while(index != 'm'){
    switch (index){
      case 'a':
      {
        string text = "Please enter a number : ";
        int num = getNum(text);
        Status status = add_to_end(list, num);
        break;
      }
    }
  display_main_menu();
  scanf("%c", &index);
  }
  return 0;
}