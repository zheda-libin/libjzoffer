project(core)

aux_source_directory(. SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})
