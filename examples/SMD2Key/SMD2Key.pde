#include <SMDjoystick.h>
/*
Keyboard emulation example
Connect your gamepad:
gamepad->arduino
1->2
2->3
3->4
4->5
5->5v
6->6
7->7
8->GND
9->8
*/
SMDjoystick j(2,3,4,5,6,7,8);
uint16_t data=0;
void setup() 
{
	Keyboard.begin();
}
uint16_t lastdata;
char keys[]={
    'f',
    'r',
    ' ',
    0,
    KEY_LEFT_SHIFT ,
    KEY_TAB ,
    KEY_BACKSPACE,
    KEY_ESC,
    0,
    KEY_RETURN,
    0,
    0,
    'w',
    's',
    'a',
    'd'
 };
   
void loop()
{
	data=j.read();
	for(int i=0;i<SMD_MAX_KEYS;i++){
		if(keys[i]==0) continue;
		bool c=(data>>i)&1;
		if(c!=((lastdata>>i)&1)){
			if(c)Keyboard.press(keys[i]);
			else Keyboard.release(keys[i]);
		}
	}
	lastdata=data;
	delay(10);
}
