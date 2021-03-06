[Variables]
Tray_X=11

[Metadata]
Name=Papirus\\Tray
Author=reddit.com/u/khanhas
Description=Click to show tray

[TrayShape]
Meter=Shape
X=#Tray_X#
Y=(#Bar_OffsetY#+#Bar_Height#/2-#Section_Height#/2)
Shape=Rectangle 0,0,(#Section_Height#),(#Section_Height#),5 | StrokeWidth 0 | Fill Color #Color_Scheme1#
DynamicVariables=1
Hidden=1

[TrayXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[TrayButton:X]+[TrayButton:W]/2
DynamicVariables=1

[TrayButton]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\traymenu.png
ImageRotate=(180*(1-[SubSkinDirectionCalc]))
W=(#Font_Size#*20/14)
X=(#Section_Height#/2 - [TrayButton:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2-[TrayButton:H]/2)
SolidColor=0,0,0,1
MouseOverAction=[!ShowMeter TrayShape][!UpdateMeter TrayButton][!Redraw]
MouseLeaveAction=[!HideMeter TrayShape][!UpdateMeter TrayButton][!Redraw]
LeftMouseDownAction=["#@#ActivateTray.exe" "[TrayXPos]" "[SubSkinYPositionCalc]" "[SubSkinDirectionCalc]"]
DynamicVariables=1
