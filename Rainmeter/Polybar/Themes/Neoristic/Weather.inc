[Variables]
Weather_X =1618
;Left, Right or Middle
Weather_Anchor=right
;C or F
Weather_Unit = F

[Metadata]
Name=Papirus\\Weather
Author=reddit.com/u/khanhas
Description=Display current weather and temperature. Hover mouse on text for more information.

[WeatherAnchor]
Measure=String
String = #Weather_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption WeatherShape X "(#Bar_OffsetX#+#*Weather_X*#-([*WeatherIcon:W*]+[*Weather:W*]+#Section_Padding#*2)/2)"][!SetOption WeatherIcon X "(#Bar_OffsetX#+#*Weather_X*#-([*WeatherIcon:W*]+[*Weather:W*]+#Section_Padding#*2)/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption WeatherIcon StringAlign RightCenter][!SetOption Weather StringAlign RightCenter][!SetOption Weather X "(#Bar_OffsetX#+#*Weather_X*#)"][!SetOption WeatherIcon X "([*Weather:X*]-#Section_Padding#*2)"][!SetOption WeatherShape X "([*WeatherIcon:X*])"]

[WeatherShape]
Meter=Shape
X=(#Bar_OffsetX#+#Weather_X#)
Y=(#Bar_OffsetY#)
Shape =Rectangle -#Section_Padding#,0,([Weather:W]+[WeatherIcon:W]+#Section_Padding#*4),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme1#
Shape2=Rectangle -#Section_Padding#,0,([WeatherIcon:W]+#Section_Padding#*2),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1
Group=Weather

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
Measure=String
String=thundershowers_day_night
;Measure=Plugin
;Plugin=Webparser
;URL=[WeatherMeasure]               
;StringIndex=2
;DynamicVariables=1
Substitute="rain_day_night":"wthr","scattered_showers_day_night":"wthr","windy_day_night":"wthr","mostly_cloudy_day_night":"wthr","partly_cloudy_night":"wthr","partly_cloudy_day":"wthr","cloudy_day_night":"wthr","snow_rain_mix_day_night":"wthr","fair_day":"wthr","fair_night":"wthr","flurries_day_night":"wthr","snow_day_night":"wthr","thundershowers_day_night":"wthr","fog_day_night":"wthr","clear_day":"wthr","clear_night":"wthr"
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
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme4#
SolidColor=0,0,0,1

StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Weather_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1
ToolTipText=Today is [WeatherDes]#CRLF#Location: [WeatherLocation]

[Weather]
Meter=String
MeasureName=WeatherTemp#Weather_Unit#
Text=%1°#Weather_Unit#
FontFace=#Font_Face1#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Section_Padding#*2)R
Y=(#Section_Padding#*-0.3)r
DynamicVariables=1
ToolTipText=Today is [WeatherDes]#CRLF#Location: [WeatherLocation]
