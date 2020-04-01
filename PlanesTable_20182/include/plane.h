// define constants
#define MAX_CHAR 20
#define MAX_PLANES 50


/*********************************************************************************************************
 * Write constants here */
#define NUM_CLASSES 3
#define CODE_FIRSTCLASS 1
#define CODE_BUSINESS 2
#define CODE_TURIST 3

//define enumerated boolean type
typedef enum {FALSE, TRUE} boolean;

//define enumerated utility type
typedef enum {COMMERCIAL,PRIVATE,GOVERNMENTAL,MILITAR,EXPERIMENTAL,OTHERS} tUtility;

//define tPlane type
typedef struct {
    int id; 
	char model[MAX_CHAR]; 
	int year;
	tUtility utility; 
	float percentOccupationFirstclass;
	float percentOccupationBusiness; 
	float percentOccupationTurist;       
	boolean isActive; 
} tPlane;


/*********************************************************************************************************
 * Define table type here 
 *********************************************************************************************************/
 typedef struct{
	tPlane planesTable[MAX_PLANES];
}tPlaneTable;

/*********************************************************************************************************
 * Write new functions headers here
 *********************************************************************************************************/
 void planeRead();
 void planeWrite();
 void planeCopy();
 void planesTableInicialize();
 int planesTableOccupation();
 void planesTableSelectByOccupation(tPlaneTable, float, int, tPlaneTable *);
 
 
 
 