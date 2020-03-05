
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/include/ASMotor.h 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass Motor --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassHeader.xslt Configuration.hxx_GENERATED validateDesign
    ) 
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/include/ASController.h 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass Controller --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassHeader.xslt Configuration.hxx_GENERATED validateDesign
    ) 
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/include/ASTemperatureProbe.h 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass TemperatureProbe --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassHeader.xslt Configuration.hxx_GENERATED validateDesign
    ) 
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/include/ASAirFlowProbe.h 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass AirFlowProbe --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassHeader.xslt Configuration.hxx_GENERATED validateDesign
    ) 
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/include/ASPurityMonitor.h 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass PurityMonitor --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassHeader.xslt Configuration.hxx_GENERATED validateDesign
    ) 
	
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/AddressSpace/src/AddressSpaceClasses.cpp 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate asclass_cpp_all --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/AddressSpace/designToClassBody.xslt Configuration.hxx_GENERATED validateDesign
    )
    
	set(ADDRESSSPACE_CLASSES 
	${PROJECT_BINARY_DIR}/AddressSpace/src/AddressSpaceClasses.cpp
	)
	
	set(ADDRESSSPACE_HEADERS
	
	${PROJECT_BINARY_DIR}/AddressSpace/include/ASMotor.h
	
	${PROJECT_BINARY_DIR}/AddressSpace/include/ASController.h
	
	${PROJECT_BINARY_DIR}/AddressSpace/include/ASTemperatureProbe.h
	
	${PROJECT_BINARY_DIR}/AddressSpace/include/ASAirFlowProbe.h
	
	${PROJECT_BINARY_DIR}/AddressSpace/include/ASPurityMonitor.h
	
	)
	

	
	