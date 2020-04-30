#include <stdio.h>
#include "list.h"

typedef char * string;

void display_main_menu(void);
char get_cmd(void);
int getNum(string text);
void do_action(List_ptr list, char index);

void display_main_menu(void){
  printf("\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it alreay exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(l) display the list of numbers\n");
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

void do_action(List_ptr list, char index){
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

    case 'd':
    {
      int value = getNum("Please enter a number : ");
      status = add_unique(list, value);
      break;
    }

    case 'e':
    {
      status = remove_from_start(list);
      break;
    }

    case 'l':
    {
      display(list);
      break;
    }
  }
}

int main(void)
{
  List_ptr list = create_list();
  char index = get_cmd();
  while(index != 'm'){
    do_action(list, index); 
    index = get_cmd();
  }
  return 0;
}