[Variables]
Weather_X =526
;Left, Right or Middle
Weather_Anchor=Middle
;C or F
Weather_Unit = F

[Metadata]
Name=Papirus\\Weather
Author=reddit.com/u/khanhas
Description=Display current weather and temperature. Hover mouse on text for more information.

[WeatherAnchor]
Measure=String
String = #Weather_Anchor#
IfMatch = Middle
IfMatchAction = [!SetOption WeatherShape X "(#Bar_OffsetX#+#*Weather_X*#-([*WeatherIcon:W*]+[*Weather:W*]+10)/2)"][!SetOption WeatherIcon X "(#Bar_OffsetX#+#*Weather_X*#-([*WeatherIcon:W*]+[*Weather:W*]+10)/2)"][!SetOption Weather X 10R]
IfMatch2 = Right
IfMatchAction2 = [!SetOption WeatherIcon StringAlign RightCenter][!SetOption Weather StringAlign RightCenter][!SetOption WeatherShape X "([*Weather:X*]-[*WeatherIcon:W*]-10)"][!SetOption WeatherIcon X "([*Weather:X*]-[*WeatherIcon:W*]-10)"][!SetOption Weather X "(#Bar_OffsetX#+#*Weather_X*#)"]

[WeatherShape]
Meter=Shape
X=(#Bar_OffsetX#+#Weather_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-#Section_Height#/2)
Shape =Rectangle -20,0,([Weather:W]+[WeatherIcon:W]+10+40),#Section_Height#,5 | StrokeWidth 0 | Fill Color #Color_Scheme1#
Shape2=Rectangle 0,#Section_Height#,([Weather:W]+[WeatherIcon:W]+10),-3,1.5 | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1

[WeatherMeasure]
Measure=Plugin
Plugin=Webparser
URL=https://www.yahoo.com/news/weather
;Your location is automatically located. If it's incorrect or you want a custom place, access to https://www.yahoo.com/news/weather
;Click "Change Location", type in then choose where you want. After that, copy new webpage link and replace it with this measure URL. And refresh skin!
RegExp=(?siU)<h1 class="city.*data-reactid="7">(.*)</h1>.*<div class="My\(2px\).*60x60\/(.*)@2x.png.*data-reactid="26">(.*)<.*<span class="Va\(t\)" data-reactid="37">(.*)</span>
UpdateRate=60

[WeatherLocation]
Measure=Plugin
Plugin=Webparser
URL=[WeatherMeasure]
StringIndex=1
DynamicVariables=1
[WeatherMeasureIcon]
Measure=Plugin
Plugin=Webparser
URL=[WeatherMeasure]
StringIndex=2
DynamicVariables=1
Substitute="rain_day_night":"","scattered_showers_day_night":"","windy_day_night":"","mostly_cloudy_day_night":"","partly_cloudy_night":"","partly_cloudy_day":"","cloudy_day_night":"","snow_rain_mix_day_night":"","fair_day":"","fair_night":"","flurries_day_night":"","snow_day_night":"","thundershowers_day_night":"","fog_day_night":"","clear_day":"","clear_night":""
OnChangeAction=[!UpdateMeter WeatherIcon][!Redraw]
[WeatherDes]
Measure=Plugin
Plugin=Webparser
URL=[WeatherMeasure]
StringIndex=3
DynamicVariables=1
[WeatherTempF]
Measure=Plugin
Plugin=Webparser
URL=[WeatherMeasure]
StringIndex=4
DynamicVariables=1
[WeatherTempC]
Measure=Calc
Formula=Round((WeatherTempF-32)*5/9)

[WeatherIcon]
Meter=String
MeasureName=WeatherMeasureIcon
FontFace=Typicons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
StringAlign=LeftCenter
AntiAlias=1
X=(#Bar_OffsetX#+#Weather_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
ToolTipText=Today is [WeatherDes]#CRLF#Location: [WeatherLocation]

[Weather]
Meter=String
MeasureName=WeatherTemp#Weather_Unit#
Text=%1°#Weather_Unit#
FontFace=#Font_Face2#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
ToolTipText=Today is [WeatherDes]#CRLF#Location: [WeatherLocation]
LeftMouseUpAction=["#@#GetProcess.exe" "#PROGRAMPATH#Rainmeter.exe" "ZProcessName" "#RootConfig#"]
