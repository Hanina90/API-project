//--------------------------------------------------------------
// File     : main.c
// Datum    : 10.05.2018
// Version  : 1.0
// Autor    : Raha Hanina
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>

float x_1_ = 100;
float x_2_ = 200;
float x_3_ = 10;
float y_1_ = 20;
float y_2_ = 20;
float y_3_ = 100;

int kleur_ = 0;

void driehoek (float x_1, float x_2, float x_3, float y_1, float y_2, float y_3, float kleur);

int main(void)
{

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

    UB_VGA_FillScreen(VGA_COL_GREEN);
    driehoek (x_1_, x_2_, x_3_, y_1_, y_2_, y_3_, kleur_);

while(1)
  {
  }
}

void driehoek (float x_1, float x_2, float x_3, float y_1, float y_2, float y_3, float kleur){

////////////////////////////////////x1 en x2////////////////////////////////////////////////////////////////
	    if (x_2 > x_1)
	   	  {

	   		  for(int x = x_1; (x <= x_2); x++)
	   		  {
	   				  float y = ((y_2 - y_1)/ (x_2- x_1))* (x - x_1) + y_1;
	   				  UB_VGA_SetPixel(x,y,kleur);
	   		  }
	   	  }

	   	  if (x_2 < x_1)
	   	  {
	   		  for(int x = x_2; (x <= x_1); x++)
	   		  	  {
	   		  			  float y = ((y_2 - y_1)/ (x_2 - x_1))* (x - x_1) + y_1;
	   		  			  UB_VGA_SetPixel(x,y,kleur);
	   		  	  }
	   	  }

	   	  if (x_1 == x_2 && y_2 > y_1)
	   	  {
	   		  for(int y = y_1; (y <= y_2); y++)
	   		  	  	  {
	   		  	  			float  x = x_1;
	   		  	  		    UB_VGA_SetPixel(x,y,kleur);
	   		  	  	  }
	   	  }

	   	  if (x_1 == x_2 && y_2 < y_1)
	   	    {
	   	  	  for(int y = y_2; (y <= y_1); y++)
	   	  	  	  	  {
	   	  	  	  			float  x = x_1;
	   	  	  	  	        UB_VGA_SetPixel(x,y,kleur);
	   	  	  	  	  }
	   	    }
////////////////////////////x2 en x3//////////////////////////////////////////////////////////
	   	 if (x_3 > x_2)
	   		  {

	   			  for(int x = x_2; (x <= x_3); x++)
	   			  {
	   					  float y = ((y_3 - y_2)/ (x_3 - x_2))* (x - x_2) + y_2;
	   					  UB_VGA_SetPixel(x, y, kleur);
	   			  }
	   		  }

	   		  if (x_3 < x_2)
	   		  {
	   			  for(int x = x_3; (x <= x_2); x++)
	   			  	  {
	   			  			  float y = ((y_3 - y_2)/ (x_3 - x_2))* (x - x_2) + y_2;
	   			  			  UB_VGA_SetPixel(x, y, kleur);
	   			  	  }
	   		  }

	   		  if (x_2 == x_3 && y_3 > y_2)
	   		  {
	   			  for(int y = y_2; (y <= y_3); y++)
	   			  	  	  {
	   			  	  			float  x = x_2;
	   			  	  			UB_VGA_SetPixel(x, y, kleur);
	   			  	  	  }
	   		  }

	   		  if (x_2 == x_3 && y_3 < y_2)
	   		    {
	   		  	  for(int y = y_3; (y <= y_2); y++)
	   		  	  	  	  {
	   		  	  	  			float  x = x_2;
	   		  	  	  			UB_VGA_SetPixel(x, y, kleur);
	   		  	  	  	  }
	   		    }
//////////////////////////////////////x1 en x3///////////////////////////////////////////////////////////
	   		 if (x_3 > x_1)
	   			  {

	   				  for(int x = x_1; (x <= x_3); x++)
	   				  {
	   						  float y = ((y_3 - y_1)/ (x_3 - x_1))* (x - x_1) + y_1;
	   						  UB_VGA_SetPixel(x, y, kleur);
	   				  }
	   			  }

	   			  if (x_3 < x_1)
	   			  {
	   				  for(int x = x_3; (x <= x_1); x++)
	   				  	  {
	   				  			  float y = ((y_3 - y_1)/ (x_3 - x_1))* (x - x_1) + y_1;
	   				  			  UB_VGA_SetPixel(x, y, kleur);
	   				  	  }
	   			  }

	   			  if (x_1 == x_3 && y_3 > y_1)
	   			  {
	   				  for(int y = y_1; (y <= y_3); y++)
	   				  	  	  {
	   				  	  			float  x = x_1;
	   				  	  		    UB_VGA_SetPixel(x, y, kleur);
	   				  	  	  }
	   			  }

	   			  if (x_1 == x_3 && y_3 < y_1)
	   			    {
	   			  	  for(int y = y_3; (y <= y_1); y++)
	   			  	  	  	  {
	   			  	  	  			float  x = x_1;
	   			  	  	  	        UB_VGA_SetPixel(x ,y, kleur);
	   			  	  	  	  }
	   			    }
}

