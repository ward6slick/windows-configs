function Initialize()
	dofile(SKIN:GetVariable('@')..'Scripts\\Calendar_Common_Script.lua')

	GetEssentialVariables()
	cur_Year, cur_Month, cur_Day, cur_Wday = GetDate('t') --Get today Year, Month, Day and Wday index (0 to 6)

	GetWeekDayLabel()
	parseSchedule()
	--drawDay: Set position for all days in given year, month. Last parameter is for execute resetShapeAndMeter() function (true) or do not execute it (false).
	drawDay(cur_Year,cur_Month, false)
end

function SetMonthAndYear()
	SKIN:Bang('!SetOption', 'MonthName', 'Text', GetDate('%B ', cur_Year, cur_Month, cur_Day)) --Set long Month name
	SKIN:Bang('!SetOption', 'YearNum', 'Text', GetDate('‮ ‬%d', cur_Year, cur_Month, cur_Day)) --Set full Year number
end

--DrawingToday function is used for drawing today indicator.
--	dayXPos: Position X of currently drawing day
--	dayYPos: Position Y of currently drawing day
--If theme doesn't need it, leave it blank, do not remove it.
function DrawingToday(dayXPos, dayYPos)
	SKIN:Bang('!SetOption', 'CalendarViewShape', 'Shape4', 'Rectangle '..dayXPos..','..dayYPos..',40,40 | Extend CurrentDayTrait') 
end

--DrawingScheduledDays function is used for drawing available event of currently drawing day.
--	dayXPos: Position X of currently drawing day
--	dayYPos: Position Y of currently drawing day
--	totalEvent: number of events of currently drawing day
--shapeCount starts at 2
--If theme doesn't need it, leave it blank, do not remove it.
function DrawingScheduledDays(dayXPos, dayYPos, totalEvent)
	SKIN:Bang('!SetOption', 'ScheduleShape', 'Shape'..shapeCount, 'Ellipse '..dayXPos..',('..dayYPos..'+12),1.5 | Extend EventTrait')
	shapeCount = shapeCount + 1
end

--EventTextFormat function is used for formatting event 
--	eventMeta: table of event which has 
--		sum: event summary, title
--		time.hour: event start hour
--		time.minute: event start minute
--		location: event location
--	final (boolean): is currently formatting event last event.
function EventTextFormat(eventMeta, final)
	local returnSummary = ''
	local returnTime = ''
	local returnLocation = ''
	local eventSepartor = ''

	if eventMeta.sum == '' then
		returnSummary = 'N/A'
	else
		returnSummary = eventMeta.sum 
	end

	if eventMeta.time.hour ~= 'null' then
		returnTime = ' ' .. eventMeta.time.hour .. ':' ..eventMeta.time.minute .. '	' --Weird character here is clock icon in FontAwesome font
	end

	if eventMeta.location ~= '' then
		returnLocation = ' '..eventMeta.location --Weird character here is pin icon in FontAwesome font
	end

	if not final then
		eventSeparator = '#CRLF##CRLF#'
	else
		eventSeparator = '#CRLF#'
	end

	return returnSummary .. '#CRLF#' .. returnTime .. returnLocation .. eventSeparator
end

--ClickEvent function is used for execute actions when user click at event available day.
--	meter: name of meter user just click
function ClickEvent(meter)
	local meterXPos = SKIN:GetMeter(meter):GetOption('X')
	local meterYPos = SKIN:GetMeter(meter):GetOption('Y')
	local text = SKIN:GetMeter(meter):GetOption('EventText')

	--Draw clicked day indicator shape
	SKIN:Bang('!SetOption', 'CalendarViewShape', 'Shape5', 'Rectangle '..meterXPos..','..meterYPos..',40,40 | Extend ChoosingDayTrait')
	
	--Set full list of events
	SKIN:Bang('!SetOption', 'EventText', 'Text', text)
	SKIN:Bang('!Update')
end

--resetShapeAndMeter function is used for clear every indicators shapes drawed, EventText meter and hide all day meters
function resetShapeAndMeter()
	SKIN:Bang('!SetOption', 'CalendarViewShape', 'Shape3', 'Ellipse 0,0,0')
	SKIN:Bang('!SetOption', 'CalendarViewShape', 'Shape4', 'Ellipse 0,0,0')
	SKIN:Bang('!SetOption', 'CalendarViewShape', 'Shape5', 'Ellipse 0,0,0')

	SKIN:Bang('!SetOption', 'EventText', 'Text', '')

	SKIN:Bang('!HideMeterGroup', 'Day')

	if not shapeCount then return end
	for i = 2, shapeCount do
		SKIN:Bang('!SetOption', 'ScheduleShape', 'Shape'..i, '')
	end
end

