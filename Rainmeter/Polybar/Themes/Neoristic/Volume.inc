[Variables]
Volume_X =1836
;Left, Right or Middle
Volume_Anchor=middle

[Metadata]
Name=Neoristic\\Volume
Author=reddit.com/u/khanhas
Description=Display volume, increase and decrease volume by mouse scroll, click at speaker icon to mute. Click at volume number to activate volume slider and audio device changer.

[VolumeAnchor]
Measure=String
String = #Volume_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption VolumeShape X "(#Bar_OffsetX#+#*Volume_X*#-([*VolumeIcon:W*]+[*Volume:W*]+#Section_Padding#*2)/2)"][!SetOption VolumeIcon X "(#Bar_OffsetX#+#*Volume_X*#-([*VolumeIcon:W*]+[*Volume:W*]+#Section_Padding#*2)/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption VolumeIcon StringAlign RightCenter][!SetOption Volume StringAlign RightCenter][!SetOption Volume X "(#Bar_OffsetX#+#*Volume_X*#)"][!SetOption VolumeIcon X "([*Volume:X*]-#Section_Padding#*2)"][!SetOption VolumeShape X "([*VolumeIcon:X*])"]

[VolumeShape]
Meter=Shape
X=(#Bar_OffsetX#+#Volume_X#)
Y=(#Bar_OffsetY#)
Shape =Rectangle -#Section_Padding#,0,([Volume:W]+[VolumeIcon:W]+#Section_Padding#*4),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme3#
Shape2=Rectangle -#Section_Padding#,0,([VolumeIcon:W]+#Section_Padding#*2),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme1#
DynamicVariables=1
Group=Volume

[VolumeLevel]
Measure=Plugin
Plugin=Win7AudioPlugin
Group=Volume

[VolumeLevelCalc]  
Measure=Calc
Formula=VolumeLevel <= 0 ? 0 : VolumeLevel
IfCondition=VolumeLevelCalc = 0
IfTrueAction=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition2=(VolumeLevelCalc <= 50) && (VolumeLevelCalc > 0)
IfTrueAction2=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition3=VolumeLevelCalc > 50 
IfTrueAction3=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
Group = Volume

[VolumeIcon]
Meter=String
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme4#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Volume_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure VolumeLevel "ToggleMute"][!UpdateMeasureGroup Volume]
Group=Volume
DynamicVariables=1

[Volume]
Meter=String
MeasureName=VolumeLevelCalc
Postfix=%
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
X=(#Section_Padding#*2)R
Y=r
MouseScrollDownAction=[!CommandMeasure VolumeLevel "ChangeVolume -5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!UpdateMeter VolumeShape][!Redraw]
MouseScrollUpAction  =[!CommandMeasure VolumeLevel "ChangeVolume +5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!UpdateMeter VolumeShape][!Redraw]
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X ([Volume:X]+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!DeactivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts"][!ToggleConfig "Polybar\Themes\#Theme#\Additional_Comps_And_Scripts" "VolumeControl.ini"]
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
DynamicVariables=1
Group=Volume
