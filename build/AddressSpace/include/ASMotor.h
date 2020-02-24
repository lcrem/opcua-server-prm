
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
    on 2020-02-24T16:14:48.786Z
 */



#ifndef __ASMotor__H__
#define __ASMotor__H__


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
  class DMotor;
}


namespace AddressSpace
{
  //! Fully auto-generated class to represent Motor in the OPC UA AddressSpace
  class ASMotor:public OpcUa::BaseObjectType
  {
    UA_DISABLE_COPY (ASMotor);
  public:



    //! Constructor. Used in Configurator.cpp. You NEVER use it directly.
    ASMotor (UaNodeId parentNodeId,
	     const UaNodeId & typeNodeId,
	     ASNodeManager * nm, const Configuration::Motor & config);



    /*dtor */
     ~ASMotor ();



    /* setters and getters for variables */



    UaStatus getRotationalSpeed (OpcUa_Double &) const;
    UaStatus setRotationalSpeed (const OpcUa_Double value,
				 OpcUa_StatusCode statusCode,
				 const UaDateTime & srcTime =
				 UaDateTime::now ());



    /* null-setter (possible because nullPolicy=nullAllowed) */
    UaStatus setNullRotationalSpeed (OpcUa_StatusCode statusCode,
				     const UaDateTime & srcTime =
				     UaDateTime::now ());



    UaStatus getRotationalSpeedSetPoint (OpcUa_Double &) const;
    UaStatus setRotationalSpeedSetPoint (const OpcUa_Double value,
					 OpcUa_StatusCode statusCode,
					 const UaDateTime & srcTime =
					 UaDateTime::now ());



    /* null-setter (possible because nullPolicy=nullAllowed) */
    UaStatus setNullRotationalSpeedSetPoint (OpcUa_StatusCode statusCode,
					     const UaDateTime & srcTime =
					     UaDateTime::now ());








    /* delegators for cachevariables  */

    //! This function will be called when OPC UA write request comes. Never directly call it.

/* NOTE: This function is not intended to be used by human being. */
      UaStatus
      writeRotationalSpeedSetPoint (Session * pSession,
				    const UaDataValue & dataValue,
				    OpcUa_Boolean checkAccessLevel =
				    OpcUa_True);





    /* Device Logic setter (if requested) */

    void linkDevice (Device::DMotor * deviceLink);
    void unlinkDevice ();
      Device::DMotor * getDeviceLink () const
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
      ChangeNotifyingVariable * m_rotationalSpeed;
      ChangeNotifyingVariable * m_rotationalSpeedSetPoint;


    /* Methods */


    /* Device Logic link (if requested) */

      Device::DMotor * m_deviceLink;




  };

}



#endif				// include guard
