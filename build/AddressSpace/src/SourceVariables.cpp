
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
    
    This file was completely generated by Quasar (additional info: using transform designToSourceVariablesBody.xslt) 
    on 2020-02-27T16:16:09.992Z
 */



#include <SourceVariables.h>
#include <LogIt.h>
using namespace std;

namespace AddressSpace
{

  /* The thread pool should be initialized by Meta while reading the config file, using function: 
     SourceVariables_initSourceVariablesThreadPool */
  static Quasar::ThreadPool * sourceVariableThreads = 0;
  void SourceVariables_initSourceVariablesThreadPool (unsigned int minThreads,
						      unsigned int maxThreads,
						      unsigned int maxJobs)
  {
    LOG (Log::
	 DBG) << "Initializing source variables thread pool to min=" <<
      minThreads << " max=" << maxThreads << " threads maxJobs=" << " jobs";
    sourceVariableThreads = new Quasar::ThreadPool (maxThreads, maxJobs);
  }

  void SourceVariables_destroySourceVariablesThreadPool ()
  {
    if (sourceVariableThreads)
      {
	delete sourceVariableThreads;
	sourceVariableThreads = nullptr;
      }
  }

  Quasar::ThreadPool * SourceVariables_getThreadPool ()
  {
    return sourceVariableThreads;
  }
}

#ifndef BACKEND_OPEN62541


#include <iomanager.h>

#include <iostream>
#include <stdexcept>

#include <QuasarThreadPool.h>





namespace AddressSpace
{




  UaStatus SourceVariables_spawnIoJobRead (ASSourceVariableJobId jobId,
					   IOManagerCallback * callback,
					   OpcUa_UInt32 hTransaction,
					   OpcUa_UInt32 callbackHandle,
					   const UaNode * parentNode)
  {
    if (!sourceVariableThreads)
      throw std::
	runtime_error
	("Attempted Source Variable operation, but Source Variable threads are not up.");
    switch (jobId)
      {

      default:
	return OpcUa_Bad;
      }
  }

  UaStatus SourceVariables_spawnIoJobWrite (ASSourceVariableJobId jobId,
					    IOManagerCallback * callback,
					    OpcUa_UInt32 hTransaction,
					    OpcUa_UInt32 callbackHandle,
					    const UaNode * parentNode,
					    OpcUa_WriteValue * pWriteValue)
  {
    if (!sourceVariableThreads)
      throw std::
	runtime_error
	("Attempted Source Variable operation, but Source Variable threads are not up.");
    switch (jobId)
      {

      default:
	return OpcUa_Bad;
      }
  }

}

#endif // BACKEND_OPEN62541
