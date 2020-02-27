
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
    
    This file was completely generated by Quasar (additional info: using transform designToClassBody.xslt) 
    on 2020-02-27T14:08:45.173Z
 */


#include <iostream>
#include <climits>

#include <boost/lexical_cast.hpp>

#include <ArrayTools.h>
#include <Utils.h>
#include <ChangeNotifyingVariable.h>
#include <CalculatedVariablesEngine.h>

#include <SourceVariables.h>



#include <ASMotor.h>


#include <DMotor.h>


namespace AddressSpace
{



/*ctr*/
  ASMotor::ASMotor (UaNodeId parentNodeId,
		    const UaNodeId & typeNodeId,
		    ASNodeManager * nm,
		    const Configuration::Motor & config):OpcUa::
    BaseObjectType (
			 /*nodeId */
			 nm->makeChildNodeId (parentNodeId,
					      (config.name ()).c_str ()),
    /*name */ (config.name ()).c_str (), nm->getNameSpaceIndex (), nm),
    m_typeNodeId (typeNodeId)
   , m_rotationalSpeed (new
			ChangeNotifyingVariable (nm->
						 makeChildNodeId (this->
								  nodeId (),
								  UaString
								  ("rotationalSpeed")),
						 UaString ("rotationalSpeed"),
						 nm->getNameSpaceIndex (),
						 UaVariant (),
						 OpcUa_AccessLevels_CurrentRead,
						 nm)),
    m_rotationalSpeedSetPoint (new ASDelegatingVariable < ASMotor >
			       (nm->
				makeChildNodeId (this->nodeId (),
						 UaString
						 ("rotationalSpeedSetPoint")),
				UaString ("rotationalSpeedSetPoint"),
				nm->getNameSpaceIndex (), UaVariant (),
				OpcUa_AccessLevels_CurrentReadOrWrite, nm)),
    m_refreshRate (new
		   ChangeNotifyingVariable (nm->
					    makeChildNodeId (this->nodeId (),
							     UaString
							     ("refreshRate")),
					    UaString ("refreshRate"),
					    nm->getNameSpaceIndex (),
					    UaVariant (),
					    OpcUa_AccessLevels_CurrentRead,
					    nm)), m_deviceLink (0)
  {

    UaStatus s;
    UaVariant v;


      s = nm->addNodeAndReference (parentNodeId, this, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	LOG (Log::ERR) << "While addNodeAndReference from " << parentNodeId.
	  toString ().toUtf8 () << " to " << this->nodeId ().toString ().
	  toUtf8 () << " : ";
	ASSERT_GOOD (s);
      }



    v.clear ();

    m_rotationalSpeed->setValue ( /*pSession */ 0, UaDataValue (UaVariant (v),
								OpcUa_BadWaitingForInitialData,
								UaDateTime::
								now (),
								UaDateTime::
								now ()),
				 /*check access level */ OpcUa_False);

    s = nm->addNodeAndReference (this,
				 m_rotationalSpeed, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	std::cout << "While addNodeAndReference from " << this->nodeId ().
	  toString ().toUtf8 () << " to " << m_rotationalSpeed->nodeId ().
	  toString ().toUtf8 () << " : " << std::endl;
	ASSERT_GOOD (s);
      }



    CalculatedVariables::Engine::
      registerVariableForCalculatedVariables (m_rotationalSpeed);

    m_rotationalSpeedSetPoint->setDataType (UaNodeId (OpcUaType_Double, 0));	// assumption: BuiltInTypeId matches numeric address of the type in namespace0

    v.setDouble (0);

    m_rotationalSpeedSetPoint->setValue ( /*pSession */ 0,
					 UaDataValue (UaVariant (v),
						      OpcUa_Good,
						      UaDateTime::now (),
						      UaDateTime::now ()),
					 /*check access level */ OpcUa_False);

    s = nm->addNodeAndReference (this,
				 m_rotationalSpeedSetPoint,
				 OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	std::cout << "While addNodeAndReference from " << this->nodeId ().
	  toString ().toUtf8 () << " to " << m_rotationalSpeedSetPoint->
	  nodeId ().toString ().toUtf8 () << " : " << std::endl;
	ASSERT_GOOD (s);
      }



    m_rotationalSpeedSetPoint->assignHandler (this,
					      &ASMotor::writeRotationalSpeedSetPoint);

    CalculatedVariables::Engine::
      registerVariableForCalculatedVariables (m_rotationalSpeedSetPoint);

    // found scalar signature: can simply load the variant with the scalar
    // fnc:dataTypeToVariantSetter(@dataType)
    v.setFloat (config.refreshRate ());
    m_refreshRate->setValue ( /*pSession */ 0,
			     UaDataValue (UaVariant (v), OpcUa_Good,
					  UaDateTime::now (),
					  UaDateTime::now ()),
			     /*check access level */ OpcUa_False);


    s = nm->addNodeAndReference (this, m_refreshRate, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	std::cout << "While addNodeAndReference from " << this->nodeId ().
	  toString ().toUtf8 () << " to " << m_refreshRate->nodeId ().
	  toString ().toUtf8 () << " : " << std::endl;
	ASSERT_GOOD (s);
      }



    CalculatedVariables::Engine::
      registerVariableForCalculatedVariables (m_refreshRate);


  }





  ASMotor::~ASMotor ()
  {

    if (m_deviceLink != 0)
      {
	LOG (Log::ERR) << "deviceLink not zero!!";
      }

  }




/* generate setters and getters (if requested) */


  UaStatus ASMotor::setRotationalSpeed (const OpcUa_Double value,
					OpcUa_StatusCode statusCode,
					const UaDateTime & srcTime)
  {

    UaVariant v;

    v.setDouble (value);

    return m_rotationalSpeed->setValue (0,
					UaDataValue (v, statusCode, srcTime,
						     UaDateTime::now ()),
					/*check access */ OpcUa_False);

  }


  UaStatus ASMotor::getRotationalSpeed (OpcUa_Double & r) const
  {
    UaVariant v (*(m_rotationalSpeed->value ( /*session */ 0).value ()));
      return v.toDouble (r);
  }

  /* null-setter (possible because nullPolicy='nullAllowed') */
  UaStatus ASMotor::setNullRotationalSpeed (OpcUa_StatusCode statusCode,
					    const UaDateTime & srcTime)
  {
    UaVariant v;

    return m_rotationalSpeed->setValue (0,
					UaDataValue (v, statusCode, srcTime,
						     UaDateTime::now ()),
					/*check access */ OpcUa_False);

  }


  UaStatus ASMotor::setRotationalSpeedSetPoint (const OpcUa_Double value,
						OpcUa_StatusCode statusCode,
						const UaDateTime & srcTime)
  {

    UaVariant v;

    v.setDouble (value);

    return m_rotationalSpeedSetPoint->setValue (0,
						UaDataValue (v, statusCode,
							     srcTime,
							     UaDateTime::
							     now ()),
						/*check access */
						OpcUa_False);

  }


  UaStatus ASMotor::getRotationalSpeedSetPoint (OpcUa_Double & r) const
  {
    UaVariant
      v (*(m_rotationalSpeedSetPoint->value ( /*session */ 0).value ()));
      return v.toDouble (r);
  }

  /* short getter (possible because this variable will never be null) */
  OpcUa_Double ASMotor::getRotationalSpeedSetPoint () const
  {
    UaVariant v (*m_rotationalSpeedSetPoint->value (0).value ());
    OpcUa_Double v_value;
      v.toDouble (v_value);
      return v_value;
  }


  UaStatus ASMotor::setRefreshRate (const OpcUa_Float value,
				    OpcUa_StatusCode statusCode,
				    const UaDateTime & srcTime)
  {

    UaVariant v;

    v.setFloat (value);

    return m_refreshRate->setValue (0,
				    UaDataValue (v, statusCode, srcTime,
						 UaDateTime::now ()),
				    /*check access */ OpcUa_False);

  }


  UaStatus ASMotor::getRefreshRate (OpcUa_Float & r) const
  {
    UaVariant v (*(m_refreshRate->value ( /*session */ 0).value ()));
      return v.toFloat (r);
  }

  /* null-setter (possible because nullPolicy='nullAllowed') */
  UaStatus ASMotor::setNullRefreshRate (OpcUa_StatusCode statusCode,
					const UaDateTime & srcTime)
  {
    UaVariant v;

    return m_refreshRate->setValue (0,
				    UaDataValue (v, statusCode, srcTime,
						 UaDateTime::now ()),
				    /*check access */ OpcUa_False);

  }





/* generate delegates (if requested) */

/* NOTE: This function is not intended to be used by human being. */
  UaStatus
    ASMotor::writeRotationalSpeedSetPoint (Session * pSession,
					   const UaDataValue & dataValue,
					   OpcUa_Boolean checkAccessLevel)
  {


    /* ensure that data type passed by OPC UA client matches specification */
    UaVariant v (*dataValue.value ());
    if (v.type () != OpcUaType_Double)
      {

	return OpcUa_BadDataEncodingInvalid;

	if (v.type () != OpcUaType_Null)
	  return OpcUa_BadDataEncodingInvalid;	// now we know it is neither the intended datatype nor NULL

      }

    // scalar
    OpcUa_Double v_value;
    v.toDouble (v_value);


    /* if device logic type specified, then generate calling functions */

    if (m_deviceLink != 0)
      {
	return m_deviceLink->writeRotationalSpeedSetPoint (v_value);
      }
    else
      return OpcUa_Bad;


  }





/* generate device logic link */


  void ASMotor::linkDevice (Device::DMotor * deviceLink)
  {
    if (m_deviceLink != 0)
      {
	/* This is an error -- device can be linked at most in the object's lifetime. */
	//TODO After error handling is discussed, abort in smarter way
	abort ();

      }
    else
      m_deviceLink = deviceLink;
  }


  void ASMotor::unlinkDevice ()
  {
    m_deviceLink = 0;
  }


}



#include <ASController.h>


#include <DController.h>


namespace AddressSpace
{



/*ctr*/
  ASController::ASController (UaNodeId parentNodeId,
			      const UaNodeId & typeNodeId,
			      ASNodeManager * nm,
			      const Configuration::
			      Controller & config):OpcUa::BaseObjectType (
									       /*nodeId */
									       nm->
									       makeChildNodeId
									       (parentNodeId,
										(config.
										 name
										 ()).
										c_str
										()),
    /*name */ (config.name ()).c_str (), nm->getNameSpaceIndex (), nm),
    m_typeNodeId (typeNodeId)
   , m_deviceLink (0)
  {

    UaStatus s;
    UaVariant v;


      s = nm->addNodeAndReference (parentNodeId, this, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	LOG (Log::ERR) << "While addNodeAndReference from " << parentNodeId.
	  toString ().toUtf8 () << " to " << this->nodeId ().toString ().
	  toUtf8 () << " : ";
	ASSERT_GOOD (s);
      }




  }





  ASController::~ASController ()
  {

    if (m_deviceLink != 0)
      {
	LOG (Log::ERR) << "deviceLink not zero!!";
      }

  }




/* generate setters and getters (if requested) */





/* generate delegates (if requested) */





/* generate device logic link */


  void ASController::linkDevice (Device::DController * deviceLink)
  {
    if (m_deviceLink != 0)
      {
	/* This is an error -- device can be linked at most in the object's lifetime. */
	//TODO After error handling is discussed, abort in smarter way
	abort ();

      }
    else
      m_deviceLink = deviceLink;
  }


  void ASController::unlinkDevice ()
  {
    m_deviceLink = 0;
  }


}



#include <ASTemperatureProbe.h>


#include <DTemperatureProbe.h>


namespace AddressSpace
{



/*ctr*/
  ASTemperatureProbe::ASTemperatureProbe (UaNodeId parentNodeId,
					  const UaNodeId & typeNodeId,
					  ASNodeManager * nm,
					  const Configuration::
					  TemperatureProbe & config):OpcUa::
    BaseObjectType (
			  /*nodeId */
			  nm->makeChildNodeId (parentNodeId,
					       (config.name ()).c_str ()),
    /*name */ (config.name ()).c_str (), nm->getNameSpaceIndex (), nm),
    m_typeNodeId (typeNodeId)
   , m_deviceLink (0)
  {

    UaStatus s;
    UaVariant v;


      s = nm->addNodeAndReference (parentNodeId, this, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	LOG (Log::ERR) << "While addNodeAndReference from " << parentNodeId.
	  toString ().toUtf8 () << " to " << this->nodeId ().toString ().
	  toUtf8 () << " : ";
	ASSERT_GOOD (s);
      }




  }





  ASTemperatureProbe::~ASTemperatureProbe ()
  {

    if (m_deviceLink != 0)
      {
	LOG (Log::ERR) << "deviceLink not zero!!";
      }

  }




/* generate setters and getters (if requested) */





/* generate delegates (if requested) */





/* generate device logic link */


  void ASTemperatureProbe::linkDevice (Device::DTemperatureProbe * deviceLink)
  {
    if (m_deviceLink != 0)
      {
	/* This is an error -- device can be linked at most in the object's lifetime. */
	//TODO After error handling is discussed, abort in smarter way
	abort ();

      }
    else
      m_deviceLink = deviceLink;
  }


  void ASTemperatureProbe::unlinkDevice ()
  {
    m_deviceLink = 0;
  }


}



#include <ASAirFlowProbe.h>


#include <DAirFlowProbe.h>


namespace AddressSpace
{



/*ctr*/
  ASAirFlowProbe::ASAirFlowProbe (UaNodeId parentNodeId,
				  const UaNodeId & typeNodeId,
				  ASNodeManager * nm,
				  const Configuration::
				  AirFlowProbe & config):OpcUa::
    BaseObjectType (
			  /*nodeId */
			  nm->makeChildNodeId (parentNodeId,
					       (config.name ()).c_str ()),
    /*name */ (config.name ()).c_str (), nm->getNameSpaceIndex (), nm),
    m_typeNodeId (typeNodeId)
   , m_deviceLink (0)
  {

    UaStatus s;
    UaVariant v;


      s = nm->addNodeAndReference (parentNodeId, this, OpcUaId_HasComponent);
    if (!s.isGood ())
      {
	LOG (Log::ERR) << "While addNodeAndReference from " << parentNodeId.
	  toString ().toUtf8 () << " to " << this->nodeId ().toString ().
	  toUtf8 () << " : ";
	ASSERT_GOOD (s);
      }




  }





  ASAirFlowProbe::~ASAirFlowProbe ()
  {

    if (m_deviceLink != 0)
      {
	LOG (Log::ERR) << "deviceLink not zero!!";
      }

  }




/* generate setters and getters (if requested) */





/* generate delegates (if requested) */





/* generate device logic link */


  void ASAirFlowProbe::linkDevice (Device::DAirFlowProbe * deviceLink)
  {
    if (m_deviceLink != 0)
      {
	/* This is an error -- device can be linked at most in the object's lifetime. */
	//TODO After error handling is discussed, abort in smarter way
	abort ();

      }
    else
      m_deviceLink = deviceLink;
  }


  void ASAirFlowProbe::unlinkDevice ()
  {
    m_deviceLink = 0;
  }


}
