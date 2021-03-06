[Variables] 0 1790
Tray_X=1790

[Metadata]
Name=Papirus\\Tray
Author=reddit.com/u/khanhas
Description=Click to show tray

[TrayShape]
Meter=Shape
X=#Tray_X#
Y=(#Bar_OffsetY#+#Bar_Height#/3-#Section_Height#/2)
Shape=Rectangle 0,0,(#Section_Height#),(#Section_Height#/1) | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1
LeftMouseDownAction=["#@#ActivateTray.exe" "[TrayXPos]" "[SubSkinYPositionCalc]" "[SubSkinDirectionCalc]"]

[TrayXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[TrayButton:X]+[TrayButton:W]/2
DynamicVariables=1

[TrayButton]
Meter=String
Text=+
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
W=(#Font_Size#)
X=(#Section_Height#/1.7 - [TrayButton:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/1.4-[TrayButton:H]/2)
DynamicVariables=1
