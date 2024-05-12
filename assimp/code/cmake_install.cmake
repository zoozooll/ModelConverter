# Install script for directory: H:/workspaces/qt/ModelConverter/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.0-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "H:/workspaces/qt/ModelConverter/assimp/lib/Debug/assimp-vc143-mtd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "H:/workspaces/qt/ModelConverter/assimp/lib/Release/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "H:/workspaces/qt/ModelConverter/assimp/lib/MinSizeRel/assimp-vc143-mt.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "H:/workspaces/qt/ModelConverter/assimp/lib/RelWithDebInfo/assimp-vc143-mt.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.0" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "H:/workspaces/qt/ModelConverter/assimp/bin/Debug/assimp-vc143-mtd.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "H:/workspaces/qt/ModelConverter/assimp/bin/Release/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "H:/workspaces/qt/ModelConverter/assimp/bin/MinSizeRel/assimp-vc143-mt.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "H:/workspaces/qt/ModelConverter/assimp/bin/RelWithDebInfo/assimp-vc143-mt.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/anim.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/aabb.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ai_assert.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/camera.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/color4.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/color4.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/config.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ColladaMetaData.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/commonMetaData.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/defs.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/cfileio.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/light.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/material.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/material.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/matrix3x3.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/matrix3x3.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/matrix4x4.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/matrix4x4.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/mesh.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ObjMaterial.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/pbrmaterial.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/GltfMaterial.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/postprocess.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/quaternion.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/quaternion.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/scene.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/metadata.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/texture.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/types.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/vector2.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/vector2.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/vector3.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/vector3.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/version.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/cimport.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/AssertHandler.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/importerdesc.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Importer.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/DefaultLogger.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ProgressHandler.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/IOStream.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/IOSystem.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Logger.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/LogStream.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/NullLogger.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/cexport.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Exporter.hpp"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/DefaultIOStream.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/DefaultIOSystem.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SceneCombiner.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/fast_atof.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/qnan.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/BaseImporter.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Hash.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ParsingUtils.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/StreamReader.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/StreamWriter.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/StringComparison.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/StringUtils.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SGSpatialSort.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/GenericProperty.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SpatialSort.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SmallVector.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SmoothingGroups.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/SmoothingGroups.inl"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/StandardShapes.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/RemoveComments.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Subdivision.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Vertex.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/LineSplitter.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/TinyFormatter.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Profiler.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/LogAux.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Bitmap.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/XMLTools.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/IOStreamBuffer.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/CreateAnimMesh.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/XmlParser.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/BlobIOSystem.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/MathFunctions.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Exceptional.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/ByteSwapper.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Compiler/poppack1.h"
    "H:/workspaces/qt/ModelConverter/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "H:/workspaces/qt/ModelConverter/assimp/bin/Debug/assimp-vc143-mtd.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "H:/workspaces/qt/ModelConverter/assimp/bin/Release/assimp-vc143-mt.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "H:/workspaces/qt/ModelConverter/assimp/bin/MinSizeRel/assimp-vc143-mt.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "H:/workspaces/qt/ModelConverter/assimp/bin/RelWithDebInfo/assimp-vc143-mt.pdb")
  endif()
endif()

