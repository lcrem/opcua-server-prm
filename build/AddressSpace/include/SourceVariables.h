
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
    
    This file was completely generated by Quasar (additional info: using transform designToSourceVariablesHeader.xslt) 
    on 2020-03-05T13:26:59.816Z
 */


#ifndef __IOMANAGERS_H__
#define __IOMANAGERS_H__

#include <QuasarThreadPool.h>
namespace AddressSpace
{
  void SourceVariables_initSourceVariablesThreadPool (unsigned int minThreads
						      =
						      0,
						      unsigned int maxThreads
						      =
						      10,
						      unsigned int maxJobs =
						      1000);
  void SourceVariables_destroySourceVariablesThreadPool ();
    Quasar::ThreadPool * SourceVariables_getThreadPool ();
}

#ifndef BACKEND_OPEN62541

#include <iomanager.h>
#include <uathreadpool.h>
#include <uabasenodes.h>


namespace AddressSpace
{


  enum ASSourceVariableJobId
  {
    ASSOURCEVARIABLE_NOTHING
  };


  UaStatus SourceVariables_spawnIoJobRead (ASSourceVariableJobId jobId,
					   IOManagerCallback * callback,
					   OpcUa_UInt32 hTransaction,
					   OpcUa_UInt32 callbackHandle,
					   const UaNode * parentNode);

  UaStatus SourceVariables_spawnIoJobWrite (ASSourceVariableJobId jobId,
					    IOManagerCallback * callback,
					    OpcUa_UInt32 hTransaction,
					    OpcUa_UInt32 callbackHandle,
					    const UaNode * parentNode,
					    OpcUa_WriteValue * pWriteValue);


}

#endif				// BACKEND_OPEN62541


#endif				// include guard
