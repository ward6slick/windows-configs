[Variables]
Tray_X=1776
;Left, Right or Center
Tray_Anchor = Right
Tray_Width=(#Font_Size#*4)

[Metadata]
Name=Fedina\\Tray
Author=reddit.com/u/khanhas
Description=Click to show tray

[TrayAnchor]
Measure=String
String = #Tray_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption TrayShape X "(#Bar_OffsetX#+#*Tray_X*#-#Tray_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption TrayShape X "(#Bar_OffsetX#+#*Tray_X*#-#Tray_Width#)"]

[TrayShape]
Meter=Shape
X=(#Bar_OffsetX#+#Tray_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Tray_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color #Color_Scheme2#
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', 'Tray_X')]
DynamicVariables=1

[TrayButton]
Meter=String
Text=+
FontFace=#Font_Face#
FontSize=(#Font_Size#)
FontColor=#Color_Scheme1#
AntiAlias=1
StringAlign=CenterCenter
X=([TrayShape:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseDownAction=["#@#ActivateTray.exe" "[TrayXPos]" "[SubSkinYPositionCalc]" "[SubSkinDirectionCalc]"]
DynamicVariables=1

[TrayXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[TrayShape:X]+[TrayShape:W]/2
DynamicVariables=1

[TrayIconDirection]
Measure=String
IfCondition=SubSkinDirectionCalc = 1
IfTrueAction=[!SetOption TrayIconDirection String ""]
IfFalseAction=[!SetOption TrayIconDirection String ""]
DynamicVariables=1
