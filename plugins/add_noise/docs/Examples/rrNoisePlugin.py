import matplotlib.pyplot as plot
import roadrunner
from telPlugins_CAPI import *

#Create a plugin manager
pm = createPluginManager()

#Create a roadrunner instance
rr = roadrunner.RoadRunner()

#Define callback functions
def pluginStarted():
    print 'The plugin was started'

def pluginIsProgressing(progress):
    nr = progress
    print '\nPlugin progress:' + `nr` +' %'

def pluginIsFinished():
    print 'The plugin did finish'

sbmlModel ="../../models/bistable.xml"
if not rr.load(sbmlModel):
    print 'Failed loading model'
    exit()

rr.simulate(0, 10, 500)

#The plugin will need a handle to the underlying roadrunner data
rrDataHandle = getTelluriumDataHandle(rr)

#Load the 'noise' plugin in order to add some noise to roadrunner data
noisePlugin = loadPlugin(pm, "tel_add_noise")

#The noise plugin has one parameter named, InputData.
#Assigning our data to it allow the plugin to do work on it
dataPara = getPluginParameter(noisePlugin, "InputData")
setParameter(dataPara, rrDataHandle)

#get parameter for the 'size' of the noise
#Set size of noise
setPluginParameter(noisePlugin,"Sigma", 1e-2)

cb_func1 =  NotifyEvent(pluginStarted)
assignOnStartedEvent(noisePlugin,  cb_func1)

cb_func2 =  NotifyIntEvent(pluginIsProgressing)
assignOnProgressEvent(noisePlugin, cb_func2)

cb_func3 =  NotifyEvent(pluginIsFinished)
assignOnFinishedEvent(noisePlugin, cb_func3)

#Execute the noise plugin which will add some noise to the (internal) data
executePlugin(noisePlugin)  

#Retrieve data from plugin
rrData = getNumpyData(getParameter(dataPara))
colNames = getTelluriumDataColumnHeader(rrDataHandle)

plotTelluriumData(rrData, colNames)

unLoadPlugins(pm)
print "done"
