
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
    Authors(from Quasar team): Piotr Nikiel
        
    This file is part of Quasar.
   
    Quasar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public Licence as published by
    the Free Software Foundation, either version 3 of the Licence.
    Quasar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public Licence for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Quasar.  If not, see <http://www.gnu.org/licenses/>.
    
    This file was completely generated by Quasar (additional info: using transform designToConfigValidator.xslt) 
    on 2020-03-05T13:27:10.751Z
 */


#include <iostream>

#include <ASUtils.h>
#include <ASInformationModel.h>

#include <Utils.h>

#include <DRoot.h>

#include <Configurator.h>
#include <Configuration.hxx>






#include "ASMotor.h"

#include "DMotor.h"

#include "ASController.h"

#include "DController.h"

#include "ASTemperatureProbe.h"

#include "DTemperatureProbe.h"

#include "ASAirFlowProbe.h"

#include "DAirFlowProbe.h"

#include "ASPurityMonitor.h"

#include "DPurityMonitor.h"





using namespace std;

	// HEADERS OF VALIDATOR


bool validateMotorHasTemperatureProbe (Device::DMotor * object);

bool validateMotorHasAirFlowProbe (Device::DMotor * object);

bool validateMotor (Device::DMotor * object);

bool validateControllerHasMotor (Device::DController * object);

bool validateController (Device::DController * object);

bool validateTemperatureProbe (Device::DTemperatureProbe * object);

bool validateAirFlowProbe (Device::DAirFlowProbe * object);

bool validatePurityMonitor (Device::DPurityMonitor * object);


	// BODIES OF VALIDATOR

bool
validateMotorHasTemperatureProbe (Device::DMotor * object)
{


  size_t size = object->temperatureprobes ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */


for (Device::DTemperatureProbe * child:object->temperatureprobes ())
    {
      validateTemperatureProbe (child);
    }

  return true;
}

bool
validateMotorHasAirFlowProbe (Device::DMotor * object)
{


  size_t size = object->airflowprobes ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */

  if (size < 0)
    {
      throw std::
	runtime_error
	("Configuration error: Motor should have no less than 0 AirFlowProbe, but it has "
	 + Utils::toString (size) + " (for " + object->getFullName () + ")");
    }

  if (size > 1)
    {
      throw std::
	runtime_error
	("Configuration error: Motor should have no more than 1 AirFlowProbe, but it has "
	 + Utils::toString (size) + " (for " + object->getFullName () + ")");
    }


for (Device::DAirFlowProbe * child:object->airflowprobes ())
    {
      validateAirFlowProbe (child);
    }

  return true;
}

bool
validateMotor (Device::DMotor * object)
{

  validateMotorHasTemperatureProbe (object);

  validateMotorHasAirFlowProbe (object);

  return true;
}

bool
validateControllerHasMotor (Device::DController * object)
{


  size_t size = object->motors ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */

  if (size < 0)
    {
      throw std::
	runtime_error
	("Configuration error: Controller should have no less than 0 Motor, but it has "
	 + Utils::toString (size) + " (for " + object->getFullName () + ")");
    }

  if (size > 4)
    {
      throw std::
	runtime_error
	("Configuration error: Controller should have no more than 4 Motor, but it has "
	 + Utils::toString (size) + " (for " + object->getFullName () + ")");
    }


for (Device::DMotor * child:object->motors ())
    {
      validateMotor (child);
    }

  return true;
}

bool
validateController (Device::DController * object)
{

  validateControllerHasMotor (object);

  return true;
}

bool
validateTemperatureProbe (Device::DTemperatureProbe * object)
{

  return true;
}

bool
validateAirFlowProbe (Device::DAirFlowProbe * object)
{

  return true;
}

bool
validatePurityMonitor (Device::DPurityMonitor * object)
{

  return true;
}


	// ROOT VALIDATOR


bool
validateRootHasController (Device::DRoot * object)
{


  size_t size = object->controllers ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */


for (Device::DController * child:object->controllers ())
    {
      validateController (child);
    }

  return true;
}

bool
validateRootHasPurityMonitor (Device::DRoot * object)
{


  size_t size = object->puritymonitors ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */


for (Device::DPurityMonitor * child:object->puritymonitors ())
    {
      validatePurityMonitor (child);
    }

  return true;
}


bool
validateRoot (Device::DRoot * root)
{

  validateRootHasController (root);

  validateRootHasPurityMonitor (root);

  return true;			/* it is assumed that improper config would throw */
}





bool
validateDeviceTree ()
{
  Device::DRoot * deviceRoot = Device::DRoot::getInstance ();
  return validateRoot (deviceRoot);

}
