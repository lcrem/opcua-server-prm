
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
    
    This file was completely generated by Quasar (additional info: using transform designToDeviceBaseHeader.xslt) 
    on 2020-02-27T14:08:37.797Z
 */



#ifndef __Base_DAirFlowProbe__H__
#define __Base_DAirFlowProbe__H__

#include <vector>
#include <string>
#include <list>
#include <boost/thread/mutex.hpp>


#include <DRoot.h>

#include <opcua_platformdefs.h>

		/* forward decl for AddressSpace */
namespace AddressSpace
{
  class ASAirFlowProbe;
}

	/* forward decl for Configuration */
namespace Configuration
{
  class AirFlowProbe;
}

		/* forward decl for Parent */

#include <DMotor.h>


namespace Device
{


  typedef DMotor Parent_DAirFlowProbe;



  class DAirFlowProbe;
  /* forward declarations (comes from design.class.hasObjects) */


    class Base_DAirFlowProbe
  {

  public:
    /* Constructor */
    explicit Base_DAirFlowProbe (const Configuration::AirFlowProbe & config,
				 Parent_DAirFlowProbe * parent);

  private:
    /* No copy constructors or assignment operators */
      Base_DAirFlowProbe (const Base_DAirFlowProbe & other);
      Base_DAirFlowProbe & operator= (const Base_DAirFlowProbe & other);

  public:

    /* sample dtr */
      virtual ~ Base_DAirFlowProbe ();

    Parent_DAirFlowProbe *getParent () const
    {
      return m_parent;
    }

    /* add/remove for handling device structure */


    /* to safely quit */
    unsigned int unlinkAllChildren ();


    void linkAddressSpace (AddressSpace::ASAirFlowProbe * as,
			   const std::string & stringAddress);
      AddressSpace::ASAirFlowProbe * getAddressSpaceLink () const;


    /* find methods for children */


    /* getters for values which are keys */


    /* mutex operations */


    /* variable-wise locks */


    /* query address-space for full name (mostly for debug purposes) */
      std::string getFullName () const
    {
      return m_stringAddress;
    };

    static std::list < DAirFlowProbe * >s_orphanedObjects;
    static void registerOrphanedObject (DAirFlowProbe * object)
    {
      s_orphanedObjects.push_back (object);
    }
    static std::list < DAirFlowProbe * >&orphanedObjects ()
    {
      return s_orphanedObjects;
    }

  private:

    Parent_DAirFlowProbe * m_parent;

    AddressSpace::ASAirFlowProbe * m_addressSpaceLink;


    std::string m_stringAddress;

    /* if any of our cachevariables has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* if any of our config entries has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* object-wise lock */


    /* variable-wise locks */





  };





}

#endif // include guard
