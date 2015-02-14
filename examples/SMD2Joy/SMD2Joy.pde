#include <SMDjoystick.h>
/*
Joystick emulation example
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

You will need JoyState library
*/
SMDjoystick j(2,3,4,5,6,7,8);
JoyState_t s;
void setup() 
{
	s.xAxis=128;
	s.yAxis=128;
	s.zAxis=128;
	s.xRotAxis=128;
	s.yRotAxis=128;
	s.zRotAxis=128;
	s.throttle=128;
	s.rudder=128;
	s.hatSw1=0;
	s.hatSw2=0;
}
void loop()
{
	s.buttons=j.read();
	Joystick.setState(&s);
}