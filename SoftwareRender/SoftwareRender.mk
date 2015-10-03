##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SoftwareRender
ConfigurationName      :=Debug
WorkspacePath          := "/home/pacmancoder/Dropbox/SoftwareRender"
ProjectPath            := "/home/pacmancoder/Dropbox/SoftwareRender/SoftwareRender"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=pacmancoder
Date                   :=03/10/15
CodeLitePath           :="/home/pacmancoder/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="SoftwareRender.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SDL2 
ArLibs                 :=  "SDL2" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pacmancoder/Dropbox/SoftwareRender/SoftwareRender/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix): src/SDLApp.cpp $(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pacmancoder/Dropbox/SoftwareRender/SoftwareRender/src/SDLApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix): src/SDLApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix) -MM "src/SDLApp.cpp"

$(IntermediateDirectory)/src_SDLApp.cpp$(PreprocessSuffix): src/SDLApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SDLApp.cpp$(PreprocessSuffix) "src/SDLApp.cpp"

$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix): src/SoftwareRender.cpp $(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pacmancoder/Dropbox/SoftwareRender/SoftwareRender/src/SoftwareRender.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix): src/SoftwareRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix) -MM "src/SoftwareRender.cpp"

$(IntermediateDirectory)/src_SoftwareRender.cpp$(PreprocessSuffix): src/SoftwareRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SoftwareRender.cpp$(PreprocessSuffix) "src/SoftwareRender.cpp"

$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix): src/Model.cpp $(IntermediateDirectory)/src_Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pacmancoder/Dropbox/SoftwareRender/SoftwareRender/src/Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Model.cpp$(DependSuffix): src/Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Model.cpp$(DependSuffix) -MM "src/Model.cpp"

$(IntermediateDirectory)/src_Model.cpp$(PreprocessSuffix): src/Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Model.cpp$(PreprocessSuffix) "src/Model.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


