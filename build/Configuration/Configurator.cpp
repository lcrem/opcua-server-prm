
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
    
    This file was completely generated by Quasar (additional info: using transform designToConfigurator.xslt) 
    on 2020-02-20T09:14:09.676Z
 */



#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/dom/DOMElement.hpp>

#include <ASUtils.h>
#include <ASInformationModel.h>
#include <ASNodeQueries.h>

#include <DRoot.h>

#include <Configurator.h>
#include <Configuration.hxx>

#include <CalculatedVariablesEngine.h>

#include <meta.h>

#include <LogIt.h>

#include <Utils.h>

using namespace CalculatedVariables;





#include <ASMotor.h>

#include <DMotor.h>
Device::DMotor *
configureMotor (const Configuration::Motor & config,
		AddressSpace::ASNodeManager * nm,
		UaNodeId parentNodeId, Device::Parent_DMotor * parentDevice);


	//! Called to create every single instance of Motor 
Device::DMotor *
configureMotor (const Configuration::Motor & config,
		AddressSpace::ASNodeManager * nm,
		UaNodeId parentNodeId, Device::Parent_DMotor * parentDevice)
{
  AddressSpace::ASMotor * asItem =
    new AddressSpace::ASMotor (parentNodeId,
			       nm->
			       getTypeNodeId (AddressSpace::
					      ASInformationModel::AS_TYPE_MOTOR),
			       nm, config);


  Device::DMotor * dItem = new Device::DMotor (config, parentDevice);
  asItem->linkDevice (dItem);
  dItem->linkAddressSpace (asItem, asItem->nodeId ().toString ().toUtf8 ());


  xercesc::DOMNodeList * childrenNodes = config._node ()->getChildNodes ();
  for (size_t i = 0; i < childrenNodes->getLength (); ++i)
    {
      xercesc::DOMElement * element =
	dynamic_cast < xercesc::DOMElement * >(childrenNodes->item (i));
      if (!element)
	continue;		// it wasnt an element anyway
      // Note for the code below: the internal representation of strings in Xerces is UTF-16 so we should transcode 
      char *transcodedTagName =
	xercesc::XMLString::transcode (element->getTagName ());
      const std::string tagName (transcodedTagName);
      xercesc::XMLString::release (&transcodedTagName);

      if (tagName == "StandardMetaData"
	  || tagName == "CalculatedVariableGenericFormula")
	continue;



      if (tagName == "CalculatedVariable")
	{
	  auto it = std::find_if (config.CalculatedVariable ().begin (),
				  config.CalculatedVariable ().end (),
				  [element] (const Configuration::
					     CalculatedVariable & x) {
				  return x._node () == element;}
	  );
	  Engine::instantiateCalculatedVariable (nm, asItem->nodeId (), *it);
	  continue;
	}

      throw_runtime_error_with_origin
	("No handler found for object - bug of new Configurator? Call Piotr.  The tag in question is:"
	 + tagName);
    }

  return dItem;


}





bool
runConfigurationDecoration (Configuration::Configuration & theConfiguration,
			    ConfigXmlDecoratorFunction &
			    configXmlDecoratorFunction)
{
  if (!configXmlDecoratorFunction)
    return true;

  if (configXmlDecoratorFunction (theConfiguration))
    {
      return true;
    }
  else
    {
      std::
	cout <<
	"Error: device specific configuration decoration failed, check logs for details"
	<< std::endl;
    }
  return false;
}




bool
configure (std::string fileName, AddressSpace::ASNodeManager * nm,
	   ConfigXmlDecoratorFunction configXmlDecoratorFunction)
{

  std::unique_ptr < Configuration::Configuration > theConfiguration;

  try
  {
    theConfiguration =
      Configuration::configuration (fileName,::xml_schema::flags::keep_dom);
  }
  catch (xsd::cxx::tree::parsing < char >&exception)
  {
    LOG (Log::
	 ERR) <<
      "Configuration: Failed when trying to open the configuration, with general error message: "
      << exception.what ();
  for (const xsd::cxx::tree::error < char >&error:exception.
	 diagnostics ())
      {
	LOG (Log::ERR) << "Configuration: Problem at " << error.
	  id () << ":" << error.line () << ": " << error.message ();
      }
    throw std::
      runtime_error
      ("Configuration: failed to load configuration. The exact problem description should have been logged.");
  }

  CalculatedVariables::Engine::loadGenericFormulas (theConfiguration->
						    CalculatedVariableGenericFormula
						    ());



  UaNodeId rootNode = UaNodeId (OpcUaId_ObjectsFolder, 0);
  Device::DRoot * deviceRoot = Device::DRoot::getInstance ();
  (void) deviceRoot;		// silence-out the warning from unused variable

  configureMeta (*theConfiguration.get (), nm, rootNode);
  if (!runConfigurationDecoration
      (*theConfiguration, configXmlDecoratorFunction))
    return false;

  const Configuration::Configuration & config = *theConfiguration;


  xercesc::DOMNodeList * childrenNodes = config._node ()->getChildNodes ();
  for (size_t i = 0; i < childrenNodes->getLength (); ++i)
    {
      xercesc::DOMElement * element =
	dynamic_cast < xercesc::DOMElement * >(childrenNodes->item (i));
      if (!element)
	continue;		// it wasnt an element anyway
      // Note for the code below: the internal representation of strings in Xerces is UTF-16 so we should transcode 
      char *transcodedTagName =
	xercesc::XMLString::transcode (element->getTagName ());
      const std::string tagName (transcodedTagName);
      xercesc::XMLString::release (&transcodedTagName);

      if (tagName == "StandardMetaData"
	  || tagName == "CalculatedVariableGenericFormula")
	continue;



      if (tagName == "Motor")
	{
	  auto it = std::find_if (config.Motor ().begin (),
				  config.Motor ().end (),
				  [element] (const Configuration::
					     Motor & x) { return x._node () ==
				  element;
				  }
	  );


	  Device::DMotor * newObject =
	    configureMotor (*it, nm, rootNode, deviceRoot);

	  deviceRoot->add (newObject);


	  continue;
	}





      if (tagName == "CalculatedVariable")
	{
	  auto it = std::find_if (config.CalculatedVariable ().begin (),
				  config.CalculatedVariable ().end (),
				  [element] (const Configuration::
					     CalculatedVariable & x) {
				  return x._node () == element;}
	  );
	  Engine::instantiateCalculatedVariable (nm, rootNode, *it);
	  continue;
	}

      throw_runtime_error_with_origin
	("No handler found for object - bug of new Configurator? Call Piotr.  The tag in question is:"
	 + tagName);
    }



  return true;
}




void
unlinkAllDevices (AddressSpace::ASNodeManager * nm)
{
  unsigned int totalObjectsNumber = 0;

  {
    std::vector < AddressSpace::ASMotor * >objects;
    std::string pattern (".*");
    AddressSpace::findAllObjectsByPatternInNodeManager <
      AddressSpace::ASMotor > (nm, pattern, objects);
    totalObjectsNumber += objects.size ();
  for (AddressSpace::ASMotor * a:objects)
      {
	a->unlinkDevice ();
      }
  }

  LOG (Log::
       INF) << "Total number of unlinked objects: " << totalObjectsNumber;
}
