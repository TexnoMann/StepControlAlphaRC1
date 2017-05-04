#include "Arduino.h"
#include "StepControl.h"

StepControl::StepControl(int en, int step, int dir, int feth){
	_degrees=0L;
	_mm=0L;
	_feth=feth;
	_enpin=en;
	_steppin=step;
	_dirpin=dir;
	microsstep=1000;
	_minspeeds=2000;
	_curspeeds=_minspeeds;
	i=0L;
	_accel=1000;
	_speeds=400;
	pinMode(_enpin, OUTPUT);
	pinMode(_dirpin,OUTPUT);
	pinMode(_steppin,OUTPUT);
	digitalWrite(_enpin, LOW);
}

void StepControl::setAcceleration(int accel){
	_accel=accel;
}
void StepControl::setMinSpeeds(int minspeeds){
	_minspeeds=minspeeds;
}

void StepControl::setSpeeds(int speeds){
	_speeds=speeds;
	microsstep= 1000000/_speeds;
}

void StepControl::setCurSpeeds(){
	if(_curspeeds!=_speeds) _curspeeds+=_accel;
	if(_curspeeds>_speeds) _curspeeds=_speeds;
	microsstep= 1000000/_curspeeds;
}

void StepControl::moveTo(long long degrees){
	_degrees= degrees;
	_curspeeds=_minspeeds;
	if(_degrees!=0){
	
		if(_degrees>0){
			digitalWrite(_dirpin, HIGH);
	  		for(i=0L;i<_degrees; i++){
				digitalWrite(_steppin, HIGH);
				setCurSpeeds();
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
	  	}
	  	else{
	  		digitalWrite(_dirpin, LOW);
	  		for(i=0L;i>_degrees; i--){
				digitalWrite(_steppin, HIGH);
				setCurSpeeds();
	  			delayMicroseconds(microsstep); 
	  			digitalWrite(_steppin, LOW);
	  		}
		  }
	
	}
}

void StepControl::moveToDistance(double mm){
	_mm=mm;
	_degrees=_mm*_feth;
	moveTo(_degrees);
}

void StepControl::go(boolean g){
	_g=g;
	if(_g) {
		digitalWrite(_dirpin, HIGH);
		digitalWrite(_steppin, HIGH);
		microsstep= 1000000/_speeds;
	  	delayMicroseconds(microsstep); 
	  	digitalWrite(_steppin, LOW);
	  }
	
	else {
		digitalWrite(_dirpin, LOW);
		digitalWrite(_steppin, HIGH);
		microsstep= 1000000/_speeds;
	  	delayMicroseconds(microsstep); 
	  	digitalWrite(_steppin, LOW);
	  }
}



