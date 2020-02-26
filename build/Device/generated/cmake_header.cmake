
	
    add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Device/generated/Base_All.cpp 
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMAND python quasar.py generate base_cpp_all --project_binary_dir ${PROJECT_BINARY_DIR}
    DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/quasar.py Configuration.hxx_GENERATED validateDesign ${PROJECT_SOURCE_DIR}/Device/designToDeviceBaseBody.xslt
    )   
	
	
	
	add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Device/generated/Base_DMotor.h 
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	COMMAND python quasar.py generate base_h Motor --project_binary_dir ${PROJECT_BINARY_DIR}
	DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/quasar.py ${PROJECT_SOURCE_DIR}/Device/designToDeviceBaseHeader.xslt Configuration.hxx_GENERATED validateDesign 
	)	
	
	
	
	
	add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Device/generated/Base_DController.h 
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	COMMAND python quasar.py generate base_h Controller --project_binary_dir ${PROJECT_BINARY_DIR}
	DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/quasar.py ${PROJECT_SOURCE_DIR}/Device/designToDeviceBaseHeader.xslt Configuration.hxx_GENERATED validateDesign 
	)	
	
	
	
	
	add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Device/generated/Base_DTemperatureProbe.h 
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	COMMAND python quasar.py generate base_h TemperatureProbe --project_binary_dir ${PROJECT_BINARY_DIR}
	DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/quasar.py ${PROJECT_SOURCE_DIR}/Device/designToDeviceBaseHeader.xslt Configuration.hxx_GENERATED validateDesign 
	)	
	
	
	
	
	add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/Device/generated/Base_DAirFlowProbe.h 
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	COMMAND python quasar.py generate base_h AirFlowProbe --project_binary_dir ${PROJECT_BINARY_DIR}
	DEPENDS ${DESIGN_FILE} ${PROJECT_SOURCE_DIR}/quasar.py ${PROJECT_SOURCE_DIR}/Device/designToDeviceBaseHeader.xslt Configuration.hxx_GENERATED validateDesign 
	)	
	
	
	
	
	set(DEVICEBASE_GENERATED_FILES
        include/DRoot.h
        src/DRoot.cpp
        generated/Base_All.cpp
	
	generated/Base_DMotor.h
	
	generated/Base_DController.h
	
	generated/Base_DTemperatureProbe.h
	
	generated/Base_DAirFlowProbe.h
	
	)
	
	set(DEVICE_CLASSES
	
	src/DMotor.cpp
	
	src/DController.cpp
	
	src/DTemperatureProbe.cpp
	
	src/DAirFlowProbe.cpp
	
	)

	add_custom_target(DeviceBase DEPENDS ${DEVICEBASE_GENERATED_FILES} )
	
	add_custom_target(DeviceGeneratedHeaders DEPENDS include/DRoot.h ${DEVICEBASE_GENERATED_FILES})
	
	