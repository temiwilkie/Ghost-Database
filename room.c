#include "defs.h"


//Initializes a single RoomType instance with the given id and name and initializes an empty GhostListType for the room
//input:int id: The id of the room, char *name: The name of the room, RoomType **room: A pointer to a pointer to a RoomType instance
//output: none
 void initRoom(int id, char *name, RoomType **room){
      *room = (RoomType*) malloc(sizeof(RoomType));
      
      (*room)->id = id;
      strcpy((*room) -> name, name);
      
      (*room)->ghosts = (GhostListType*) malloc(sizeof(GhostListType));
       
      initGhostList((*room)->ghosts);

 }
//Initializes a RoomArrayType instance by setting its size to 0
//Input:RoomArrayType *arr: A pointer to a RoomArrayType instance 
//Output: none

 void initRoomArray(RoomArrayType *arr){
 arr->size = 0;
}

//Adds a RoomType instance to the RoomArrayType instance by appending it to the end of the elements array and incrementing the size
//input: RoomArrayType *arr: A pointer to a RoomArrayType instance, RoomType *r: A pointer to a RoomType instance.
//output:none
void addRoom(RoomArrayType *arr, RoomType *r) {
  arr->elements[arr->size] = r;
  arr->size++;
}

//Frees the memory allocated for each RoomType instance in the elements array of a RoomArrayType instance
//input:RoomArrayType *arr: A pointer to a RoomArrayType instance
//output: none
void cleanupRoomArray(RoomArrayType *arr){
  for(int i = 0; i < arr ->size; i++){
    cleanupGhostList(arr -> elements[i]->ghosts);
    free(arr->elements[i]);
    }
    free(arr->elements);
    arr->size = 0;
  }

//Prints out information about each RoomType instance in the RoomArrayType instance
//input: RoomArrayType *arr: A pointer to a RoomArrayType instance
//output: none
void printRooms(RoomArrayType *arr){
  for(int i = 0; i < arr->size; i++){
    printf("Room ID:%d\n", arr ->elements[i]->id);
    printf("Room Name:%s\n", arr ->elements[i]->name);
    printf("Ghosts in Room:\n"); 
    printGhostList(arr->elements[i]->ghosts);
  }
}




