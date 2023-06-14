#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define C_TRUE     1
#define C_FALSE    0
 
#define MAX_ARR  128
#define MAX_STR   32
 
#define NEXT_ROOM_ID    9001
#define NEXT_GHOST_ID  810310
 
typedef enum { POLTERGEIST, WRAITH, PHANTOM, BULLIES, OTHER } GhostEnumType;
 
typedef struct {
  int id;
  char name[MAX_STR];
  struct GhostList *ghosts;
} RoomType;
 
typedef struct {
  int id;
  GhostEnumType ghostType;
  RoomType *room;
  float likelihood;
} GhostType;
 

/*** Define the RoomArrayType here ***/
typedef struct {
   RoomType *elements[MAX_ARR];
   int size;
}RoomArrayType;
 
/*** Define the NodeType here ***/
typedef struct Node {
   GhostType *ghost;
   struct Node *next;
}NodeType;
 
/*** Complete the GhostListType here ***/
typedef struct GhostList {
   NodeType *head;
   NodeType *tail;
}GhostListType;

/*** Complete the BuildingType here ***/
typedef struct Building {
   GhostListType ghosts;
   RoomArrayType rooms;
 
} BuildingType;
 

void initRoom(int, char*, RoomType**);
void addRoom(RoomArrayType*, RoomType*);
void initGhost(int, GhostEnumType, RoomType*, float, GhostType**);
void addGhost(GhostListType*, GhostType*);
void initGhostList(GhostListType*);
void initRoomArray(RoomArrayType*);
void cleanupRoomArray(RoomArrayType*);
void cleanupGhostData(GhostListType*);
void initBuilding(BuildingType*);
void printRooms(RoomArrayType*);
void printGhostList(GhostListType*);
void printByLikelihood(GhostListType*, int);
void cleanupBuilding(BuildingType*);
void initGhostList(GhostListType*);
void printGhostList(GhostListType*);
void cleanupGhostList(GhostListType*);
void printMenu(int*);
void loadBuildingData(BuildingType*);
 
 

