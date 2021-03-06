[Variables]
date_x=1813
;Left, Right or Center
Date_Anchor=Right

[Metadata]
Name=Neoristic\\Date
Author=reddit.com/u/khanhas
Description=Display date. Click to activate Calendar View with Google Calendar and Microsoft Outlook support.

[DateAnchor]
Measure=String
String = #Date_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption DateShape X "(#Bar_OffsetX#+#*Date_X*#-([*DateIcon:W*]+[*Date:W*]+#Section_Padding#*2)/2)"][!SetOption DateIcon X "(#Bar_OffsetX#+#*Date_X*#-([*DateIcon:W*]+[*Date:W*]+#Section_Padding#*2)/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption DateIcon StringAlign RightCenter][!SetOption Date StringAlign RightCenter][!SetOption Date X "(#Bar_OffsetX#+#*Date_X*#)"][!SetOption DateIcon X "([*Date:X*]-#Section_Padding#*2)"][!SetOption DateShape X "([*DateIcon:X*])"]

[DateShape]
Meter=Shape
X=(#Bar_OffsetX#+#Date_X#)
Y=(#Bar_OffsetY#)
Shape =Rectangle -#Section_Padding#,0,([Date:W]+[DateIcon:W]+#Section_Padding#*4),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme1#
Shape2=Rectangle -#Section_Padding#,0,([DateIcon:W]+#Section_Padding#*2),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1

[DateParseSchedule]
Measure=Script
ScriptFile=#@#Scripts\Calendar_Common_Script.lua

[DateScheduleFetch]
Measure=Plugin
Plugin=WebParser
URL=
Download=1
DownloadFile=calendarSchedule.txt
Debug=1
FinishAction=[!CommandMeasure DateParseSchedule "moduleNotification = true; notificationMeter = 'DateNotification'; parseSchedule()"]
UpdateRate=1000

[MeasureDate] %b 
Measure=Time
Format=%a %#d

[DateIcon]
Meter=String
Text=dte
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme4#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Date_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure DateLevel "ToggleMute"][!UpdateMeasureGroup Date]
Group=Date
DynamicVariables=1

[Date]
Meter=String
MeasureName=MeasureDate
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Section_Padding#*2)R
Y=r
LeftMouseUpAction=[!WriteKeyValue Variables Curr_X ([DateIcon:X]+([DateIcon:W]+[Date:W]+10)/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "CalendarView.ini"]
DynamicVariables=1

[DateNotification]
Meter=Shape
X=([DateIcon:X]+[DateIcon:W])
Y=(#Bar_OffsetY#+#Bar_Height#/2+#Font_Size#*8/14)
Shape=Ellipse 0,0,4 | StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1
Hidden=1
