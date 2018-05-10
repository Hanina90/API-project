//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>

float x_1 = 200;
float x_2 = 100;
float x_3 = 10;
float y_1 = 100;
float y_2 = 10;
float y_3 = 100;

int kleur = 0;

int dikte = 3;

int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

    UB_VGA_FillScreen(VGA_COL_GREEN);

////////////////////////////////////x1 en x2////////////////////////////////////////////////////////////////
    if (x_2 > x_1)
   	  {

   		  for(int x = x_1; (x <= x_2); x++)
   		  {
   			  for(int i = 0; i < dikte; i++)
   			  {
   				  //float y = (a * x) + b;

   				  float y = ((y_2 - y_1)/ (x_2- x_1))* (x - x_1) + y_1;
   				  UB_VGA_SetPixel(x,(y+i),10);
   			  }
   		  }
   	  }

   	  if (x_2 < x_1)
   	  {
   		  for(int x = x_2; (x <= x_1); x++)
   		  	  {
   		  		  for(int i = 0; i < dikte; i++)
   		  		  {
   		  			  //float y = (a * x) + b;

   		  			  float y = ((y_2 - y_1)/ (x_2 - x_1))* (x - x_1) + y_1;
   		  			  UB_VGA_SetPixel(x,(y+i),10);
   		  		  }
   		  	  }
   	  }

   	  if (x_1 == x_2 && y_2 > y_1)
   	  {
   		  for(int y = y_1; (y <= y_2); y++)
   		  	  	  {
   		  	  		  for(int i = 0; i < dikte; i++)
   		  	  		  {
   		  	  			float  x = x_1;
   		  	  			UB_VGA_SetPixel(x,(y+i),10);
   		  	  		  }
   		  	  	  }
   	  }

   	  if (x_1 == x_2 && y_2 < y_1)
   	    {
   	  	  for(int y = y_2; (y <= y_1); y++)
   	  	  	  	  {
   	  	  	  		  for(int i = 0; i < dikte; i++)
   	  	  	  		  {
   	  	  	  			float  x = x_1;
   	  	  	  			UB_VGA_SetPixel(x,(y+i),10);
   	  	  	  		  }
   	  	  	  	  }
   	    }
////////////////////////////x2 en x3//////////////////////////////////////////////////////////
   	 if (x_3 > x_2)
   		  {

   			  for(int x = x_2; (x <= x_3); x++)
   			  {
   				  for(int i = 0; i < dikte; i++)
   				  {
   					  //float y = (a * x) + b;

   					  float y = ((y_3 - y_2)/ (x_3 - x_2))* (x - x_2) + y_2;
   					  UB_VGA_SetPixel(x,(y+i),10);
   				  }
   			  }
   		  }

   		  if (x_3 < x_2)
   		  {
   			  for(int x = x_3; (x <= x_2); x++)
   			  	  {
   			  		  for(int i = 0; i < dikte; i++)
   			  		  {
   			  			  //float y = (a * x) + b;

   			  			  float y = ((y_3 - y_2)/ (x_3 - x_2))* (x - x_2) + y_2;
   			  			  UB_VGA_SetPixel(x,(y+i),10);
   			  		  }
   			  	  }
   		  }

   		  if (x_2 == x_3 && y_3 > y_2)
   		  {
   			  for(int y = y_2; (y <= y_3); y++)
   			  	  	  {
   			  	  		  for(int i = 0; i < dikte; i++)
   			  	  		  {
   			  	  			float  x = x_2;
   			  	  			UB_VGA_SetPixel(x,(y+i),10);
   			  	  		  }
   			  	  	  }
   		  }

   		  if (x_2 == x_3 && y_3 < y_2)
   		    {
   		  	  for(int y = y_3; (y <= y_2); y++)
   		  	  	  	  {
   		  	  	  		  for(int i = 0; i < dikte; i++)
   		  	  	  		  {
   		  	  	  			float  x = x_2;
   		  	  	  			UB_VGA_SetPixel(x,(y+i),10);
   		  	  	  		  }
   		  	  	  	  }
   		    }

//////////////////////////////////////x1 en x3///////////////////////////////////////////////////////////
   		 if (x_3 > x_1)
   			  {

   				  for(int x = x_1; (x <= x_3); x++)
   				  {
   					  for(int i = 0; i < dikte; i++)
   					  {
   						  float y = ((y_3 - y_1)/ (x_3 - x_1))* (x - x_1) + y_1;
   						  UB_VGA_SetPixel(x,(y+i),10);
   					  }
   				  }
   			  }

   			  if (x_3 < x_1)
   			  {
   				  for(int x = x_3; (x <= x_1); x++)
   				  	  {
   				  		  for(int i = 0; i < dikte; i++)
   				  		  {
   				  			  //float y = (a * x) + b;

   				  			  float y = ((y_3 - y_1)/ (x_3 - x_1))* (x - x_1) + y_1;
   				  			  UB_VGA_SetPixel(x,(y+i),10);
   				  		  }
   				  	  }
   			  }

   			  if (x_1 == x_3 && y_3 > y_1)
   			  {
   				  for(int y = y_1; (y <= y_3); y++)
   				  	  	  {
   				  	  		  for(int i = 0; i < dikte; i++)
   				  	  		  {
   				  	  			float  x = x_1;
   				  	  			UB_VGA_SetPixel(x,(y+i),10);
   				  	  		  }
   				  	  	  }
   			  }

   			  if (x_1 == x_3 && y_3 < y_1)
   			    {
   			  	  for(int y = y_3; (y <= y_1); y++)
   			  	  	  	  {
   			  	  	  		  for(int i = 0; i < dikte; i++)
   			  	  	  		  {
   			  	  	  			float  x = x_1;
   			  	  	  			UB_VGA_SetPixel(x,(y+i),10);
   			  	  	  		  }
   			  	  	  	  }
   			    }
/////////////////////////////////////////////////////////////////////////////////////////////////

while(1)
  {
  }
}

