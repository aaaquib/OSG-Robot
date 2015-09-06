#ifndef OSGVE_TESTENVIRONMENT
#define OSGVE_TESTENVIRONMENT

#include <osgVirtualEnvironment/VirtualEnvironment.h>
#include <osgVirtualEnvironment/VirtualObject.h>

#include "HumanController.h"
#include "BodyPart.h"

#include "Cube.h"
#include "TrackedSphere.h"

class TestEnvironment : public osgve::VirtualEnvironment
{
	public:
		TestEnvironment();

	protected:
		virtual const char* getName() const { return "Test Environment"; }
		virtual void create();
		virtual void setup();
		virtual void update();


	private:
		
		void testCallback();
		Cube *cube;

		TrackedSphere* leftHand;
	    TrackedSphere* rightHand;

		osgve::Plugin* tplugin;
};


#endif