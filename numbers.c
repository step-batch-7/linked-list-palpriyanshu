#include <stdio.h>
#include "list.h"

typedef char * string;

void display_main_menu(void);
char get_cmd(void);
int getNum(string text);

void display_main_menu(void){
  printf("Main Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(m) exit\n\n");
  printf("Please enter the alphabet of the operation you would like to perform\n");
};

char get_cmd(void){
  char cmd;
  display_main_menu();
  scanf("%c", &cmd);
  while((getchar()) != '\n');
  return cmd;
}

int getNum(string text){
  int num;
  printf("%s",text);
  scanf("%d",&num);
  while(getchar() != '\n');
  return num;
};

Status do_action(List_ptr list, char index){
  Status status;
  switch (index){
      case 'a':
      {
        int num = getNum( "Please enter a number : ");
        status = add_to_end(list, num);
        break;
      }

      case 'b':
      {
        int num = getNum( "Please enter a number : ");
        status = add_to_start(list, num);
        break;
      }

      case 'c':
      {
        int value = getNum("Please enter a number : ");
        int position = getNum("Please enter the position : ");
        status = insert_at(list, value, position);
        break;
      }
    }
   return status; 
}

int main(void)
{
  List_ptr list = create_list();
  char index = get_cmd();
  while(index != 'm'){
    Status status = do_action(list, index); 
    index = get_cmd();
  }
  return 0;
}