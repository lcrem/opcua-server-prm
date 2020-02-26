
/*  © Copyright CERN, 2015. All rights not expressly granted are reserved.
        
    The stub of this file was generated by Quasar (additional info: using transform designToDeviceHeader.xslt) 
    on 2020-02-26T11:25:20.565Z
    
    Quasar is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public Licence as published by
    the Free Software Foundation, either version 3 of the Licence.
    Quasar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public Licence for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Quasar.  If not, see <http://www.gnu.org/licenses/>.
    
    
    
 */





#ifndef __DAirFlowProbe__H__
#define __DAirFlowProbe__H__

#include <vector>
#include <boost/thread/mutex.hpp>

#include <statuscode.h>
#include <uadatetime.h>
#include <session.h>


#include <DRoot.h>
#include <Configuration.hxx>

#include <Base_DAirFlowProbe.h>


namespace Device
{




  class DAirFlowProbe:public Base_DAirFlowProbe
  {

  public:
    /* sample constructor */
    explicit DAirFlowProbe (const Configuration::AirFlowProbe & config,
			    Parent_DAirFlowProbe * parent);
    /* sample dtr */
     ~DAirFlowProbe ();




    /* delegators for
       cachevariables and sourcevariables */


    /* delegators for methods */


  private:
    /* Delete copy constructor and assignment operator */
      DAirFlowProbe (const DAirFlowProbe &);
      DAirFlowProbe & operator= (const DAirFlowProbe & other);

    // ----------------------------------------------------------------------- *
    // -     CUSTOM CODE STARTS BELOW THIS COMMENT.                            *
    // -     Don't change this comment, otherwise merge tool may be troubled.  *
    // ----------------------------------------------------------------------- *

  public:

  private:


  };





}

#endif // include guard
