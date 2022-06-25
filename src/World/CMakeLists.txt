project(World) #project name

set(SOURCE_LIB World_field.cpp Cell.h) #SOURCE_LIB var defenition

add_library(World_field STATIC ${SOURCE_LIB}) #static lib creation
