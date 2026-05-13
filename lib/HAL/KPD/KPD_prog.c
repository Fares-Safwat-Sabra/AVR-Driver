/*
 * KPD_prog.c
 *
 * Created: 4/29/2026 9:47:41 PM
 *  Author: fathi
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"

#include "KPD_config.h"


/*keypad array of data */


u8 KPD_arr[3][3] = {{1,2,'+'} , 
	                {3,4,'-'} , 
					{'c',0,'='}} ; 
						
					
void  KPD_voidInit(void){
	
	 u8 ROW_arr[3] ={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN} ; 
	 u8 COL_arr[3] = {KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN} ; 
	 
	 u8 loc_in=0 ; 
	 
	  for (loc_in=0 ; loc_in<3 ; loc_in++)
	  {
		   /*init rows */
		  
		   DIO_voidSetPinDir(KPD_ROW_PORT,ROW_arr[loc_in],INPUT) ; 
		   DIO_voidSetPinVal(KPD_ROW_PORT,ROW_arr[loc_in],HIGH) ; 
		   
		   /*col init */ 
		  
		  DIO_voidSetPinDir(KPD_COL_PORT,COL_arr[loc_in],OUTPUT) ; 
		  DIO_voidSetPinVal(KPD_COL_PORT,COL_arr[loc_in],HIGH) ; 
		  
	  }
	  	 
		 
		 	 
	
	
	
	
	
	
	
}

u8   KPD_u8GetKey(void) {
	
	 u8 ROW_arr[3] ={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN} ;
	 u8 COL_arr[3] = {KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN} ;
	 
	 u8 col=0 , row=0 ; 
	 u8 val = 0xff ; 

	for (col=0 ; col  < 3  ; col++)
	{
		/*active the current  col ---> low */
		
		DIO_voidSetPinVal(KPD_COL_PORT,COL_arr[col],LOW) ; 
		
		 /*check any button is pressed */
		for(row =0 ; row < 3 ; row ++){
			
			if (DIO_u8ReadPinVal(KPD_ROW_PORT,ROW_arr[row])==0)
			{
	               val =KPD_arr[row][col] ; 
				   while(DIO_u8ReadPinVal(KPD_ROW_PORT,ROW_arr[row])==0) ; 
				   return val ; 				
	 		}	
		}
		/*active the current  col ---> high */
		
		DIO_voidSetPinVal(KPD_COL_PORT,COL_arr[col],HIGH) ;
	}
	return val ; 
}
