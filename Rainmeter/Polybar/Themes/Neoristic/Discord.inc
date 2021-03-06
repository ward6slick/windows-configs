[Variables]
Discord_X=1461

[Metadata]
Name=Papirus\\Discord
Author=reddit.com/u/khanhas
Description=Click to show Discord status and control

[DiscordShape]
Meter=Shape
X=#Discord_X#
Y=(#Bar_OffsetY#)
Shape=Rectangle 0,0,(#Bar_Height#),(#Bar_Height#) | StrokeWidth 0 | Fill Color #Color_Scheme1#
DynamicVariables=1
MouseOverAction=[!WriteKeyValue Variables "Curr_X" "(#CURRENTCONFIGX#+[DiscordIcon:X]+[DiscordIcon:W]/2)" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "DiscordStatus.ini"][!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["discord://"]

[DiscordIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Discord.png
W=(#Font_Size#*20/14)
X=(#Discord_X#+#Bar_Height#/2-[DiscordIcon:W]/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[DiscordIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1

[Discord_BadgeShape]
Meter=Shape
Shape=Rectangle ([Discord_UnreadCountBadge:X]-#Font_Size#*2/3),([Discord_UnreadCountBadge:Y]-#Font_Size#/3),([Discord_UnreadCountBadge:W]+#Font_Size#*sgn([Discord_UnreadCountBadge:W])),([Discord_UnreadCountBadge:H]+#Font_Size#/3*sgn([Discord_UnreadCountBadge:W])) | StrokeWidth 0 | Fill Color #Color_Scheme4#
DynamicVariables=1

[Discord_UnreadCountBadge]
Meter=String
MeasureName=DiscordNotice
FontFace=#Font_Face2#
FontSize=(#Font_Size#*12/9)
FontColor=#Color_Scheme2#
X=(#Discord_X#+#Bar_Height#-#Font_Size#/3)
StringAlign=RightBottom
Y=(#Bar_OffsetY#+#Bar_Height#)
AntiAlias=1
DynamicVariables=1

[DiscordScript]
Measure=Script
ScriptFile=#@#Scripts\Discord_Common_Script.lua
JSONFile = %appdata%\BetterDiscord\plugins\DiscordForRainmeter.config.json

[DiscordNotice]
Measure=Calc
Formula=[DiscordScript:GetNotification(true,true,true)]
IfCondition=DiscordNotice > 0 
IfTrueAction=[!ShowMeter Discord_UnreadCountBadge][!SetOption DiscordIcon ImageTint "#Color_Scheme2#"]
IfFalseAction=[!HideMeter Discord_UnreadCountBadge][!SetOption DiscordIcon ImageTint "#Color_Scheme4#"]
DynamicVariables=1
