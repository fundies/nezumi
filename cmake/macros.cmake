# Defines the default value for the specified module.
MACRO (NEZUMI_MODULE_DEFAULT MODULE DEFAULT)
    SET ("${MODULE}_DEFAULT" ${DEFAULT})
ENDMACRO ()

# Defines an entry for the specified module.
MACRO (NEZUMI_MODULE_ENTRY MODULE ENTRY)
    # Parse the values of SOURCES and LIBRARIES.
    CMAKE_PARSE_ARGUMENTS ("ARGS" "" "" "SOURCES;LIBRARIES" ${ARGN})

    # Store the values of SOURCES and LIBRARIES.
    SET ("${MODULE}_${ENTRY}_SOURCES" ${ARGS_SOURCES})
    SET ("${MODULE}_${ENTRY}_LIBRARIES" ${ARGS_LIBRARIES})

    # Add the entry to the module's entry list.
    LIST (APPEND "${MODULE}_ENTRIES" ${ENTRY})
ENDMACRO ()

# Defines a cache option for the specified module.
MACRO (NEZUMI_MODULE_OPTION MODULE DOCSTRING)
    # Set the cache option to the module's default value.
    SET (${MODULE} "${${MODULE}_DEFAULT}" CACHE STRING ${DOCSTRING})

    # Set the STRINGS property to the module's entry list.
    SET_PROPERTY (CACHE ${MODULE} PROPERTY STRINGS "${${MODULE}_ENTRIES}")

    # Output the sources for the selected module.
    SET ("SOURCE_${MODULE}" "${${MODULE}_${${MODULE}}_SOURCES}")
ENDMACRO ()

# Links the module's libraries to the specified target.
MACRO (NEZUMI_MODULE_TARGET MODULE TARGET)
    TARGET_LINK_LIBRARIES (${TARGET} PRIVATE "${${MODULE}_${${MODULE}}_LIBRARIES}")
ENDMACRO ()