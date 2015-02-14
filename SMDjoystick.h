#ifndef _SMDJOYSTICK_H_
#define _SMDJOYSTICK_H_

#include <Arduino.h>

/**
SegaMegaDrive gamepad arduino library by AsGreyWolf
**/
enum{
	SMD_A=0,
	SMD_B,
	SMD_C,
	SMD_EMPTY_1,
	SMD_X,
	SMD_Y,
	SMD_Z,
	SMD_MODE,
	SMD_EMPTY_2,
	SMD_START,
	SMD_EMPTY_3,
	SMD_EMPTY_4,
	SMD_UP,
	SMD_DOWN,
	SMD_LEFT,
	SMD_RIGHT,
	SMD_MAX_KEYS
};
class SMDjoystick{
	public:
		SMDjoystick(int upPin,int downPin,int leftPin,int rightPin,int aPin,int selectPin,int startPin);
		bool read(int key);
		uint16_t read();
	private:
		int up;
		int down;
		int left;
		int right;
		int a;
		int select;
		int start;
};

#endif
