#include "BodyPart.h"

BodyPart::BodyPart(osg::Vec3 &center, float radius, float height)
{
	//make a shape here
	ref_ptr<Capsule> capsule = new Capsule(center, radius, height);
	ref_ptr<ShapeDrawable> drawable = new ShapeDrawable(capsule);
	drawable->setColor(osg::Vec4(1,1,1,1));
	ref_ptr<Geode> geo = new Geode;
	geo->addDrawable(drawable);

	transform = new PositionAttitudeTransform;
	transform->addChild(geo);

	Group::addChild(transform);
	selected = false;
	xrot = yrot = zrot = 0;
}

void BodyPart::update()
{
	// put your source code here
	osg::ref_ptr<osg::ShapeDrawable> sd = dynamic_cast<osg::ShapeDrawable*>(transform->getChild(0)->asGeode()->getDrawable(0));
	if(selected)
	{
		sd->setColor(osg::Vec4(1,0,0,1));
	}
	else
		sd->setColor(osg::Vec4(1,1,1,1));
}