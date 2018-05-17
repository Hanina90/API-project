//--------------------------------------------------------------
// File     : main.c
// Datum    : 12.05.2018
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

int radius_y_ =  10;
int radius_x_ =  100;
int x_mp_ = 100;
int y_mp_ = 100;
int kleur_ = 10;
void ellipse (int x_mp, int y_mp, int radius_x, int radius_y, int kleur );

//float y;

int main(void)
{

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_GREEN);

	ellipse(x_mp_, y_mp_, radius_x_, radius_y_, kleur_);

    while(1)
	  {
	  }
}

void ellipse (int x_mp, int y_mp, int radius_x, int radius_y, int kleur ){

int hh;
int ww;
int hhww;
int x0;
int dx = 0;

hh =  pow (radius_y, 2);
ww = pow (radius_x, 2);
hhww = hh * ww;
x0 = radius_x;

// do the horizontal diameter
for (int x = -radius_x; x <= radius_x; x++)
	 UB_VGA_SetPixel(x_mp + x, y_mp, kleur);

// now do both halves at the same time, away from the diameter
for (int y = 1; y <= radius_y; y++)
	{
		int x1 = x0 - (dx - 1);  // try slopes of dx - 1 or more
		for ( ; x1 > 0; x1--)
			if (x1*x1*hh + y*y*ww <= hhww)
				break;
		dx = x0 - x1;  // current approximation of the slope
		x0 = x1;

		for (int x = -x0; x <= x0; x++)
		{
			UB_VGA_SetPixel(x_mp + x,y_mp - y, kleur);
			UB_VGA_SetPixel(x_mp + x,y_mp + y, kleur);
		}
	}
}


