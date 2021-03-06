[Variables]
StartMenu_X=128
;Left, Right or Center
StartMenu_Anchor=left
StartMenu_Width=(#Font_Size#*4)

[Metadata]
Name=Paper\\Start Menu
Author=reddit.com/u/khanhas
Description=Click to show Windows's Start Menu

[StartMenuAnchor]
Measure=String
String = #StartMenu_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption StartMenuShape X "(#Bar_OffsetX#+#*StartMenu_X*#-#StartMenu_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption StartMenuShape X "(#Bar_OffsetX#+#*StartMenu_X*#-#StartMenu_Width#)"]

[StartMenuShape]
Meter=Shape
X=(#Bar_OffsetX#+#StartMenu_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#StartMenu_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', 'StartMenu_X')]
DynamicVariables=1

[StartMenuButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=(#StartMenu_Width#/2)r
Y=(#Bar_Height#/2)r
SolidColor=00000001
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X ([StartMenuShape:X]+#CURRENTCONFIGX#+round([StartMenuShape:X]/(#Bar_OffsetX#+#Bar_Width#))*([StartMenuShape:W]-580)) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "AppLauncher.ini"]
;LeftMouseDownAction=["#@#nircmd.exe" sendkeypress lwin]
DynamicVariables=1
