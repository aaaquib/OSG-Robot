#include "TestEnvironment.h"

using namespace osg;

#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <osgViewer/Viewer>

#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osg/Image>

using namespace osgve;

// constructor
TestEnvironment::TestEnvironment()
{
	//cube = new Cube(20.0);
	//root = new osg::MatrixTransform;
	//Torso = new BodyPart(osg::Vec3(0,0,5),4,6);
	tplugin = pluginManager->getTrackerPlugin();

	rightHand = new TrackedSphere(osg::Vec4(1,0,0,1));
	leftHand = new TrackedSphere(osg::Vec4(0,0,1,1));
}

// setup environment function - executed once upon initializiation of environment
// anything not related to the scene graph should be set up here
void TestEnvironment::setup()
{
	if(pluginManager->getInputPlugin()->loaded())
	{
		InteractiveManipulator *cam = ((InteractiveManipulator*)camera.get());
		//cam->setLookAt(osg::Vec3(0,60,0),osg::Vec3(0,60,0),osg::Vec3(0,0,1));
		//cam->setHomePosition(osg::Vec3(0,60,0),osg::Vec3(0,60,0),osg::Vec3(0,0,1));
		//cam->setPosition(osg::Vec3(0,60,0));
		cam->setPanLeftButton(5);
		cam->setPanRightButton(6);
		cam->setMoveForwardButton(7);
		cam->setMoveBackButton(8);
		cam->setMoveLeftButton(9);
		cam->setMoveRightButton(10);
		callbackManager->registerCallback(new ButtonCallback<TestEnvironment>(this, &TestEnvironment::testCallback, 0, 11, 1.0)); // device 0, button 3, timeout 2.5 seconds 
	}

	callbackManager->registerCallback(new KeyboardCallback<TestEnvironment>(this, &TestEnvironment::testCallback, osgGA::GUIEventAdapter::KEYDOWN, 't')); // key down event, t key	

	leftHand->setTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(2));
	rightHand->setTrackerData(pluginManager->getTrackerPlugin()->getTrackerData(3));
}

// create scene graph function - executed once upon initializiation of environment
void TestEnvironment::create()
{
	/*root->addChild(cube);
	cube->setPosition(osg::Vec3d(0.0, 0.0, 0.0));*/
	//camera->setLookAt(osg::Vec3(0,0,0),osg::Vec3(0,60,0),osg::Vec3(0,0,-1));

	osg::ref_ptr<osg::PositionAttitudeTransform> Body = new PositionAttitudeTransform();
	Body->setPosition(osg::Vec3(0,60,0));

	osg::ref_ptr<BodyPart> Torso = new BodyPart(osg::Vec3(0,0,5),4,6);
	Torso->setName("Torso");
	Body->addChild(Torso.get());
	//Torso->setAttitude(osg::Quat(osg::DegreesToRadians(45.0),osg::Y_AXIS));

	osg::ref_ptr<BodyPart> Head = new BodyPart(osg::Vec3(0,0,1.8),1.5,2);
	Head->setName("Head");
	osg::ref_ptr<osg::MatrixTransform> Neck = new osg::MatrixTransform;
	Neck->setName("Neck");
	Torso->addChild(Neck.get());
	osg::Matrix temp;
	temp.makeTranslate(0,0,12);
	Neck->setMatrix(temp);
	Neck->addChild(Head.get());

	osg::ref_ptr<BodyPart> rightArm = new BodyPart(osg::Vec3(0,0,-2.5),1,3);
	rightArm->setName("rightArm");

	osg::ref_ptr<osg::MatrixTransform> Rshoulder = new osg::MatrixTransform;
	Rshoulder->setName("Rshoulder");
	Torso->addChild(Rshoulder.get());
	osg::Matrix temp2;
	temp2.makeTranslate(5,0,11);
	Rshoulder->setMatrix(temp2);
	Rshoulder->addChild(rightArm.get());
	
	osg::ref_ptr<BodyPart> leftArm = new BodyPart(osg::Vec3(0,0,-2.5),1,3);
	leftArm->setName("leftArm");
	
	osg::ref_ptr<osg::MatrixTransform> Lshoulder = new osg::MatrixTransform;
	Lshoulder->setName("Lshoulder");
	Torso->addChild(Lshoulder.get());
	osg::Matrix temp3;
	temp3.makeTranslate(-5,0,11);
	Lshoulder->setMatrix(temp3);
	Lshoulder->addChild(leftArm.get());

	osg::ref_ptr<BodyPart> rightForeArm = new BodyPart(osg::Vec3(0,0,-2.55),0.8,3.5);
	rightForeArm->setName("rightForeArm");

	osg::ref_ptr<osg::MatrixTransform> Relbow = new osg::MatrixTransform;
	Relbow->setName("Relbow");
	rightArm->addChild(Relbow.get());
	osg::Matrix temp4;
	temp4.makeTranslate(0,0,-5);
	Relbow->setMatrix(temp4);
	Relbow->addChild(rightForeArm.get());

	osg::ref_ptr<BodyPart> leftForeArm = new BodyPart(osg::Vec3(0,0,-2.55),0.8,3.5);
	leftForeArm->setName("leftForeArm");

	osg::ref_ptr<osg::MatrixTransform> Lelbow = new osg::MatrixTransform;
	Lelbow->setName("Lelbow");
	leftArm->addChild(Lelbow.get());
	osg::Matrix temp5;
	temp5.makeTranslate(0,0,-5);
	Lelbow->setMatrix(temp5);
	Lelbow->addChild(leftForeArm.get());

	osg::ref_ptr<BodyPart> rightUpperLeg = new BodyPart(osg::Vec3(0,0,-3.6),1.6,4);
	rightUpperLeg->setName("rightUpperLeg");
	
	osg::ref_ptr<osg::MatrixTransform> Rhip = new osg::MatrixTransform;
	Rhip->setName("Rhip");
	Torso->addChild(Rhip.get());
	osg::Matrix temp6;
	temp6.makeTranslate(2,0,-1);
	Rhip->setMatrix(temp6);
	Rhip->addChild(rightUpperLeg.get());

	osg::ref_ptr<BodyPart> leftUpperLeg = new BodyPart(osg::Vec3(0,0,-3.6),1.6,4);
	leftUpperLeg->setName("leftUpperLeg");
	
	osg::ref_ptr<osg::MatrixTransform> Lhip = new osg::MatrixTransform;
	Lhip->setName("Lhip");
	Torso->addChild(Lhip.get());
	osg::Matrix temp7;
	temp7.makeTranslate(-2,0,-1);
	Lhip->setMatrix(temp7);
	Lhip->addChild(leftUpperLeg.get());

	osg::ref_ptr<BodyPart> rightLowerLeg = new BodyPart(osg::Vec3(0,0,-3.5),1.3,5);
	rightLowerLeg->setName("rightLowerLeg");
	
	osg::ref_ptr<osg::MatrixTransform> Rknee = new osg::MatrixTransform;
	Rknee->setName("Rknee");
	rightUpperLeg->addChild(Rknee.get());
	osg::Matrix temp8;
	temp8.makeTranslate(0,0,-7);
	Rknee->setMatrix(temp8);
	Rknee->addChild(rightLowerLeg.get());

	osg::ref_ptr<BodyPart> leftLowerLeg = new BodyPart(osg::Vec3(0,0,-3.5),1.3,5);
	leftLowerLeg->setName("leftLowerLeg");
	
	osg::ref_ptr<osg::MatrixTransform> Lknee = new osg::MatrixTransform;
	Lknee->setName("Lknee");
	leftUpperLeg->addChild(Lknee.get());
	osg::Matrix temp9;
	temp9.makeTranslate(0,0,-7);
	Lknee->setMatrix(temp9);
	Lknee->addChild(leftLowerLeg.get());

	root->setName("root");
	root->addChild(Body.get());
	root->addChild(rightHand);
	root->addChild(leftHand);

	/*osg::ref_ptr<HumanSelectController> selection = new HumanSelectController( Body->asGroup());
	osg::ref_ptr<HumanRotateController> rotation = new HumanRotateController( Body->asGroup() );

	TestEnvironment::viewer->addEventHandler(selection.get());
	TestEnvironment::viewer->addEventHandler(rotation.get());*/

	//callbackManager->registerCallback(new KeyboardCallback<TestEnvironment>(this, &TestEnvironment::testCallback, osgGA::GUIEventAdapter::KEYDOWN, 't'));
}

// update function - per frame updates occur here
void TestEnvironment::update()
{
	leftHand->update();
	rightHand->update();
}

void TestEnvironment::testCallback()
{
	using namespace std;
	cout << "void TestEnvironment::testCallback()" << endl;
}