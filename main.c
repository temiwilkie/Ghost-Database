#include "defs.h"
//Initializes the building, loads building data, and presents a menu to the user
//input:none //output: integer representing the success or failure  and the menu to the user and the results of their selected option
int main()
{
  BuildingType* building = (BuildingType*) calloc(1, sizeof (BuildingType));
  initBuilding(building);
  loadBuildingData(building);

  int choice = -1;
  while (choice != 0) {
    printMenu(&choice);
    switch (choice) {
      case 1:
        printRooms(&building->rooms);
        break;
      case 2:
        printGhostList(&building->ghosts);
        break;
      case 3:
        printByLikelihood(&building->ghosts, C_FALSE);
        break;
      case 4:
        printByLikelihood(&building->ghosts, C_TRUE);
        break;
      case 0:
        printf("Exit Program\n");
        break;
      default:
        printf("Invalid Choice! Try again\n");
        break;
    }
  }

  cleanupBuilding(building);

  return 0;
}
//Prints the menu options to the user and prompts them to select an option
//input: choice a pointer to an integer representing the user's selected option 
//output: the menu options to the user
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 4;

  printf("\nMAIN MENU\n");
  printf("  (1) Print rooms\n");
  printf("  (2) Print ghosts\n");
  printf("  (3) Print ghosts by likelihood\n");
  printf("  (4) Print most/least likely ghosts\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

