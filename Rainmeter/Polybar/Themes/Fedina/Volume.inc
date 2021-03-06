[Variables]
Volume_X =1848
;Left, Right or Center
Volume_Anchor=right
Volume_Width=(#Font_Size#*6)

[Metadata]
Name=Fedina\\Volume
Author=reddit.com/u/khanhas
Description=Display volume, increase and decrease volume by mouse scroll, click at speaker icon to mute. Click at volume number to activate volume slider and audio device changer.

[VolumeAnchor]
Measure=String
String = #Volume_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption VolumeShape X "(#Bar_OffsetX#+#*Volume_X*#-#Volume_Width#/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption VolumeShape X "(#Bar_OffsetX#+#*Volume_X*#-#Volume_Width#)"]

[VolumeShape]
Meter=Shape
X=(#Bar_OffsetX#+#Volume_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,#Volume_Width#,#Bar_Height# | StrokeWidth 0 | Extend Color
Color = Fill Color [ColorMeasureScript:GetColor('#Color_Scheme3#', '#Color_Scheme4#', 'side to middle', 'Volume_X')]
DynamicVariables=1

[VolumeLevel]
Measure=Plugin
Plugin=Win7AudioPlugin
Group = Volume

[VolumeLevelCalc]  
Measure=Calc
Formula=VolumeLevel <= 0 ? 0 : VolumeLevel
IfCondition=VolumeLevelCalc = 0
IfTrueAction=[!SetOption VolumeIcon Text " "][!UpdateMeterGroup Volume][!Redraw]
IfCondition2=(VolumeLevelCalc <= 50) && (VolumeLevelCalc > 0)
IfTrueAction2=[!SetOption VolumeIcon Text " "][!UpdateMeterGroup Volume][!Redraw]
IfCondition3=VolumeLevelCalc > 50
IfTrueAction3=[!SetOption VolumeIcon Text " "][!UpdateMeterGroup Volume][!Redraw]
Group = Volume

[VolumeIcon]
Meter=String
FontFace=Typicons
FontSize=(#Font_Size#*16/14)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=([VolumeShape:X] + [VolumeShape:W]/2 - ([VolumeIcon:W] + [Volume:W] + 5)/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure VolumeLevel "ToggleMute"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
Group=Volume
DynamicVariables=1

[Volume]
Meter=String
MeasureName=VolumeLevelCalc
Postfix=%
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=5R
Y=r
MouseScrollDownAction=[!CommandMeasure VolumeLevel "ChangeVolume -5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
MouseScrollUpAction  =[!CommandMeasure VolumeLevel "ChangeVolume +5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X (#Volume_X#+([Volume:X]+[Volume:H]-#Volume_X#)/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "VolumeControl.ini"]
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
DynamicVariables=1
SolidColor=0,0,0,1
Group=Volume
RightMouseUpAction=["sndvol.exe"]
