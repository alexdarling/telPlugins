from telplugins import *

try:  
    sbmlModel ="BIOMD0000000203.xml"                              
    auto = Plugin("tel_auto2000")              
    
    #print auto.listOfPropertyNames()
    
    #Setup Auto Propertys
    auto.setProperty("SBML", readAllText(sbmlModel))
    
    #Auto specific properties
    auto.setProperty("ScanDirection", "Positive")    
    auto.setProperty("PrincipalContinuationParameter", "A")
    auto.setProperty("PCPLowerBound", 10)
    auto.setProperty("PCPUpperBound", 200)
    
    #Max numberof points
    auto.setProperty("NMX", 5000)  
           
    #Execute the plugin
    auto.execute()
         
    # Bifurcation summary
    print "Summary: " + auto.BifurcationSummary
    
    #Plot Bifurcation diagram
    pts     = auto.BifurcationPoints
    lbls    = auto.BifurcationLabels
    biData  = auto.BifurcationData    

    biData.plotBifurcationDiagram(pts, lbls) 
        
    print "Done"

except Exception as e:
    print "There was a problem: " + `e`
