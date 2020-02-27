
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
    
    This file was completely generated by Quasar (additional info: using transform designToRootBody.xslt) 
    on 2020-02-27T13:56:02.353Z
 */


#include <iostream>
#include <DRoot.h>
#include <ASUtils.h>




#include <DMotor.h>

#include <DController.h>

#include <DTemperatureProbe.h>

#include <DAirFlowProbe.h>


namespace Device
{

  DRoot::DRoot ()
  {
    if (m_instance != 0)
      abort ();			/* Logic error inside program. DRoot can be instantiated just once */
    m_instance = this;
  }

  DRoot::~DRoot ()
  {

    for (auto it = m_childrenController.begin ();
	 it != m_childrenController.end (); it++)
      delete (*it);
    m_childrenController.clear ();

    {
      auto objects = Base_DMotor::orphanedObjects ();
    for (DMotor * object:objects)
	{
	  delete object;

	}
      objects.clear ();

    }

    {
      auto objects = Base_DController::orphanedObjects ();
    for (DController * object:objects)
	{
	  delete object;

	}
      objects.clear ();

    }

    {
      auto objects = Base_DTemperatureProbe::orphanedObjects ();
    for (DTemperatureProbe * object:objects)
	{
	  delete object;

	}
      objects.clear ();

    }

    {
      auto objects = Base_DAirFlowProbe::orphanedObjects ();
    for (DAirFlowProbe * object:objects)
	{
	  delete object;

	}
      objects.clear ();

    }

  }

  DRoot *DRoot::getInstance ()
  {
    if (m_instance == 0)
      {
	ABORT_MESSAGE ("DRoot: instance not yet created. ");
      }
    return m_instance;
  }

  void DRoot::unlinkAllChildren () const
  {
    unsigned int objectCounter = 0;

    for (auto it = m_childrenController.begin ();
	 it != m_childrenController.end (); it++)
        objectCounter += (*it)->unlinkAllChildren ();

    {
      auto objects = DMotor::orphanedObjects ();
      for (DMotor * object:objects)
	{
	  objectCounter += object->unlinkAllChildren ();
	}

    }

    {
      auto objects = DController::orphanedObjects ();
    for (DController * object:objects)
	{
	  objectCounter += object->unlinkAllChildren ();
	}

    }

    {
      auto objects = DTemperatureProbe::orphanedObjects ();
    for (DTemperatureProbe * object:objects)
	{
	  objectCounter += object->unlinkAllChildren ();
	}

    }

    {
      auto objects = DAirFlowProbe::orphanedObjects ();
    for (DAirFlowProbe * object:objects)
	{
	  objectCounter += object->unlinkAllChildren ();
	}

    }

    std::
      cout << "DRoot::unlinkAllChildren(): " << objectCounter <<
      " objects unlinked " << std::endl;
  }

  /* find methods for children */


  /* Singleton's instance. */
  DRoot *DRoot::m_instance = 0;



}
