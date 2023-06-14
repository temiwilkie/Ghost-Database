#include "defs.h"

//function initializes a GhostListType by setting its head and tail pointers to NULL
//input:  list, GhostListType struct initialized //output: none
void initGhostList(GhostListType *list){
     list -> head = NULL;
     list -> tail = NULL;
}

//function initializes a GhostType struct by allocating memory for it and setting its fields to the input values.
//input: id The ID of the ghost, gt The GhostEnumType of the ghost, r The RoomType of the ghost,  like The likelihood of the ghost,  ghost A pointer to the GhostType struct
//output: none
void initGhost(int id, GhostEnumType gt, RoomType *r, float like, GhostType **ghost){
     (*ghost) = (GhostType*)malloc(sizeof(GhostType));
     if (*ghost == NULL){
     	printf("Failure to allocate ghost memory\n");
     	return;
     }
     (*ghost) -> id = id;
     (*ghost) -> ghostType = gt;
     (*ghost) -> room = r;
     (*ghost) -> likelihood = like;
     
}

//function adds a GhostType struct to the end of a GhostListType struct
//input: list The GhostListType struct, ghost The GhostType struct //output: none
void addGhost(GhostListType *list, GhostType *ghost){
    NodeType *current = malloc(sizeof(NodeType));
  current -> ghost = ghost;
  current -> next = NULL;
  if(list -> head == NULL){
    list -> head = current;
    list -> tail = current;

  }
  else{
    list -> tail -> next = current;
    list -> tail = current;
  }
}

//function frees memory allocated to GhostType struct and sets the head and tail pointers of the list to NULL
//input: list The GhostListType struct //output: none
void cleanupGhostData(GhostListType *list){
     NodeType *current = list -> head;
     
     while(current != NULL){
     	free(current -> ghost);
     	current = current -> next;
     }
}

// function frees memory allocated to GhostType structs and their corresponding NodeType structs in a GhostListType struct
//input: list The GhostListType struct output: none
void cleanupGhostList(GhostListType *list){
     NodeType *current = list -> head;
     NodeType *old = current;
     
     while(current != NULL){
     	old = current -> next;
     	free(current);
     	current = old;
     }   
}
//function prints the ID, GhostEnumType, RoomType name, and likelihood of a GhostType struct
//input: GhostType struct output:none
void printGhost(GhostType *ghost){
     printf("ID: %d\n",ghost -> id);
     printf("Ghost Type: ");
  
    switch(ghost -> ghostType){
	    case POLTERGEIST:
	    printf("Poltergeist");
	    break;
	    case WRAITH:
	    printf("Wraith\n");
	    break;
	    case PHANTOM:
	    printf("Phantom\n");
	    break;
	    case BULLIES:
	    printf("Bullies\n");
	    break;
	    case OTHER:
	    printf("Other\n");
	    break;
	    default:
	    printf("Unknown\n");
	    break;
  }
  
    printf("\nGhost Room:");
  if(ghost -> room == NULL){
    printf("%s\n","unknown");
  }
  else{
    printf("%s\n", ghost ->room ->name);
  }
    printf("Ghost likelihood: %.2f\n",ghost ->likelihood);
}

//function prints all GhostType structs in a GhostListType struct
//input: list The GhostListType struct  output: none
void printGhostList(GhostListType *list){
     NodeType *current = list -> head;
     while(current != NULL){
     	printGhost(current -> ghost);
     	current = current -> next;
   }
}


//function adds a GhostType struct to a GhostListType struct in order of decreasing likelihood
//input: list The GhostListType struct output: none
void addGhostByLikelihood(GhostListType *list, GhostType *ghost) {
    NodeType *current = (NodeType*)malloc(sizeof(NodeType));
    current->ghost = ghost;
    current->next = NULL;
    
    if (list->head == NULL) {
        list->head = current;
        list->tail = current;
    }
    else {
        NodeType *new = list->head;
        NodeType *old = NULL;
        
        while (new != NULL && new->ghost->likelihood > ghost->likelihood) {
            old = new;
            new = new->next;
        }
        
        if (old == NULL) {
            current->next = list->head;
            list->head = current;
        }
        else {
            current->next = new;
            old->next = current;
        }
    }
}
//function prints the most and least likely GhostType structs in a GhostListType struct, or all GhostType structs in order of decreasing likelihood
//input: origList The GhostListType struct, endsOnly, output: none
void printByLikelihood(GhostListType *origList, int endsOnly){
     GhostListType temp;
     initGhostList(&temp);
     
     NodeType *current = origList -> head;
     while(current != NULL){
          addGhostByLikelihood(&temp,current -> ghost);
          current = current -> next;
     }
     if (endsOnly){
        printf("Most likely ghost:\n");
        printGhost(temp.head->ghost);
        printf("Least likely ghost:\n");
        printGhost(temp.tail->ghost);	
    } else {
        printf("Ghosts:\n");
        printGhostList(&temp);
    }
    
    cleanupGhostList(&temp);
	
}


   
     
     
     
     
     
     
     
     
     

