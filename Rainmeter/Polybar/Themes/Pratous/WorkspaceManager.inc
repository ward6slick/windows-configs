[Variables]
Workspacemanager_x=0
;Left, Right or Center
Workspacemanager_Anchor=Left
Maximum_Workspace = 4
Workspace_Number_Gap = 15

;Self-generated, change Workspacemanager_Anchor instead.
WorkspaceAnchorPoint = 0

[Metadata]
Name=Papirus\\Workspace Manager
Author=reddit.com/u/khanhas
Description=Click at number to change to desired workspace. Middle click to create new workspace. Choose a windows then hold Shift + click at number to move that window to desired workspace.

[GetWorkspaceVariable]
Measure=PLugin
Plugin=RunCommand
Program=""#@#WorkspaceManager.exe" "#PROGRAMPATH#Rainmeter.exe" "Workspace_Total" "Workspace_Current" "#RootConfig#""

[WorkspaceWindowSendMessage]
Measure=Plugin
Plugin=WindowMessagePlugin
WindowName=#@#WorkspaceManager.exe

[WorkspaceAnchorPoint]
Measure=String
String = #Workspacemanager_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetVariable WorkspaceAnchorPoint "[*WorkspaceShape:W*]/2"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetVariable WorkspaceAnchorPoint "[*WorkspaceShape:W*]"]

[WorkspaceShape]
Meter=Shape
X=(#Bar_OffsetX#+#workspacemanager_x#-#WorkspaceAnchorPoint#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-20)
Shape=Rectangle 0,0,(#Workspace_Number_Gap#*2*#Maximum_Workspace#),#Bar_Height# | StrokeWidth 0 | Fill Color 0,0,0,1
DynamicVariables=1 
;Save current active windows
MouseOverAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 5 1"]
;New desktop
MiddleMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 3 1"]
RightMouseUpAction=[!WriteKeyValue Variables Curr_X ([WorkspaceShape:X]+[WorkspaceShape:W]/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\WindowsTiler.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\WindowsTiler.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\WindowsTiler.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "WindowsTiler.ini"]

[WorkspaceError]
Meter=String
Text=Error
FontFace=#Font_Face1#
FontColor=#Color_Scheme2#
FontSize=#Font_Size#
AntiAlias=1
SolidColor=0,0,0,1
X=10r
Y=(#Bar_Height#/2)r
StringAlign=LeftCenter
ToolTipText=Workspace manager only works with Windows 10.#Crlf#If you're using Windows 10, try Refresh Skin.
Hidden=1

[WorkspaceScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\script_Workspace.lua

[WorkspaceActionTimer]
Measure=Plugin
Plugin=Actiontimer
ActionList1=Repeat ScriptAnimation,16,1000
ScriptAnimation=!CommandMeasure WorkspaceScript "ChangeWorkspaceAnimation()"

[WorkspaceCurrent]
Meter=Shape
X=(#Bar_OffsetX#+#workspacemanager_x#-#WorkspaceAnchorPoint#)
Y=(#Bar_OffsetY#)
IndicatorTrait = StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1

[StyleWSNumber]
X=R
Y=(#Bar_OffsetY#+#Bar_Height#/2)
FontFace=#Font_Face#
FontColor=#Color_Scheme2#
FontSize=#Font_Size#
AntiAlias=1
SOlidColor=0,0,0,1
H=40
W=(#Workspace_Number_Gap#*2)
StringAlign=CenterCenter
Hidden=1

[Workspace1]
Meter=String
Text=1
X=(#Bar_OffsetX#+#workspacemanager_x#+#Workspace_Number_Gap#-#WorkspaceAnchorPoint#)
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 1"]
DynamicVariables=1 
[Workspace2]
Meter=String
Text=2
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 2"]
[Workspace3]
Meter=String
Text=3
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 3"]
[Workspace4]
Meter=String
Text=4
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 4"]
[Workspace5]
Meter=String
Text=5
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 5"]
[Workspace6]
Meter=String
Text=6
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 6"]
[Workspace7]
Meter=String
Text=7
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 7"]
[Workspace8]
Meter=String
Text=8
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 8"]
[Workspace9]
Meter=String
Text=9
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 9"]
[Workspace10]
Meter=String
Text=10
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure WorkspaceWindowSendMessage "SendMessage 16687 2 10"]
