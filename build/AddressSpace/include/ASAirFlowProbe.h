
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
    on 2020-02-27T13:56:11.865Z
 */



#ifndef __ASAirFlowProbe__H__
#define __ASAirFlowProbe__H__


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
  class DAirFlowProbe;
}


namespace AddressSpace
{
  //! Fully auto-generated class to represent AirFlowProbe in the OPC UA AddressSpace
  class ASAirFlowProbe:public OpcUa::BaseObjectType
  {
    UA_DISABLE_COPY (ASAirFlowProbe);
  public:



    //! Constructor. Used in Configurator.cpp. You NEVER use it directly.
    ASAirFlowProbe (UaNodeId parentNodeId,
		    const UaNodeId & typeNodeId,
		    ASNodeManager * nm,
		    const Configuration::AirFlowProbe & config);



    /*dtor */
     ~ASAirFlowProbe ();



    /* setters and getters for variables */








    /* delegators for cachevariables  */





    /* Device Logic setter (if requested) */

    void linkDevice (Device::DAirFlowProbe * deviceLink);
    void unlinkDevice ();
      Device::DAirFlowProbe * getDeviceLink () const
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

      Device::DAirFlowProbe * m_deviceLink;




  };

}



#endif				// include guard
