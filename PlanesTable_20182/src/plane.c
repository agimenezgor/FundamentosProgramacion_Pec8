#include <stdio.h>
#include <string.h>
#include "plane.h"


void planeRead(tPlane *plane){
    
    
    printf("Identifier for plane (integer): >> ");
    scanf("%d", &plane->id);
    
    printf("Model for plane  (string): >> ");
    scanf("%s", &plane->model);
       
    printf("Year for plane  (integer):  >> ");
    scanf("%d", &plane->year);
        
    printf("Utility for plane  (enter a number being 0=COMMERCIAL, 1=PRIVATE, 2=GOVERNMENTAL, 3=MILITAR, 4=EXPERIMENTAL, 5=OTHERS: >> ");
    scanf("%u", &plane->utility);
        
    printf("Percentage of ocupation in Firstclass for plane (real): >> ");
    scanf("%f", &plane->percentOccupationFirstclass);

    printf("Percentage of ocupation in Business for plane (real): >> ");
    scanf("%f", &plane->percentOccupationBusiness);

    printf("Percentage of ocupation in Turist for plane (real): >> ");
    scanf("%f", &plane->percentOccupationTurist);
    
    printf("Is plane active? (enter a number being 0=FALSE, 1=TRUE): >> ");
    scanf("%u", &plane->isActive);
        
    printf("\n");
    
}

void planeWrite(tPlane plane){

    printf("Plane id: %d\n", plane.id);
    printf("Plane model: %s\n ", plane.model);
	printf("Plane year: %d\n", plane.year);
	printf("Plane utility: %u\n", plane.utility);
	printf("Percentage of occupation in Firstclass: %.2f\n", plane.percentOccupationFirstclass);
    printf("Percentage of occupation in Business: %.2f\n", plane.percentOccupationBusiness);
    printf("Percentage of occupation in Turist: %.2f\n", plane.percentOccupationTurist);
    printf("Is the plane active? %u\n", plane.isActive);
    printf("\n");
}

void planeCopy(tPlane planeSrc, tPlane *planeDst){

    planeDst->id = planeSrc.id;
    strcpy(planeDst->model, planeSrc.model);
    planeDst->year = planeSrc.year;
    planeDst->utility = planeSrc.utility;
    planeDst->percentOccupationFirstclass = planeSrc.percentOccupationFirstclass;
    planeDst->percentOccupationBusiness = planeSrc.percentOccupationBusiness;
    planeDst->percentOccupationTurist = planeSrc.percentOccupationTurist;
    planeDst->isActive = planeSrc.isActive;
}

/*********************************************************************************************************
 * Write new functions here
 *
 ********************************************************************************************************/
 /* Inicialización de la tabla*/

void planesTableInicialize (tPlaneTable *planesTable){ 
	int i;
	
	for(i = 0; i < MAX_PLANES; i++){
		(*planesTable).planesTable[i].id = 0;
		(*planesTable).planesTable[i].model[i] = 0;
		(*planesTable).planesTable[i].year = 0;
		(*planesTable).planesTable[i].utility = 0;
		(*planesTable).planesTable[i].percentOccupationFirstclass = 0;
		(*planesTable).planesTable[i].percentOccupationBusiness = 0;
		(*planesTable).planesTable[i].percentOccupationTurist = 0;
		(*planesTable).planesTable[i].isActive = 0;
	}
}

/* Función media ocupación*/

int planesTableOccupation (tPlaneTable planesTable, int idClass, int planesNum, float *average){
	int i;
	int j = 0;
	float av;
	
	if (idClass == 1){
		for(i=0; i < planesNum; i++){
			j = j + planesTable.planesTable[i].percentOccupationFirstclass;
		}
			av = (float)j / (float)planesNum;
			printf("The total average of the first class is: %.2f\n\n", av);
			*average = av;
	}else{
		if (idClass == 2){
			for(i=0; i < planesNum; i++){
				j = j + planesTable.planesTable[i].percentOccupationBusiness;
			}
			av = (float)j / (float)planesNum;
			printf("The total average of the business class is: %.2f\n\n", av);
			*average = av;
		}else{
			for(i=0; i < planesNum; i++){
				j = j + planesTable.planesTable[i].percentOccupationTurist;
			}
			av = (float)j / (float)planesNum;
			printf("The total average of the turist class is: %.2f\n\n", av);
			*average = av;
		}
	}
	return 0;
}

/* Función de selección de menores que la media*/

void planesTableSelectByOccupation(tPlaneTable planesTable, float average, int idClass, tPlaneTable *selectTable){
	int f = 0;
	int i;
	float h = 0;
	float av;
	int c = 0;
	
	if(idClass == 1){
		for(i=0; i<MAX_PLANES; i++){
		f = f + 1;             /*Total aviones registrados en la tabla planesTable*/
		h = h + planesTable.planesTable[i].percentOccupationFirstclass;
		av = h / (float)f;   
		
		if(av == average){
			for(i = 0; i < f; i++){
				if(planesTable.planesTable[i].percentOccupationFirstclass < average){
					c = c + 1;        /*Total aviones por debajo de la media*/
				}
			}
			
			for(i = 0; i < f; i++){       /*Guardar datos en selectTable. */
				if(planesTable.planesTable[i].percentOccupationFirstclass < average){
					(*selectTable).planesTable[i].id = planesTable.planesTable[i].id;
				}
			}
			
			if(c == 1){
				printf("There are 1 plane under the average.\n\n");
				printf("Id of the plane: \n\n");
			}else{
				printf("There are %d planes under the average.\n\n", c);
				printf("Id of the planes: \n\n");
			}
			
			for(i = 0; i < f ; i++){     /*Impresión de datos*/
				if(planesTable.planesTable[i].percentOccupationFirstclass < average){
					printf("Id: %d\n", selectTable->planesTable[i].id);
				}
			}
			printf("\n");
			break;
		}
	}
	}else{
		if(idClass == 2){
			for(i=0; i<MAX_PLANES; i++){
		f = f + 1;             /*Total aviones registrados en la tabla planesTable*/
		h = h + planesTable.planesTable[i].percentOccupationBusiness;
		av = h / (float)f;   
		
		if(av == average){
			for(i = 0; i < f; i++){
				if(planesTable.planesTable[i].percentOccupationBusiness < average){
					c = c + 1;        /*Total aviones por debajo de la media*/
				}
			}
			
			for(i = 0; i < f; i++){       /*Guardar datos en selectTable. */
				if(planesTable.planesTable[i].percentOccupationBusiness < average){
					(*selectTable).planesTable[i].id = planesTable.planesTable[i].id;
				}
			}
			
			if(c == 1){
				printf("There are 1 plane under the average.\n\n");
				printf("Id of the plane: \n\n");
			}else{
				printf("There are %d planes under the average.\n\n", c);
				printf("Id of the planes: \n\n");
			}
			
			for(i = 0; i < f ; i++){     /*Impresión de datos*/
				if(planesTable.planesTable[i].percentOccupationBusiness < average){
					printf("Id: %d\n", selectTable->planesTable[i].id);
				}
			}
			printf("\n");
			break;
		}
	}
		}else{
			for(i=0; i<MAX_PLANES; i++){
		f = f + 1;             /*Total aviones registrados en la tabla planesTable*/
		h = h + planesTable.planesTable[i].percentOccupationTurist;
		av = h / (float)f;   
		
		if(av == average){
			for(i = 0; i < f; i++){
				if(planesTable.planesTable[i].percentOccupationTurist < average){
					c = c + 1;        /*Total aviones por debajo de la media*/
				}
			}
			
			for(i = 0; i < f; i++){       /*Guardar datos en selectTable. */
				if(planesTable.planesTable[i].percentOccupationTurist < average){
					(*selectTable).planesTable[i].id = planesTable.planesTable[i].id;
				}
			}
			
			if(c == 1){
				printf("There are 1 plane under the average.\n\n");
				printf("Id of the plane: \n\n");
			}else{
				printf("There are %d planes under the average.\n\n", c);
				printf("Id of the planes: \n\n");
			}
			
			for(i = 0; i < f ; i++){     /*Impresión de datos*/
				if(planesTable.planesTable[i].percentOccupationTurist < average){
					printf("Id: %d\n", selectTable->planesTable[i].id);
				}
			}
			printf("\n");
			break;
		}
	}
		}
	}
}


