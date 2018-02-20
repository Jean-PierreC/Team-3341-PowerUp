#include "OI.h"
#include "Commands/MoveLiftToHeight.h"
#include "Commands/LiftPositionControl.h"
#include "Commands/MoveLiftToMinHeight.h"
#include "Commands/AcquireCrate.h"
#include "Commands/ReleaseCrate.h"
#include "Commands/StopCatcher.h"
#include "Commands/LiftPositionControl.h"
#include "Commands/MoveLift.h"

using namespace std;

OI::OI() : leftStick(new Joystick(0)),
rightStick(new Joystick(1)),
liftStick(new Joystick(2))
{
		shootCrate = new JoystickButton(leftStick, 1);
		shootCrate->WhenPressed(new ReleaseCrate());
		shootCrate->WhenReleased(new StopCatcher());

		getCrate = new JoystickButton(leftStick, 2);
		getCrate->WhenPressed(new AcquireCrate());
		getCrate->WhenReleased(new StopCatcher());

	// Process operator interface input here.
	testButton = new JoystickButton(liftStick,4);
	calibrateLift = new JoystickButton(liftStick,8);
	positionPidTest = new JoystickButton(liftStick,1);
	testButton->WhenPressed(new MoveLiftToHeight(25));
	calibrateLift->WhenPressed(new MoveLiftToMinHeight());
	positionPidTest->WhenPressed(new LiftPositionControl());
	positionPidTest->WhenReleased(new MoveLift());
}

Joystick* OI::getLeftStick()
{
	return leftStick;
}

Joystick* OI::getRightStick()
{
	return rightStick;
}


Joystick* OI::getLiftStick()
{
	return liftStick;
}

