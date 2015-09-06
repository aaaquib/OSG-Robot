#include "Cube.h"

Cube::Cube(double width)
{
	// this draws a sphere with the given radius
	// and then sets the texture
	osg::Geode *geode = new osg::Geode();
	geode->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3d(0.0, 0.0, 0.0), width)));
	setModel(geode);	
}

void Cube::update()
{

}