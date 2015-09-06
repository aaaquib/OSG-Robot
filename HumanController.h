#include <osg/Group>
#include <osgGA/GUIEventHandler>
#include "BodyPart.h"
#include <osg/MatrixTransform>

class HumanSelectController : public osgGA::GUIEventHandler
{
public:
	HumanSelectController( osg::Group* node ) : body(node)
	{
	}
virtual bool handle( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa );

//osg::Node* findNamedNode(const std::string& searchName, 
//                                          osg::Node* currNode);
protected:
	osg::ref_ptr<osg::Group> body;
};

class HumanRotateController : public osgGA::GUIEventHandler
{
public:
	HumanRotateController( osg::Group* node ) : body(node)
	{
	}
virtual bool handle( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa );

//osg::Node* findNamedNode(const std::string& searchName, 
//                                          osg::Node* currNode);
protected:
	osg::ref_ptr<osg::Group> body;
};