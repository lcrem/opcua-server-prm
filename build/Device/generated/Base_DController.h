
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
    on 2020-03-05T13:26:50.747Z
 */



#ifndef __Base_DController__H__
#define __Base_DController__H__

#include <vector>
#include <string>
#include <list>
#include <boost/thread/mutex.hpp>


#include <DRoot.h>

#include <opcua_platformdefs.h>

		/* forward decl for AddressSpace */
namespace AddressSpace
{
  class ASController;
}

	/* forward decl for Configuration */
namespace Configuration
{
  class Controller;
}

		/* forward decl for Parent */

#include <DRoot.h>


namespace Device
{


  typedef DRoot Parent_DController;



  class DController;
  /* forward declarations (comes from design.class.hasObjects) */

  class DMotor;


    class Base_DController
  {

  public:
    /* Constructor */
    explicit Base_DController (const Configuration::Controller & config,
			       Parent_DController * parent);

  private:
    /* No copy constructors or assignment operators */
      Base_DController (const Base_DController & other);
      Base_DController & operator= (const Base_DController & other);

  public:

    /* sample dtr */
      virtual ~ Base_DController ();

    Parent_DController *getParent () const
    {
      return m_parent;
    }

    /* add/remove for handling device structure */

    void add (DMotor *);
    const std::vector < DMotor * >&motors () const
    {
      return m_Motors;
    }
    // This function is generated because the hasObjects links to exactly 1 object


    /* to safely quit */
    unsigned int unlinkAllChildren ();


    void linkAddressSpace (AddressSpace::ASController * as,
			   const std::string & stringAddress);
      AddressSpace::ASController * getAddressSpaceLink () const;


    /* find methods for children */


    /* getters for values which are keys */


    /* mutex operations */


    /* variable-wise locks */


    /* query address-space for full name (mostly for debug purposes) */
      std::string getFullName () const
    {
      return m_stringAddress;
    };

    static std::list < DController * >s_orphanedObjects;
    static void registerOrphanedObject (DController * object)
    {
      s_orphanedObjects.push_back (object);
    }
    static std::list < DController * >&orphanedObjects ()
    {
      return s_orphanedObjects;
    }

  private:

    Parent_DController * m_parent;

    AddressSpace::ASController * m_addressSpaceLink;


    std::string m_stringAddress;

    std::vector < DMotor * >m_Motors;

    /* if any of our cachevariables has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* if any of our config entries has isKey=true then we shall keep its copy here for find functions  (it is const, either way) */


    /* object-wise lock */


    /* variable-wise locks */





  };





}

#endif // include guard
