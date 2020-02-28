
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
    
    This file was completely generated by Quasar (additional info: using transform designToClassHeader.xslt) 
    on 2020-02-27T16:16:06.946Z
 */



#ifndef __ASTemperatureProbe__H__
#define __ASTemperatureProbe__H__


#include <opcua_baseobjecttype.h>
#include <opcua_basedatavariabletype.h>

#include <methodhandleuanode.h>
#include <ASDelegatingMethod.h>

#include <Configuration.hxx>

#include <ASNodeManager.h>
#include <ASDelegatingVariable.h>


#include <ASSourceVariable.h>

#include <ChangeNotifyingVariable.h>


		/* forward declaration */
namespace Device
{
  class DTemperatureProbe;
}


namespace AddressSpace
{
  //! Fully auto-generated class to represent TemperatureProbe in the OPC UA AddressSpace
  class ASTemperatureProbe:public OpcUa::BaseObjectType
  {
    UA_DISABLE_COPY (ASTemperatureProbe);
  public:



    //! Constructor. Used in Configurator.cpp. You NEVER use it directly.
    ASTemperatureProbe (UaNodeId parentNodeId,
			const UaNodeId & typeNodeId,
			ASNodeManager * nm,
			const Configuration::TemperatureProbe & config);



    /*dtor */
     ~ASTemperatureProbe ();



    /* setters and getters for variables */








    /* delegators for cachevariables  */





    /* Device Logic setter (if requested) */

    void linkDevice (Device::DTemperatureProbe * deviceLink);
    void unlinkDevice ();
      Device::DTemperatureProbe * getDeviceLink () const
    {
      return m_deviceLink;
    }

    /* OPC UA Type Information provider for this class. */
    virtual UaNodeId typeDefinitionId () const
    {
      return m_typeNodeId;
    }




  private:
      UaNodeId m_typeNodeId;
    /* Variables */


    /* Methods */


    /* Device Logic link (if requested) */

      Device::DTemperatureProbe * m_deviceLink;




  };

}



#endif				// include guard
