##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug_Win
ProjectName            :=SoftwareRender
ConfigurationName      :=Debug_Win
WorkspacePath          := "C:\code\SoftwareRender"
ProjectPath            := "C:\code\SoftwareRender\SoftwareRender"
IntermediateDirectory  :=./bin_debug_win32
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Vladislav
Date                   :=19/10/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
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
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include $(IncludeSwitch)SDL2/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 
ArLibs                 :=  "mingw32" "SDL2main" "SDL2" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)SDL2/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe
CC       := C:/TDM-GCC-32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
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
	@$(MakeDirCommand) "./bin_debug_win32"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./bin_debug_win32"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/code/SoftwareRender/SoftwareRender/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix): src/SDLApp.cpp $(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/code/SoftwareRender/SoftwareRender/src/SDLApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix): src/SDLApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SDLApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SDLApp.cpp$(DependSuffix) -MM "src/SDLApp.cpp"

$(IntermediateDirectory)/src_SDLApp.cpp$(PreprocessSuffix): src/SDLApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SDLApp.cpp$(PreprocessSuffix) "src/SDLApp.cpp"

$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix): src/SoftwareRender.cpp $(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/code/SoftwareRender/SoftwareRender/src/SoftwareRender.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix): src/SoftwareRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SoftwareRender.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SoftwareRender.cpp$(DependSuffix) -MM "src/SoftwareRender.cpp"

$(IntermediateDirectory)/src_SoftwareRender.cpp$(PreprocessSuffix): src/SoftwareRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SoftwareRender.cpp$(PreprocessSuffix) "src/SoftwareRender.cpp"

$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix): src/Model.cpp $(IntermediateDirectory)/src_Model.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/code/SoftwareRender/SoftwareRender/src/Model.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Model.cpp$(DependSuffix): src/Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Model.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Model.cpp$(DependSuffix) -MM "src/Model.cpp"

$(IntermediateDirectory)/src_Model.cpp$(PreprocessSuffix): src/Model.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Model.cpp$(PreprocessSuffix) "src/Model.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./bin_debug_win32/


