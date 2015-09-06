#include "HumanController.h"
#include<osg/PositionAttitudeTransform>

osg::ref_ptr<osg::MatrixTransform> rotationjoint;

bool HumanSelectController::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
{
	if ( !body ) return false;
	
	osg::ref_ptr<BodyPart> torso = dynamic_cast<BodyPart*>(body->getChild(0));
	
	osg::ref_ptr<osg::MatrixTransform> neck = dynamic_cast<osg::MatrixTransform*>(torso->getChild(1));
	osg::ref_ptr<BodyPart> Head = dynamic_cast<BodyPart*>(neck->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Rshoulder = dynamic_cast<osg::MatrixTransform*>(torso->getChild(2));
	osg::ref_ptr<BodyPart> Rarm = dynamic_cast<BodyPart*>(Rshoulder->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Lshoulder = dynamic_cast<osg::MatrixTransform*>(torso->getChild(3));
	osg::ref_ptr<BodyPart> Larm = dynamic_cast<BodyPart*>(Lshoulder->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Relbow = dynamic_cast<osg::MatrixTransform*>(Rarm->getChild(1));
	osg::ref_ptr<BodyPart> Rforearm = dynamic_cast<BodyPart*>(Relbow->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Lelbow = dynamic_cast<osg::MatrixTransform*>(Larm->getChild(1));
	osg::ref_ptr<BodyPart> Lforearm = dynamic_cast<BodyPart*>(Lelbow->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Rhip = dynamic_cast<osg::MatrixTransform*>(torso->getChild(4));
	osg::ref_ptr<BodyPart> Rupperleg = dynamic_cast<BodyPart*>(Rhip->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Lhip = dynamic_cast<osg::MatrixTransform*>(torso->getChild(5));
	osg::ref_ptr<BodyPart> Lupperleg = dynamic_cast<BodyPart*>(Lhip->getChild(0));

		osg::ref_ptr<osg::MatrixTransform> Rknee = dynamic_cast<osg::MatrixTransform*>(Rupperleg->getChild(1));
	osg::ref_ptr<BodyPart> Rlowerleg = dynamic_cast<BodyPart*>(Rknee->getChild(0));

	osg::ref_ptr<osg::MatrixTransform> Lknee = dynamic_cast<osg::MatrixTransform*>(Lupperleg->getChild(1));
	osg::ref_ptr<BodyPart> Llowerleg = dynamic_cast<BodyPart*>(Lknee->getChild(0));

	switch ( ea.getEventType() )
	{
		case osgGA::GUIEventAdapter::KEYDOWN:

		switch ( ea.getKey() )
		{
		case osgGA::GUIEventAdapter::KEY_0 :
			{
			if(!torso->selected)
			{
				torso->selected = true;
				Head->selected=false;
				Rarm->selected=false;
				Larm->selected=false;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(torso->getParent(0));
			}
			else
				torso->selected = false;

			torso->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_1 :
			{
			if(!Head->selected)
			{
				Head->selected = true;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Head->getParent(0));
			}
			else
				Head->selected = false;

			Head->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_2 :
			{
			if(!Rarm->selected)
			{
				Rarm->selected = true;
				Head->selected = false;
				torso->selected = false;
				Larm->selected=false;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Rarm->getParent(0));
			}
			else
				Rarm->selected = false;

			Rarm->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_3 :
			{
			if(!Larm->selected)
			{
				Larm->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Larm->getParent(0));
			}
			else
				Larm->selected = false;

			Larm->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_4 :
			{
			if(!Rforearm->selected)
			{
				Rforearm->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Rforearm->getParent(0));
			}
			else
				Rforearm->selected = false;

			Rforearm->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_5 :
			{
			if(!Lforearm->selected)
			{
				Lforearm->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Rforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Lforearm->getParent(0));
			}
			else
				Lforearm->selected = false;

			Lforearm->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_6 :
			{
			if(!Rupperleg->selected)
			{
				Rupperleg->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Rupperleg->getParent(0));
			}
			else
				Rupperleg->selected = false;

			Rupperleg->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_7 :
			{
			if(!Lupperleg->selected)
			{
				Lupperleg->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Rlowerleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Lupperleg->getParent(0));
			}
			else
				Lupperleg->selected = false;

			Lupperleg->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_8 :
			{
			if(!Rlowerleg->selected)
			{
				Rlowerleg->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Llowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Rlowerleg->getParent(0));
			}
			else
				Rlowerleg->selected = false;

			Rlowerleg->update();
			}
			break;
		case osgGA::GUIEventAdapter::KEY_9 :
			{
			if(!Llowerleg->selected)
			{
				Llowerleg->selected = true;
				Head->selected = false;
				torso->selected = false;
				Rarm->selected=false;
				Larm->selected=false;;
				Rforearm->selected=false;
				Lforearm->selected=false;
				Rupperleg->selected=false;
				Lupperleg->selected=false;
				Rlowerleg->selected=false;
				rotationjoint = dynamic_cast<osg::MatrixTransform*>(Llowerleg->getParent(0));
			}
			else
				Llowerleg->selected = false;

			Llowerleg->update();
			}
			break;

		/*case osgGA::GUIEventAdapter::KEY_A :
			{
			osg::Matrix matrix = body->getMatrix();
			matrix *= osg::Matrix::translate(-5,0,0);
			body->setMatrix(matrix);
			}
			break;

			case osgGA::GUIEventAdapter::KEY_D :
			{
			osg::Matrix matrix = body->getMatrix();
			matrix *= osg::Matrix::translate(5,0,0);
			body->setMatrix(matrix);
			}
			break;

			case osgGA::GUIEventAdapter::KEY_W :
			{
			osg::Matrix matrix = body->getMatrix();
			matrix *= osg::Matrix::translate(0,5,0);
			body->setMatrix(matrix);
			}
			break;

			case osgGA::GUIEventAdapter::KEY_S :
			{
			osg::Matrix matrix = body->getMatrix();
			matrix *= osg::Matrix::translate(0,-5,0);
			body->setMatrix(matrix);
			}
			break;*/

		default: break;
		}

		torso->update();
		Head->update();
		Rarm->update();
		Larm->update();
		Rforearm->update();
		Lforearm->update();
		Rupperleg->update();
		Lupperleg->update();
		Rlowerleg->update();
		Llowerleg->update();

		break;
		default:
		break;
	}
	return false;
}

bool HumanRotateController::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
{
	if ( !body ) return false;

	if(!rotationjoint.valid()) return false;

	switch ( ea.getEventType() )
	{
		case osgGA::GUIEventAdapter::KEYDOWN:
			switch ( ea.getKey() )
			{
			case osgGA::GUIEventAdapter::KEY_Up:
			{
				osg::ref_ptr<BodyPart> selectedPart = dynamic_cast<BodyPart*>(rotationjoint->getChild(0));
				osg::Matrix matrix = rotationjoint->getMatrix();
				std::string joint = rotationjoint->getName();

				if ( ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_SHIFT )
				{
					if(joint == "Rhip" || joint == "Lhip")
					{
						selectedPart->zrot += 5;
					if(selectedPart->zrot>10) selectedPart->zrot = 10;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::Z_AXIS));

					rotationjoint->setMatrix(matrix);
					}
				}

				else if(joint == "Rknee" || joint == "Lknee")
				{
					selectedPart->xrot += 5;
					if(selectedPart->xrot>80) selectedPart->xrot = 80;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Relbow" || joint == "Lelbow")
				{
					selectedPart->xrot += 5;
					if(selectedPart->xrot>80) selectedPart->xrot = 80;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				else if(joint == "Rhip" || joint == "Lhip")
				{
					selectedPart->xrot += 5;
					if(selectedPart->xrot>80) selectedPart->xrot = 80;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				
				else if(joint == "Rshoulder" || joint == "Lshoulder")
				{
					selectedPart->xrot += 5;
					if(selectedPart->xrot>90) selectedPart->xrot = 90;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}
			}
			break;
			case osgGA::GUIEventAdapter::KEY_Down:
			{
				osg::ref_ptr<BodyPart> selectedPart = dynamic_cast<BodyPart*>(rotationjoint->getChild(0));
				osg::Matrix matrix = rotationjoint->getMatrix();
				std::string joint = rotationjoint->getName();

				if ( ea.getModKeyMask()&osgGA::GUIEventAdapter::MODKEY_SHIFT )
				{
					if(joint == "Rhip" || joint == "Lhip")
					{
						selectedPart->zrot -= 5;
					if(selectedPart->zrot<0) selectedPart->zrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::Z_AXIS));

					rotationjoint->setMatrix(matrix);
					}
				}

				else if(joint == "Rknee" || joint == "Lknee")
				{
					selectedPart->xrot -= 5;
					if(selectedPart->xrot<0) selectedPart->xrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Relbow" || joint == "Lelbow")
				{
					selectedPart->xrot -= 5;
					if(selectedPart->xrot<0) selectedPart->xrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Rhip" || joint == "Lhip")
				{
					selectedPart->xrot -= 5;
					if(selectedPart->xrot<0) selectedPart->xrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				
				else if(joint == "Rshoulder" || joint == "Lshoulder")
				{
					selectedPart->xrot -= 5;
					if(selectedPart->xrot<0) selectedPart->xrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::X_AXIS));

					rotationjoint->setMatrix(matrix);
				}
			}
			break;

			case osgGA::GUIEventAdapter::KEY_Left:
			{
				osg::ref_ptr<BodyPart> selectedPart = dynamic_cast<BodyPart*>(rotationjoint->getChild(0));
				osg::Matrix matrix = rotationjoint->getMatrix();
				std::string joint = rotationjoint->getName();

				if(joint == "Rhip")
				{
					selectedPart->yrot -= 5;
					if(selectedPart->yrot<0) selectedPart->yrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				else if(joint == "Lhip")
				{
					selectedPart->yrot += 5;
					if(selectedPart->yrot>45) selectedPart->yrot = 45;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Rshoulder")
				{
					selectedPart->yrot -= 5;
					if(selectedPart->yrot<0) selectedPart->yrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Lshoulder")
				{
					selectedPart->yrot += 5;
					if(selectedPart->yrot>45) selectedPart->yrot = 45;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}
			}
			break;
			case osgGA::GUIEventAdapter::KEY_Right:
			{
				osg::ref_ptr<BodyPart> selectedPart = dynamic_cast<BodyPart*>(rotationjoint->getChild(0));
				osg::Matrix matrix = rotationjoint->getMatrix();
				std::string joint = rotationjoint->getName();

				if(joint == "Rhip")
				{
					selectedPart->yrot += 5;
					if(selectedPart->yrot>45) selectedPart->yrot = 45;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				else if(joint == "Lhip")
				{
					selectedPart->yrot -= 5;
					if(selectedPart->yrot<0) selectedPart->yrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}

				else if(joint == "Rshoulder")
				{
					selectedPart->yrot += 5;
					if(selectedPart->yrot>45) selectedPart->yrot = 45;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}
				else if(joint == "Lshoulder")
				{
					selectedPart->yrot -= 5;
					if(selectedPart->yrot<0) selectedPart->yrot = 0;
					else
						matrix.preMult( osg::Matrix::rotate(osg::DegreesToRadians(-5.0), osg::Y_AXIS));

					rotationjoint->setMatrix(matrix);
				}
			}
			break;

			default: break;
		}
		break;
		default:
		break;
	}
	return false;
}