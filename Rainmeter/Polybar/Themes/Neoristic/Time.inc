[Variables]
Time_X =1884
;Left, Right or Middle
Time_Anchor =middle

[Metadata]
Name=Papirus\\Time
Author=reddit.com/u/khanhas
Description=Display time.

[TimeAnchor]
Measure=String
String = #Time_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption TimeShape X "(#Bar_OffsetX#+#*Time_X*#-([*TimeIcon:W*]+[*Time:W*]+#Section_Padding#*2)/2)"][!SetOption TimeIcon X "(#Bar_OffsetX#+#*Time_X*#-([*TimeIcon:W*]+[*Time:W*]+#Section_Padding#*2)/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption TimeIcon StringAlign RightCenter][!SetOption Time StringAlign RightCenter][!SetOption Time X "(#Bar_OffsetX#+#*Time_X*#)"][!SetOption TimeIcon X "([*Time:X*]-#Section_Padding#*2)"][!SetOption TimeShape X "([*TimeIcon:X*])"]

[TimeShape]
Meter=Shape
X=(#Bar_OffsetX#+#Time_X#)
Y=(#Bar_OffsetY#)
Shape =Rectangle -#Section_Padding#,0,([Time:W]+[TimeIcon:W]+#Section_Padding#*4),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme3#
Shape2=Rectangle -#Section_Padding#,0,([TimeIcon:W]+#Section_Padding#*2),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme1#
DynamicVariables=1

[MeasureTime]
Measure=Time
Format=%I:%M

[TimeIcon]
Meter=String
Text=
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme4#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Time_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure VolumeLevel "ToggleMute"][!UpdateMeasureGroup Volume]
Group=Volume
DynamicVariables=1

[Time]
Meter=String
MeasureName=MeasureTime
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Section_Padding#*2)R
Y=r
LeftMouseUpAction=[!WriteKeyValue Variables Curr_X ([DateIcon:X]+([DateIcon:W]+[Date:W]+10)/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "CalendarView.ini"]
;RightMouseUpAction=[explorer.exe shell:appsFolder\Microsoft.WindowsAlarms_8wekyb3d8bbwe!App]
DynamicVariables=2
