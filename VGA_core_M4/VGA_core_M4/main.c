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

float x_one = 200;
float x_two = 100;
float y_one = 200;
float y_two = 10;

int dikte = 1;

int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_GREEN);

	lijn(x_one, x_two, y_one, y_two);

	while(1)
		  	{
		  		//lijn(x_one, x_two, y_one, y_two);
		  	}
}
 //////////////////////////Functies//////////////////////////////////////////////////////

void lijn (float x_begin, float x_eind, float y_begin, float y_eind)
{
	 if (x_eind > x_begin)
	  {

		  for(int x = x_begin; (x <= x_eind); x++)
		  {
			  for(int i = 0; i < dikte; i++)
			  {
				  //float y = (a * x) + b;

				  float y = ((y_eind - y_begin)/ (x_eind - x_begin))* (x - x_begin) + y_begin;
				  UB_VGA_SetPixel(x,(y+i),10);
			  }
		  }
	  }

	  if (x_eind < x_begin)
	  {
		  for(int x = x_eind; (x <= x_begin); x++)
		  	  {
		  		  for(int i = 0; i < dikte; i++)
		  		  {
		  			  //float y = (a * x) + b;

		  			  float y = ((y_eind - y_begin)/ (x_eind - x_begin))* (x - x_begin) + y_begin;
		  			  UB_VGA_SetPixel(x,(y+i),10);
		  		  }
		  	  }
	  }

	  if (x_begin == x_eind && y_eind > y_begin)
	  {
		  for(int y = y_begin; (y <= y_eind); y++)
		  	  	  {
		  	  		  for(int i = 0; i < dikte; i++)
		  	  		  {
		  	  			float  x = x_begin;
		  	  			UB_VGA_SetPixel(x,(y+i),10);
		  	  		  }
		  	  	  }
	  }

	  if (x_begin == x_eind && y_eind < y_begin)
	    {
	  	  for(int y = y_eind; (y <= y_begin); y++)
	  	  	  	  {
	  	  	  		  for(int i = 0; i < dikte; i++)
	  	  	  		  {
	  	  	  			float  x = x_begin;
	  	  	  			UB_VGA_SetPixel(x,(y+i),10);
	  	  	  		  }
	  	  	  	  }
	    }
}



