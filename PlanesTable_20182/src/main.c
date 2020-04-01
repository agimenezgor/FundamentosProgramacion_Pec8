#include <stdio.h>
#include "plane.h"
/*********************************************************************************************************
 * Pac8/Pec8 code v.1
 ********************************************************************************************************/

//main algorithm
int main(int argc, char **argv){
    
/*********************************************************************************************************
 * Write main algorith here 
 ********************************************************************************************************/
	tPlaneTable planesTable;
	tPlaneTable selectTable;
	
	int planesNum;
	int idClass;
	float average;
	
	printf("Enter how many planes do you want to introduce: >> ");
	scanf("%d", &planesNum);
	printf("\n");
	
	while(planesNum < 0 || planesNum > MAX_PLANES){
		printf("                  Data error.\nThe number of planes must be between 1 and 50.\n\n");
		printf("Please, reintroduce how many planes do you want to introduce: >> ");
		scanf("%d", &planesNum);
		printf("\n");
	}
	
	planesTableInicialize(&planesTable);
	planesTableInicialize(&selectTable);
	
	int i;
	
	for(i=0; i < planesNum; i++){
		planeRead(&planesTable.planesTable[i]);
	}
	
	for(i=0; i < planesNum; i++){
		planeWrite(planesTable.planesTable[i]);
	}
	
	printf("Enter the code of the class that you want to analyze (first class = 1, business = 2, turist = 3): >> ");
	scanf("%d", &idClass);
	printf("\n");
	
	while(idClass < 1 || idClass > 3){
		printf("              Data error.\nThe code number must be between 1 and 3.\n\n");
		printf("Please, reintroduce the code number: >> ");
		scanf("%d", &idClass);
		printf("\n");
	}
	
	
	planesTableOccupation(planesTable, idClass, planesNum, &average);
	
	planesTableSelectByOccupation(planesTable, average, idClass, &selectTable);
	
	return 0;
}
