
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
    
    This file was completely generated by Quasar (additional info: using transform designToInformationModelHeader.xslt) 
    on 2020-02-24T16:14:48.685Z
 */



#ifndef __ASINFORMATIONMODEL__H__
#define __ASINFORMATIONMODEL__H__

#include <ASNodeManager.h>

namespace AddressSpace
{


  class ASInformationModel
  {
  public:

    enum
    {
      AS_TYPE_STANDARDMETADATA = 1000,
      AS_TYPE_LOG,
      AS_TYPE_GENERALLOGLEVEL,
      AS_TYPE_SOURCEVARIABLESTHREADPOOL,
      AS_TYPE_COMPONENTLOGLEVEL,
      AS_TYPE_COMPONENTLOGLEVELS,
      AS_TYPE_QUASAR,
      AS_TYPE_SERVER,
      AS_TYPE_BUILDINFORMATION,
      AS_TYPE_MOTOR
    };

    static void createNodesOfTypes (ASNodeManager * nm);
  };
}

#endif				// __ASINFORMATIONMODEL__H__
