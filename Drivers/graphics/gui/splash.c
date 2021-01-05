/*
 * splash.c
 *
 *  Created on: Aug 7, 2017
 *      Author: jose
 */

#include "splash.h"
#include "oled.h"
#define SPLASH_TIMEOUT 1000

//widget_t splash_widget;

screen_t splash_screen = {

	processInput:	splash_processInput,
	init:			splash_init,
	draw:			splash_draw,
};



static uint32_t splash_time;
void splash_setup(screen_t * scr) {

	scr->processInput = &splash_processInput;
	scr->init = &splash_init;
	scr->draw = &splash_draw;
	scr->update = NULL;
}

int splash_processInput(screen_t * scr, RE_Rotation_t input, RE_State_t *state) {
	if(HAL_GetTick() - splash_time > SPLASH_TIMEOUT){
		return screen_main;
	}
	return -1;
}
/*
const uint8_t splashBMP[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x60, 0x70, 0x30, 0x30, 0x38, 0x38, 0x38, 0x18, 0x18,
		0x18, 0x38, 0x38, 0x38, 0x30, 0x70, 0x70, 0x60, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x78,
		0x1e, 0x0f, 0x87, 0xc3, 0xf1, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f,
		0x3f, 0xdf, 0xef, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf1, 0xe1, 0xc3, 0x87, 0x0e, 0x3c, 0xf8,
		0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x03, 0x00,
		0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xcf, 0xc7, 0xe3, 0x23, 0x01, 0x00, 0x04,
		0xc7, 0xe7, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xe0, 0x00,
		0x07, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xf0, 0x80,
		0x07, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe7, 0x63, 0x21, 0x00, 0x00, 0x80, 0xc2, 0xe3,
		0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x01, 0x80,
		0xf0, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f,
		0x1e, 0x3c, 0x78, 0x71, 0xe3, 0xc7, 0xc7, 0x83, 0x81, 0x00, 0x00, 0x00, 0x00, 0x01, 0x21, 0x39,
		0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x9f, 0x8f, 0xc7, 0xc3, 0xe1, 0x70, 0x38, 0x3c, 0x1f, 0x07,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06,
		0x06, 0x06, 0x06, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x04, 0x04, 0x04, 0xfc, 0x04, 0x04, 0x04, 0x00, 0x00, 0xfe, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00,
		0xe0, 0xb0, 0x90, 0x90, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x64, 0x44, 0xc4, 0x80,
		0x00, 0xc0, 0xf0, 0x10, 0x10, 0x10, 0xe0, 0x80, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0xe0, 0x10, 0x10,
		0x10, 0xfe, 0xfe, 0x00, 0xc0, 0xe0, 0x90, 0x90, 0x90, 0xe0, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10,
		0x00, 0xf6, 0x00, 0x00, 0xe0, 0xf0, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0xe0, 0x30, 0x10, 0x10,
		0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x64, 0x44, 0xc4, 0x84, 0x00, 0x00, 0xfc, 0x10,
		0x10, 0x00, 0x00, 0x90, 0x90, 0x90, 0xf0, 0xe0, 0x00, 0x00, 0xfc, 0x10, 0x10, 0x10, 0x00, 0xf6,
		0xe0, 0x00, 0xc0, 0x70, 0x10, 0x10, 0x10, 0xe0, 0xc0, 0x00, 0xf0, 0xf0, 0x10, 0x10, 0x30, 0xe0,
		0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
		0x03, 0x06, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x06, 0x03,
		0x00, 0x01, 0x03, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x03, 0x07, 0x04, 0x00, 0x03, 0x06, 0x04,
		0x04, 0x07, 0x03, 0x00, 0x01, 0x03, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
		0x00, 0x07, 0x00, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x13, 0x12, 0x14, 0x16,
		0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00, 0x00, 0x07, 0x04,
		0x04, 0x04, 0x00, 0x07, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x03, 0x04, 0x04, 0x04, 0x00, 0x07,
		0x03, 0x00, 0x01, 0x03, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x07
};
*/

// Credits: Jesus Vallejo  https://github.com/jesusvallejo/
const uint8_t splashBMP[] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x8f, 0x8f, 0x87, 0x07,
		0x07, 0x03, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f,
		0x1f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xbf, 0xbf, 0xbb, 0xab, 0xab, 0xab, 0x01, 0x70, 0x51, 0x50, 0x51, 0xd0, 0x01,
		0x10, 0x11, 0xf0, 0x11, 0x10, 0x01, 0xf0, 0x31, 0x40, 0x31, 0xf0, 0x01, 0xab, 0xab, 0xbb, 0xbb,
		0xff, 0xff, 0xff, 0x7f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x83, 0xc1,
		0xe1, 0xe1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xe3, 0xe6, 0xcc, 0x88, 0x08, 0x08,
		0x08, 0x88, 0x88, 0x88, 0x08, 0x09, 0x0f, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0x03, 0x03,
		0xf3, 0xf3, 0xff, 0xff, 0x03, 0x03, 0x9f, 0x9f, 0x03, 0x03, 0xff, 0xff, 0x03, 0x03, 0x93, 0x93,
		0x93, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xfb, 0xfb, 0xfb, 0xfb, 0xeb, 0xeb, 0xaa, 0xaa, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x88,
		0xa8, 0xa8, 0x51, 0x00, 0xc8, 0xa8, 0x91, 0x00, 0x00, 0x00, 0x01, 0x00, 0xaa, 0xab, 0xaf, 0xaf,
		0xff, 0xff, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0xfe, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xdf, 0x0f, 0x07, 0x07, 0x0f, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
		0x00, 0x03, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x1f, 0x1f, 0x9c, 0x9c,
		0x9f, 0x9f, 0xff, 0xff, 0x1c, 0x1c, 0x9f, 0x9f, 0x1c, 0x1c, 0xff, 0xff, 0x1c, 0x1c, 0xfc, 0xfc,
		0xfc, 0xfc, 0xff, 0xff, 0x1f, 0x1f, 0x1f, 0xdf, 0xdf, 0x1f, 0xff, 0xff, 0x1f, 0x1f, 0x9f, 0x9f,
		0x9f, 0x9f, 0xff, 0xff, 0x1f, 0x1f, 0x9f, 0x9f, 0x9f, 0x1f, 0xff, 0xff, 0x9f, 0x9f, 0x1f, 0x1f,
		0x9f, 0x9f, 0xff, 0xff, 0x1f, 0x1e, 0x3e, 0x7e, 0x1e, 0x1c, 0xf0, 0xfc, 0x18, 0x1c, 0x90, 0x9c,
		0x98, 0x9c, 0xf0, 0xfc, 0xe0, 0xfc, 0x80, 0xfc, 0xe0, 0xfc, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xff,
		0xff, 0xff, 0xff, 0xf0, 0x80, 0x00, 0x00, 0x70, 0x7f, 0x70, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x9f,
		0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0x1f, 0x13, 0x10,
		0x10, 0x10, 0x1f, 0x00, 0x00, 0x07, 0x07, 0x87, 0xf2, 0xff, 0xff, 0xff, 0xe4, 0xe4, 0xe4, 0xe4,
		0xe0, 0xe0, 0xff, 0xff, 0xe0, 0xe0, 0xe7, 0xe7, 0xe0, 0xe0, 0xff, 0xff, 0xe0, 0xe0, 0xe7, 0xe7,
		0xe7, 0xe7, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xef, 0xef, 0xe0, 0xff, 0xff, 0xe0, 0xe0, 0xe4, 0xe4,
		0xe4, 0xe7, 0xff, 0xff, 0xe0, 0xe0, 0xfe, 0xf8, 0xe2, 0xe6, 0xff, 0xff, 0xe7, 0xe7, 0xe0, 0xe0,
		0xe7, 0xe7, 0xff, 0xff, 0xe0, 0xe0, 0xfe, 0xfc, 0xe0, 0xe0, 0xff, 0xff, 0xe0, 0xe0, 0xe7, 0xe4,
		0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0xc0, 0xf0, 0xf8, 0xfe, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0,
		0xc0, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x20, 0x20, 0x24, 0x24,
		0x04, 0x04, 0xff, 0xff, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0xff, 0xff, 0x00, 0x00, 0xe4, 0xe4,
		0x00, 0x00, 0xff, 0xff, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0xff, 0xff, 0x3c, 0x3c, 0x00, 0x00,
		0x3c, 0x3c, 0xff, 0xff, 0x00, 0x00, 0x3c, 0x3c, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xf9, 0xf3,
		0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x52, 0x6d, 0xdf, 0xab, 0x7f, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0x8f, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff,
		0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
		0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
		0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0x1f, 0x1f, 0x0f, 0xff, 0x7f, 0x7f,
		0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x79, 0x76, 0x55, 0x7e, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff,
		0xfc, 0xfc, 0xfc, 0xfc, 0xff, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
		0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
		0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xff, 0xf8, 0xf8, 0xf0, 0xff, 0xfe, 0xfe,
		0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
UG_BMP_MONO splash = {
		p: splashBMP,
		width: 128,
		height: 64
};

void splash_init(screen_t * scr) {
	splash_time = HAL_GetTick();
}

void splash_draw(screen_t * scr) {
	static bool done=0;
	if(!done){
		done=1;
		UG_DrawBMP_MONO(0,0, &splash);
	}
}
