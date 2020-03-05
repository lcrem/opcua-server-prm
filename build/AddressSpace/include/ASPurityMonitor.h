
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
    on 2020-03-04T17:55:06.015Z
 */



#ifndef __ASPurityMonitor__H__
#define __ASPurityMonitor__H__


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
  class DPurityMonitor;
}


namespace AddressSpace
{
  //! Fully auto-generated class to represent PurityMonitor in the OPC UA AddressSpace
  class ASPurityMonitor:public OpcUa::BaseObjectType
  {
    UA_DISABLE_COPY (ASPurityMonitor);
  public:



    //! Constructor. Used in Configurator.cpp. You NEVER use it directly.
    ASPurityMonitor (UaNodeId parentNodeId,
		     const UaNodeId & typeNodeId,
		     ASNodeManager * nm,
		     const Configuration::PurityMonitor & config);



    /*dtor */
     ~ASPurityMonitor ();



    /* setters and getters for variables */



    UaStatus getRunningConfiguration (OpcUa_Double &) const;
    UaStatus setRunningConfiguration (const OpcUa_Double value,
				      OpcUa_StatusCode statusCode,
				      const UaDateTime & srcTime =
				      UaDateTime::now ());



    /* short getter (possible because nullPolicy=nullForbidden) */
    OpcUa_Double getRunningConfiguration () const;








    /* delegators for cachevariables  */

    //! This function will be called when OPC UA write request comes. Never directly call it.

/* NOTE: This function is not intended to be used by human being. */
      UaStatus
      writeRunningConfiguration (Session * pSession,
				 const UaDataValue & dataValue,
				 OpcUa_Boolean checkAccessLevel = OpcUa_True);





    /* Device Logic setter (if requested) */

    void linkDevice (Device::DPurityMonitor * deviceLink);
    void unlinkDevice ();
      Device::DPurityMonitor * getDeviceLink () const
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
      ASDelegatingVariable < ASPurityMonitor > *m_runningConfiguration;


    /* Methods */


    /* Device Logic link (if requested) */

      Device::DPurityMonitor * m_deviceLink;




  };

}



#endif				// include guard
