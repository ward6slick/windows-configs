[Variables]
date_x=1454
;Left, Right or Center
Date_Anchor=Right
Date_Width=(#Font_Size#*11)

[Metadata]
Name=Fedina\\Date
Author=reddit.com/u/khanhas
Description=Display date. Click to activate Calendar View with Google Calendar and Microsoft Outlook support.

[DateAnchor]
Measure=String
String = #Date_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption DateShape X "(#Bar_OffsetX#+#*Date_X*#-#Date_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption DateShape X "(#Bar_OffsetX#+#*Date_X*#-#Date_Width#)"]

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

[DateShape]
Meter=Shape
X=(#Bar_OffsetX#+#Date_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Date_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', 'Date_X')]
DynamicVariables=1

[MeasureDate] %#d %b
Measure=Time
Format=%A

[DateIcon]
Meter=String
Text=
FontFace=Typicons
FontSize=(#Font_Size#*16/14)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=([DateShape:X] + [DateShape:W]/2 - ([DateIcon:W] + [Date:W] + 5)/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Date]
Meter=String
MeasureName=MeasureDate
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=5R
Y=r
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Curr_X ([DateIcon:X]+([DateIcon:W]+[Date:W]+10)/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "CalendarView.ini"]

[DateNotification]
Meter=Shape
X=([DateIcon:X]+[DateIcon:W])
Y=(#Bar_OffsetY#+#Bar_Height#/2+#Font_Size#*8/14)
Shape=Ellipse 0,0,4 | StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1
Hidden=1
