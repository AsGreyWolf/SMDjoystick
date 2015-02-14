#include "SMDjoystick.h"
SMDjoystick::SMDjoystick(int upPin,int downPin,int leftPin,int rightPin,int aPin,int selectPin,int startPin):up(upPin),down(downPin),left(leftPin),right(rightPin),a(aPin),select(selectPin),start(startPin){
	pinMode(up,INPUT);
	pinMode(down,INPUT);
	pinMode(left,INPUT);
	pinMode(right,INPUT);
	pinMode(a,INPUT);
	pinMode(start,INPUT);
	pinMode(select,OUTPUT);
}
uint16_t SMDjoystick::read(){
	uint16_t data=0;
	digitalWrite(select,LOW);
	data+=!digitalRead(a)<<SMD_A;
	data+=!digitalRead(start)<<SMD_START;
	data+=!digitalRead(up)<<SMD_UP;
	data+=!digitalRead(down)<<SMD_DOWN;
	delayMicroseconds(1200);
	digitalWrite(select,HIGH);
	data+=!digitalRead(left)<<SMD_LEFT;
	data+=!digitalRead(right)<<SMD_RIGHT;
	data+=!digitalRead(a)<<SMD_B;
	data+=!digitalRead(start)<<SMD_C;
	digitalWrite(select,LOW);
	delayMicroseconds(1200);
	digitalWrite(select,HIGH);
	digitalWrite(select,LOW);
	digitalWrite(select,HIGH);
	data+=!digitalRead(up)<<SMD_Z;
	data+=!digitalRead(down)<<SMD_Y;
	data+=!digitalRead(left)<<SMD_X;
	data+=!digitalRead(right)<<SMD_MODE;
	digitalWrite(select,LOW);
	digitalWrite(select,HIGH);
	return data;
}
bool SMDjoystick::read(int key){
	bool val=false;
	switch(key){
	case SMD_UP:
		val=!digitalRead(up);
		break;
	case SMD_DOWN:
		val=!digitalRead(down);
		break;
	case SMD_LEFT:
		digitalWrite(select,HIGH);
		val=!digitalRead(left);
		break;
	case SMD_RIGHT:
		digitalWrite(select,HIGH);
		val=!digitalRead(right);
		break;
	case SMD_START:
		digitalWrite(select,LOW);
		val=!digitalRead(start);
		break;
	case SMD_A:
		digitalWrite(select,LOW);
		val=!digitalRead(a);
		break;
	case SMD_B:
		digitalWrite(select,HIGH);
		val=!digitalRead(a);
		break;
	case SMD_C:
		digitalWrite(select,HIGH);
		val=!digitalRead(start);
		break;
	case SMD_X:
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		val=!digitalRead(left);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		break;
	case SMD_Y:
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		val=!digitalRead(down);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		break;
	case SMD_Z:
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		val=!digitalRead(up);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		break;
	case SMD_MODE:
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		delayMicroseconds(1200);
		digitalWrite(select,HIGH);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		val=!digitalRead(right);
		digitalWrite(select,LOW);
		digitalWrite(select,HIGH);
		break;
	}
	return val;
}