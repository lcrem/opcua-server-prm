
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
    on 2020-02-24T16:14:58.116Z
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





using namespace std;

	// HEADERS OF VALIDATOR


bool validateMotor (Device::DMotor * object);


	// BODIES OF VALIDATOR

bool
validateMotor (Device::DMotor * object)
{

  return true;
}


	// ROOT VALIDATOR


bool
validateRootHasMotor (Device::DRoot * object)
{


  size_t size = object->motors ().size ();
  (void) size;			/* prevent unused variable warning if bounds are not given in design file */


for (Device::DMotor * child:object->motors ())
    {
      validateMotor (child);
    }

  return true;
}


bool
validateRoot (Device::DRoot * root)
{

  validateRootHasMotor (root);

  return true;			/* it is assumed that improper config would throw */
}





bool
validateDeviceTree ()
{
  Device::DRoot * deviceRoot = Device::DRoot::getInstance ();
  return validateRoot (deviceRoot);

}
