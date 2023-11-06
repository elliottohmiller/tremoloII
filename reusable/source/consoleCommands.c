// ConsoleCommands.c
// This is where you add commands:
//		1. Add a protoype
//			static eCommandResult_T ConsoleCommandVer(const char buffer[]);
//		2. Add the command to mConsoleCommandTable
//		    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
//		3. Implement the function, using ConsoleReceiveParam<Type> to get the parameters from the buffer.

#include <string.h>
#include "consoleCommands.h"
#include "console.h"
#include "consoleIo.h"
#include "version.h"

#define IGNORE_UNUSED_VARIABLE(x)     if ( &x == &x ) {}

static eCommandResult_T ConsoleCommandComment(const char buffer[]);
static eCommandResult_T ConsoleCommandVer(const char buffer[]);
static eCommandResult_T ConsoleCommandHelp(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[]);
//user defined commands
static eCommandResult_T ConsoleCommandDepth(const char buffer[]);
static eCommandResult_T ConsoleCommandRate(const char buffer[]);
static eCommandResult_T ConsoleCommandShape(const char buffer[]);
static eCommandResult_T ConsoleCommandLEDMode(const char buffer[]);

static const sConsoleCommandTable_T mConsoleCommandTable[] =
{
    {";", &ConsoleCommandComment, HELP("Comment! You do need a space after the semicolon. ")},
    {"help", &ConsoleCommandHelp, HELP("Lists the commands available")},
    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
    {"int", &ConsoleCommandParamExampleInt16, HELP("How to get a signed int16 from params list: int -321")},
    {"u16h", &ConsoleCommandParamExampleHexUint16, HELP("How to get a hex u16 from the params list: u16h aB12")},
	//user additions
    {"depth", &ConsoleCommandDepth, HELP("Set the depth parameter 0:100")},
    {"rate", &ConsoleCommandRate, HELP("Set the rate parameter 1:10")},
    {"shape", &ConsoleCommandShape, HELP("Set the shape parameter 1:5")},
    {"led", &ConsoleCommandLEDMode, HELP("Set the LED display mode: \"depth,\" \"rate,\" \"shape,\" \"pwm\"")},

	CONSOLE_COMMAND_TABLE_END // must be LAST
};

static eCommandResult_T ConsoleCommandComment(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandHelp(const char buffer[])
{
	uint32_t i;
	uint32_t tableLength;
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	tableLength = sizeof(mConsoleCommandTable) / sizeof(mConsoleCommandTable[0]);
	for ( i = 0u ; i < tableLength - 1u ; i++ )
	{
		ConsoleIoSendString(mConsoleCommandTable[i].name);
#if CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(" : ");
		ConsoleIoSendString(mConsoleCommandTable[i].help);
#endif // CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[])
{
	int16_t parameterInt;
	eCommandResult_T result;
	result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is ");
		ConsoleSendParamInt16(parameterInt);
		ConsoleIoSendString(" (0x");
		ConsoleSendParamHexUint16((uint16_t)parameterInt);
		ConsoleIoSendString(")");
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandVer(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString(VERSION_STRING);
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}

//user command functions
static eCommandResult_T ConsoleCommandDepth(const char buffer[])
{

		int16_t parameterInt;
		eCommandResult_T result;
		result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
		if ( COMMAND_SUCCESS == result )
		{
			ConsoleIoSendString("Parameter is ");
			ConsoleSendParamInt16(parameterInt);
			ConsoleIoSendString(" (0x");
			ConsoleSendParamHexUint16((uint16_t)parameterInt);
			ConsoleIoSendString(")");
			ConsoleIoSendString(STR_ENDLINE);
		}

		/*
		 * set depth param
		 */

		return result;

}

static eCommandResult_T ConsoleCommandRate(const char buffer[])
{

		int16_t parameterInt;
		eCommandResult_T result;
		result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
		if ( COMMAND_SUCCESS == result )
		{
			ConsoleIoSendString("Parameter is ");
			ConsoleSendParamInt16(parameterInt);
			ConsoleIoSendString(" (0x");
			ConsoleSendParamHexUint16((uint16_t)parameterInt);
			ConsoleIoSendString(")");
			ConsoleIoSendString(STR_ENDLINE);
		}

		/*
		 * set rate param
		 */

		return result;

}

static eCommandResult_T ConsoleCommandShape(const char buffer[])
{

		int16_t parameterInt;
		eCommandResult_T result;
		result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
		if ( COMMAND_SUCCESS == result )
		{
			ConsoleIoSendString("Parameter is ");
			ConsoleSendParamInt16(parameterInt);
			ConsoleIoSendString(" (0x");
			ConsoleSendParamHexUint16((uint16_t)parameterInt);
			ConsoleIoSendString(")");
			ConsoleIoSendString(STR_ENDLINE);
		}

		/*
		 * set shape param
		 */

		return result;

}

static eCommandResult_T ConsoleCommandLEDMode(const char buffer[])
{

		ledMode parameterLED;
		eCommandResult_T result;
		result = LEDModeParam(buffer, 1, &parameterLED);
		if ( COMMAND_SUCCESS == result )
		{
			ConsoleIoSendString("Parameter is ");
			ConsoleSendParamInt16((uint16_t)parameterLED);
			ConsoleIoSendString(" (0x");
			ConsoleSendParamHexUint16((uint16_t)parameterLED);
			ConsoleIoSendString(")");
			ConsoleIoSendString(STR_ENDLINE);
		}

		/*
		 * flash leds according to ledMode
		 */

		return result;

}


const sConsoleCommandTable_T* ConsoleCommandsGetTable(void)
{
	return (mConsoleCommandTable);
}


