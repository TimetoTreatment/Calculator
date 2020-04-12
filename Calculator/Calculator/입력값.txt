//
// ArrayStack Header.
//
// Made by (CE) TimetoTreatment.
//
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Define DATA type and ArrayStack structure
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// ~def ___ DATA;
typedef int DATA;

typedef struct _ArrayStack
{
	DATA* ar;
	int top;
	int max;

} AStack;


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// ArrayStack Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

/* Initialize Stack */
void ASiniti(AStack* st, int max);

/* Clear Stack */
void ASclear(AStack* st);

/* Check whether empty */
int ASisEmpty(AStack* st);

/* Check whether full */
int ASisFull(AStack* st);

/* Insert DATA */
void ASpush(AStack* st, DATA data);

/* Extract DATA */
DATA ASpop(AStack* st);

/* Read top */
DATA ASpeek(AStack* st);

/* Read current Stack size */
int ASsize(AStack* st);

/* Show all DATA */
void ASlist(AStack* st);


#endif