## 
##  Created on: Apr 03, 2012
##      Author: martinez
## 

## FOLDER SPECIFIC

SET(folder_package_depend ${OPENGL_FOUND} ${GLUT_FOUND} ${GLEW_FOUND})
SET(folder_link_libs ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})
SET(folder_include_dirs ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})
SET(folder_lib_depend )

### FOLDER GENERIC

SET(current_dir_lists ${CMAKE_CURRENT_LIST_FILE})
INCLUDE(${CMAKE_HOME_DIRECTORY}/cmake/BuildSrcFolderGenericLists.txt NO_POLICY_SCOPE)

# :mode=cmake:
