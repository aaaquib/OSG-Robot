#ifndef OSGVE_CUBE
#define OSGVE_CUBE

#include <osgVirtualEnvironment/VirtualObject.h>
#include <osg/ShapeDrawable>


class Cube : public osgve::VirtualObject
{
	public:
		Cube(double width);
		void update();



};

#endif