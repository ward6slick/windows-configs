[Variables]
StartMenu_X=0

[Metadata]
Name=Papirus\\Start Menu
Author=reddit.com/u/khanhas
Description=Click to show Windows's Start Menu

[StartMenuShape]
Meter=Shape
X=#StartMenu_X#
Y=(#Bar_OffsetY#+#Bar_Height#/2-#Section_Height#/2)
Shape=Rectangle 0,0,(#Section_Height#),(#Section_Height#) | StrokeWidth 0 | Fill Color #Color_Scheme1#
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X ([StartMenuShape:X]+#CURRENTCONFIGX#+round([StartMenuShape:X]/(#Bar_OffsetX#+#Bar_Width#))*([StartMenuShape:W]-580)) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\AppLauncher.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "AppLauncher.ini"]
;LeftMouseDownAction=["#@#nircmd.exe" sendkeypress lwin]
DynamicVariables=1

[StartMenuButton]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\appdrawer.png
W=(#Font_Size#*20/15)
X=(#Section_Height#/2 - [StartMenuButton:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2-[StartMenuButton:H]/2)
ImageTint=#Color_Scheme2#
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1
