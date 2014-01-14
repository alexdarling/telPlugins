/**
 * @file rrplugins_c_api.h
 * @brief Plugins Core C-API Header
 * @author Totte Karlsson & Herbert M Sauro
 *
 * <--------------------------------------------------------------
 * This file is part of cRoadRunner.
 * See http://code.google.com/p/roadrunnerlib for more details.
 *
 * Copyright (C) 2012-2013
 *   University of Washington, Seattle, WA, USA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * In plain english this means:
 *
 * You CAN freely download and use this software, in whole or in part, for personal,
 * company internal, or commercial purposes;
 *
 * You CAN use the software in packages or distributions that you create.
 *
 * You SHOULD include a copy of the license in any redistribution you may make;
 *
 * You are NOT required include the source of software, or of any modifications you may
 * have made to it, in any redistribution you may assemble that includes it.
 *
 * YOU CANNOT:
 *
 * redistribute any piece of this software without proper attribution;
*/
#ifndef rrplugins_c_apiH
#define rrplugins_c_apiH
#include "rrplugins_exporter.h"
#include "rrplugins_types.h"
#include "rrplugins_properties_api.h"
//---------------------------------------------------------------------------

#if defined(__cplusplus)
namespace rrp { extern "C" {
#endif

/*!
 \brief Create a new instance of a plugin manager.
 \brief A PluginManager manages a collection of plugins, loaded and unloaded by
  the load and unload API functions respectively.
 \param pluginDir Full path to folder containing plugins. If NULL, uses default folder.
 \return On success, a handle to a Plugin manager, on failure, NULL.
 \ingroup plugin_manager
 */
RRP_C_DS RRPluginManagerHandle rrp_cc createPluginManager(const char* pluginDir);

/*!
 \brief Free the plugin manager. A call to this function will also unload any loaded plugins.
 \param handle Handle to a plugin manager. 
 \return true if success, false otherwise. 
 \ingroup plugin_manager
 */
RRP_C_DS bool rrp_cc freePluginManager(RRPluginManagerHandle handle);

/*!
 \brief Load plugins. The function will look in the default plugin folder for plugins, and load them.
 \param handle Handle to a PluginManager instance
 \return Returns an integer holding number of succesfully loaded plugins
 \ingroup plugin_manager
*/
RRP_C_DS int rrp_cc loadPlugins(RRPluginManagerHandle handle);

/*!
 \brief Unload plugins
 \param handle Handle to a PluginManager instance
 \return Returns true if Plugins are unloaded succesfully, false otherwise
 \ingroup plugin_manager
*/
RRP_C_DS bool rrp_cc unLoadPlugins(RRPluginManagerHandle handle);

/*!
 \brief Load a particular plugin
 \param handle Handle to a PluginManager instance
 \param pluginName Name of the plugin to load. The plugin name is the plugins shared library name, without path and extension.
 \return Returns a handle to a plugin, NULL if unsuccesfull
 \ingroup plugin_manager 
*/
RRP_C_DS RRPluginHandle rrp_cc loadPlugin(RRPluginManagerHandle handle, const char* pluginName);

/*!
 \brief unload a particular plugin
 \param handle Handle to a PluginManager instance
 \param plugin Handle to a Plugin instance
 \return Returns true if the Plugin are unloaded succesfully, false otherwise
 \ingroup plugin_manager
*/
RRP_C_DS bool rrp_cc unLoadPlugin(RRPluginManagerHandle handle, RRPluginHandle plugin);

/*!
 \brief Get Number of loaded plugins.
 \param handle Handle to a PluginManager instance
 \return Returns the number of loaded plugins, -1 if a problem is encountered
 \ingroup plugin_manager
*/
RRP_C_DS int rrp_cc getNumberOfPlugins(RRPluginManagerHandle handle);

/*!
 \brief Function to retrieve the names of currently loaded plugins.
 \param handle Handle to a PluginManager instance
 \return Returns names for loaded plugins as a RRStringArrayPtr, NULL otherwise
 \ingroup plugin_manager
*/
RRP_C_DS char* rrp_cc getPluginNames(RRPluginManagerHandle handle);

/*!
 \brief Function to retrieve the library name of currently loaded plugins.
 \param handle Handle to a PluginManager instance
 \return Returns names for loaded plugins as a RRStringArrayPtr, NULL otherwise
 \ingroup plugin_manager
*/
RRP_C_DS char* rrp_cc getPluginLibraryNames(RRPluginManagerHandle handle);

/*!
 \brief getFirstPlugin retrieves the "first" plugin in the plugin managers internal list of plugins.
 This function is typically used together with the getNextPlugin and the getPreviousPlugin functions.
 \param handle Handle to a PluginManager instance
 \return Returns a handle to a plugin. Returns NULL if the plugin is not found
 \ingroup plugin_manager
*/
RRP_C_DS RRPluginHandle rrp_cc getFirstPlugin(RRPluginManagerHandle handle);

/*!
 \brief getNextPlugin retrieves the "next" plugin in the plugin managers internal list of plugins. This function
    is typically used together with the getFirstPlugin and getPreviousPlugin functions.
 \param handle Handle to a PluginManager instance
 \return Returns a handle to a plugin. Returns NULL if the plugin is not found
 \ingroup plugin_manager
*/
RRP_C_DS RRPluginHandle rrp_cc getNextPlugin(RRPluginManagerHandle handle);

/*!
 \brief getPreviousPlugin retrieves the "previous" plugin in the plugin managers internal list of plugins. This function
    is typically used together with the getFirstPlugin and getNextPlugin functions.
 \param handle Handle to a PluginManager instance
 \return Returns a handle to a plugin. Returns NULL if the plugin is not found
 \ingroup plugin_manager
*/
RRP_C_DS RRPluginHandle rrp_cc getPreviousPlugin(RRPluginManagerHandle handle);

/*!
 \brief getCurrentPlugin retrieves the "current" plugin in the plugin managers internal list of plugins. This function
    is typically used together with the getFirst, Next and getPreviousPlugin functions.
 \param handle Handle to a PluginManager instance
 \return Returns a handle to a plugin. Returns NULL if the plugin is not found
 \ingroup plugin_manager
*/
RRP_C_DS RRPluginHandle rrp_cc getCurrentPlugin(RRPluginManagerHandle handle);

/*!
 \brief GetPluginHandle
 \param handle Handle to a PluginManager instance
 \param pluginName Pointer to string holding the name of a plugin
 \return Returns a handle to a plugin, with name as supplied in the parameter pluginName.
 Returns NULL if the plugin is not found
 \ingroup plugin_manager
*/
RRP_C_DS RRPluginHandle rrp_cc getPlugin(RRPluginManagerHandle handle, const char* pluginName);

/*!
 \brief Get a handle to a plugins shared library
 \param handle Handle to a PluginManager instance
 \param pluginHandle Handle to a plugin
 \return Returns a handle to the shared library holding a plugin. Returns  -1 if the handle can't be retrieved.
 \note This function is not yet implemented..
 \ingroup plugin_manager
*/
RRP_C_DS long rrp_cc getPluginSharedLibHandle(RRPluginManagerHandle handle, RRPluginHandle pluginHandle);


//==========================  PLUGIN HANDLE functions
/*!
 \brief Get the name of a Plugin.
 \param handle Handle to a plugin
 \return Returns a string on success, NULL otherwise
  \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginName(RRPluginHandle handle);

/*!
 \brief Return a plugins Category. A plugin developer may assign this information. 
 \param handle Handle to a plugin
 \return Returns a string on success, NULL otherwise

 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginCategory(RRPluginHandle handle);

/*!
 \brief Return a plugins description. This is assigned by the plugin developer. 
 \param handle Handle to a plugin
 \return Returns a string on success, NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginDescription(RRPluginHandle handle);

/*!
 \brief Return a plugins Hint. This information is assigned by the plugin developer.
 \param handle Handle to a plugin
 \return Returns a string on success, NULL otherwise
  \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginHint(RRPluginHandle handle);

/*!
 \brief Return some information about a Plugin. 
 \param handle Handle to a plugin
 \return Returns info, as a string, for the plugin, NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginInfo(RRPluginHandle handle);

/*!
 \brief Get Plugin manual as PDF. A plugin may embedd a help manual as a PDF. This function return such as a pointer to a string. 
 Use the function getPluginManualNrOfBytes to get the exact length of this string.
 \param handle Handle to a plugin
 \return Returns the plugins manuals pdf file as a unsigned char*. If not available, returns NULL.
 \ingroup plugins
*/
RRP_C_DS unsigned char* rrp_cc getPluginManualAsPDF(RRPluginHandle handle);

/*!
 \brief Get the byte size for the PDF manual.
 \param handle Handle to a plugin
 \return Returns the nr of bytes in the plugins manuals pdf file as an unsigned int.
 \ingroup plugins
*/
RRP_C_DS unsigned int rrp_cc getPluginManualNrOfBytes(RRPluginHandle handle);

/*!
 \brief Assign a roadrunner instance handle for the plugin to use.
    A plugin may use an externally created roadrunner instance for its internal work.
  \param pHandle Handle to a plugin
  \param rrHandle Handle to a RoadRunner instance
  \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc assignRoadRunnerInstance(RRPluginHandle pHandle, RRHandle rrHandle);

/*!
 \brief The executePlugin function is the function designated to fire of a Plugins "worker".
 What is done when this function is entered is plugin dependent.
 \param handle Handle to a plugin
 \return Returns true or false indicating success/failure
 \note The execute function is blocking. If the plugin is todo long work, consider using
 the executePluginEx function that have the option to execute the plugin code in a thread.
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc executePlugin(RRPluginHandle handle);

/*!
 \brief The executePluginEx is similar to the executePlugin function, except it takes two extra arguments.
 \param handle Handle to a plugin
 \param inAThread bool indicating if the plugin should be executed in a thread.
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc executePluginEx(RRPluginHandle handle, bool inAThread);

/*!
 \brief Get some status of a plugin. See the plugins documentation on what to expect. 
 \param handle Handle to a plugin
 \return Returns plugin status if available, as a string. NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginStatus(RRPluginHandle handle);

/*!
 \brief Returns a plugins result, as a string. See the plugins documentation on what to expect. 
 \param handle Handle to a plugin
 \return Returns a plugins result if available. NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginResult(RRPluginHandle handle);

/*!
 \brief Reset a Plugin. Plugin dependent. A reset function should bring the internal state of a plugin to a known state
 \param handle Handle to a plugin
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc resetPlugin(RRPluginHandle handle);

/*!
 \brief check if plugin is actively working
 \param handle Handle to a plugin
 \return Returns true or false indicating i the plugin is busy or not
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc isPluginWorking(RRPluginHandle handle);

/*!
 \brief Terminate any work that is in progress in a plugin. If the plugins worker is executed in a thread, this function
 will signal the internals of the plugin to terminate. 
 \param handle Handle to a plugin
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS void rrp_cc terminateWork(RRPluginHandle handle);

/*!
 \brief Check if the work of a plugin is currently being terminated
 \param handle Handle to the plugin
 \return Returns true or false indicating if the work within the plugin is in the process of being terminated
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc isBeingTerminated(RRPluginHandle handle);

/*!
 \brief wasTerminated. query a  plugin if work was terminated before completion
 \param handle Handle to the plugin
 \return Returns true or false indicating if the work in the plugin was terminated or not
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc wasTerminated(RRPluginHandle handle);

/*!
 \brief Assign event function fired when a plugin starts its work
 \param handle Handle to a plugin
 \param cb Function pointer to event routine
 \param userData1 void* pointer to user data.
 \param userData2 void* pointer to user data.
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc assignOnStartedEvent(RRPluginHandle handle, PluginEvent cb, void* userData1, void* userData2);

/*!
 \brief Assign event function fired as a plugin progresses
 \param handle Handle to a plugin
 \param cb Function pointer to event routine
 \param userData1 void* pointer to user data.
 \param userData2 void* pointer to user data.
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc assignOnProgressEvent(RRPluginHandle handle, PluginEvent cb, void* userData1, void* userData2);

/*!
 \brief Assign event function fired when a plugin finishes its work
 \param handle Handle to a plugin
 \param cb Function pointer to event routine
 \param userData1 void* pointer to user data.
 \param userData2 void* pointer to user data.
 \return Returns true or false indicating success/failure
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc assignOnFinishedEvent(RRPluginHandle handle, PluginEvent cb, void* userData1, void* userData2);

///*
// \brief Hand external data to a plugin
// \param handle Handle to a plugin
// \param userData void* pointer to user data. Plugin dependent.
// \return Returns true or false indicating success/failure
// \ingroup plugins
//*/
//RRP_C_DS bool rrp_cc assignPluginInput(RRPluginHandle handle, void* userData);

/*!
 \brief Get roadrunner instance handle from plugin
 \param handle Handle to a Plugin instance
 \return Returns a handle to a rrInstance if available, returns NULL otherwise
 \ingroup plugins
*/
RRP_C_DS RRHandle rrp_cc getRRHandleFromPlugin(RRPluginHandle handle);

/*!
 \brief Get a Plugins Propertiese as an xml document. The string returned from this function is formated as xml.
 \param handle Handle to a plugin
 \return Returns available properties in the plugin, as a pointer to a string, NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getPluginPropertiesAsXML(RRPluginHandle handle);

/*!
 \brief Get a handle to a plugins properties
 \param handle Handle to a plugin
  \return Returns a handle to a plugins property container, NULL otherwise
 \ingroup plugins
*/
RRP_C_DS RRPropertiesHandle rrp_cc getPluginProperties(RRPluginHandle handle);

/*!
 \brief Get a list of a plugins property names, as a string. Space being the delimiter.
 \param handle Handle to a plugin
  \return Returns a string if succesfull, NULL otherwise
 \ingroup plugins
*/
RRP_C_DS char* rrp_cc getListOfPluginPropertyNames(RRPluginHandle handle);

/*!
 \brief Get a handle to a property.
 \param handle Handle to a plugin
 \param propertyName Name of the property
 \return Returns a handle to a property. Returns NULL if not found
 \ingroup plugins
*/
RRP_C_DS RRPropertyHandle rrp_cc getPluginProperty(RRPluginHandle handle, const char* propertyName);

/*!
 \brief Set the value of a PluginProperty by a string.
 \param handle Handle to a plugin
 \param propertyName Name of property
 \param value Value of property, as string
 \return true if succesful, false otherwise
 \ingroup plugins
*/
RRP_C_DS bool rrp_cc setPluginProperty(RRPluginHandle handle, const char* propertyName, const char* value);

/*!
 \brief Retrieve a handle to RoadRunners internal data
 \param handle Handle to a RoadRunner instance
 \return Returns an handle to roadrunners internal data object
 \ingroup simulation
*/
RRP_C_DS RRDataHandle rrp_cc getRoadRunnerDataHandle(RRHandle handle);

/*!
 \brief Create a RoadRunner C data structure (RRCDataPtr) from RoadRunner data
 \param rrDataHandle A pointer to a RoadRunner numerical data type variable
 \return Returns NULL if fails, otherwise returns a RRCData handle
 \ingroup utilities
*/
RRP_C_DS RRCDataPtr rrp_cc createRRCData(RRDataHandle rrDataHandle);

/*!
 \brief Retrieve the number of rows in the given RoadRunner C numberical data (returned from simulate(RRHandle handle))

 Example: \code nRows = getRRDataNumRows (result); \endcode

 \param rrData A pointer to a RoadRunner numerical data type variable
 \return Returns -1 if fails, otherwise returns the number of rows
 \ingroup utilities
*/
RRP_C_DS int rrp_cc getRRCDataNumRows (RRCDataPtr rrData);

/*!
 \brief Retrieve the number of columns in the given rrCData data (returned form simulat(RRHandle handle))

 Example: \code nRows = getResultNumCols (rrData); \endcode

 \param rrData A pointer to a rrData type variable
 \return Returns -1 if fails, otherwise returns the number of columns
 \ingroup utilities
*/
RRP_C_DS int rrp_cc getRRCDataNumCols (RRCDataPtr rrData);

/*!
 \brief Retrieves an element at a given row and column from a RRCData struct type variable

 RoadRunner numerical data are indexed from zero

 Example: \code status = getRRCDataElement (rrData, 2, 4, *value); \endcode

 \param rrcData A pointer to a rrCData type variable
 \param r -The row index to the rrData data
 \param c - The column index to the rrData data
 \param[out] value - The retrieved value from the rrData data
 \return Returns true if succesful
 \note The F indicate this is a forwarde fucntion from RoadRUnners C API.
 \ingroup utilities
*/
RRP_C_DS bool rrp_cc getRRCDataElementF(RRCDataPtr rrcData, int r, int c, double *value);


/*!
 \brief Retrieves an element at a given row and column from a RoadRunner data type variable

 RoadRunner numerical data are indexed from zero

 Example: \code status = getRoadRunnerDataElement (rrDataHandle, 2, 4, *value); \endcode

 \param rrData A Handle o a RoadRunner data type variable
 \param r The row index to the rrData data
 \param c The column index to the rrData data
 \param[out] value - The retrieved value from the rrData data
 \return Returns true if succesful
 \ingroup utilities
*/
RRP_C_DS bool rrp_cc getRoadRunnerDataElement(RRDataHandle rrData, int r, int c, double *value);

/*!
 \brief Retrieves a RoadRunner data column header. The column header is a string 
 with comma delimited values. Each value is a header for correseponding data column.

 \param data A handle to a RoadRunner data type variable
 \return Returns a string containing the header as a string, NULL if unsuccesful
 \ingroup utilities
*/
RRP_C_DS char* rrp_cc getRoadRunnerDataColumnHeader(RRDataHandle data);


/*!
 \brief Retrieves the number of rows in a RoadRunner data object.

 \param data A handle to a RoadRunner data type variable
 \return Returns the number of rows in the underlying data object.
 \ingroup utilities
*/
RRP_C_DS int rrp_cc getRoadRunnerDataNumRows(RRDataHandle data);

/*!
 \brief Retrieves the number of cols in a RoadRunner data object.

 \param data A handle to a RoadRunner data type variable
 \return Returns the number of cols in the underlying data object.
 \ingroup utilities
*/
RRP_C_DS int rrp_cc getRoadRunnerDataNumCols(RRDataHandle data);

/*!
 \brief Creates a RoadRunner data object, and returns a handle to it.

 \param rows Number of rows to create.
 \param cols Number of cols to create.
 \param colNames Column header as a string, e.g. "time, S1, S2". 
 \return Returns a handle to a RoadRunner data object, NULL if unsuccessfull.
 \ingroup utilities
*/
RRP_C_DS RRDataHandle rrp_cc createRoadRunnerData(int rows, int cols, char* colNames);

/*!
 \brief Free the memory allocated by a RoadRunner data object.
 \param handle A RRDataHandle handle to an underlying RoadRunnerData object.

 \return Returns a boolean indicating success.
 \ingroup utilities
*/
RRP_C_DS bool rrp_cc freeRoadRunnerData(RRDataHandle handle);

/*!
 \brief Returns a string list in string form.
 \return Returns string list as a character string
 \ingroup utilities
 \note Forwarded from roadruners C API
*/
RRP_C_DS char* rrp_cc stringArrayToStringFWD(const RRStringArrayPtr list);

/*!
 \brief Write roadrunner data to file a RoadRunner data object.
 \param rrData A handle to RoadRunner data.
 \param fName Output file name as a string.
 \return Returns a boolean indicating success.
 \ingroup utilities
*/
RRP_C_DS bool rrp_cc writeRoadRunnerDataToFile(RRDataHandle rrData, char* fName);

/*!
 \brief Read roadrunner data from a file, into a RoadRunner data object.
 \param rrData A handle to RoadRunner data.
 \param fName File name to read data from.
 \return Returns a boolean indicating success.
 \ingroup utilities
*/RRP_C_DS bool rrp_cc readRoadRunnerDataFromFile(RRDataHandle rrData, char* fName);

/*!
 \brief Return last API error
 \return Returns a string with the error
 \ingroup utilities
 \note Forwarded from roadruners C API
*/
RRP_C_DS char* rrp_cc getLastPluginError();

/*!
 \brief Free char* generated by library routines
 \ingroup freeRoutines
*/
RRP_C_DS bool rrp_cc freeText(char* text);


#if defined(__cplusplus)
} }    //rrp namespace and extern "C"
#endif

#endif


/*! \mainpage Plugin framework for libRoadRunner

  \section intro_sec Introduction

  RoadRunner is a SBML compliant high performance and portable simulation engine
  for systems and synthetic biology.

  The plugin framework documented here, is available to assist in using and creating extensions (Plugins) to the main RoadRunner Core.
  A simple example (a C++ program using RoadRunners C API's) on how to get access to plugins is shown below.

\code
#include <iostream>
#include "rrc_api.h"
#include "rrplugins_c_api.h"

using namespace std;
using namespace rrc;
using namespace rrp;

int main()
{
    RRPluginManagerHandle pmHandle = createPluginManager();
    loadPlugins(pmHandle);

    cout<<"Nr of loaded plugins:" << getNumberOfPlugins(pmHandle)<<endl;
    RRStringArrayPtr names = getPluginNames(pmHandle);

    if(!names)
    {
        cout<<"No plugins loaded ..";
        return 0;
    }

    for(int i = 0; i < names->Count; i++)
        cout<<"\n";
        cout<<"Plugin name: " <<names->String[i]<<endl;

        //Get a handle to a plugin
        RRPluginHandle plHandle = getPlugin(pmHandle, names->String[i]);
        cout <<getPluginInfo(plHandle)<<endl;
    }


    //Cleanup.
    freeStringArray(names);
    unLoadPlugins(pmHandle);
    freePluginManager(pmHandle);
    return 0;
}
\endcode

    \section plugins_overview Overview
    The libRoadRunner Plugin API is centered around three important concepts:
    - A Plugin Manager (RRPluginManagerHandle)
    - A Plugin (RRPlugin)
    - Plugin Properties (RRProperty)

    \section plugins_usage How to use plugins
    A typical use case of the Plugin API may be as follows:

    Plugin usage scenario
    -# Client creates a PluginManager.
    -# Client load plugins using the Plugin Manager.
    -# Client get a handle to a plugin.
    -# Client get a handle to a specific property in the plugin.
    -# Client set the value of the property.
    -# Client excutes the plugin.
    -# Client retrieve the value of a plugins property, e.g. a "result" property.
    .

    \section plugins_writing How to write plugins
    The current plugin framework aim towards being a minimalistic API. As such, it is designed to give a plugin developer
    maximum amount of room for interacting with the RoadRunner core, and at the same time,
    a minimum of requirements and abstract concepts getting in the way of designing a plugin.

    This section will show you how to get on the way with your first plugin, using pure C. See examples and documentation on the 
    C++ pages on how to create a plugin using C++.

    \subsection Code The plugin code
    As any roadrunner plugin need to be compiled into a shared library, so does a plugin written in C. The following example will show how
    to design and create a plugin with one plugin property, named Demo Property. The purpose of the plugin is to populate this property
    with some data, generated by the core RoadRunner API.


 * \section install_sec Installation
 *
 * Installation documentation is provided on the RoadRunner homepage: http://www.libroadrunner.org

 * \section license_sec License
 * Copyright (C) 2012
 *   University of Washington, Seattle, WA, USA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * In plain english this means:
 *
 * You CAN freely download and use this software, in whole or in part, for personal,
 * company internal, or commercial purposes;
 *
 * You CAN use the software in packages or distributions that you create.
 *
 * You SHOULD include a copy of the license in any redistribution you may make;
 *
 * You are NOT required include the source of software, or of any modifications you may
 * have made to it, in any redistribution you may assemble that includes it.
 *
 * YOU CANNOT:
 *
 * redistribute any piece of this software without proper attribution;


 \defgroup plugin_manager Plugin Manager
 \brief Plugin Manager Library Functions

 \defgroup plugins Plugin Functions
 \brief Functions operating on Plugin Handles.

 \defgroup plugin_properties Plugin Properties
 \brief Plugins Property related functions

\defgroup utilities Utility Functions
 \brief Functions to help and assist in the use of the Plugins framework


*/



