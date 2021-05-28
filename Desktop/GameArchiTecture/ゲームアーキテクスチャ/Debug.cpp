#include "Debug.h"
#include <debugapi.h>

int test = 4;
inline Vector2 operator+(const Vector2& lval, const Vector2& rval) {
	Vector2 ret = { lval.x + rval.x,lval.y + rval.y };
	return ret;
}

void Debug::Out(const char* str)
{
	OutputDebugStringA(str);
}

void Debug::Out(const wchar_t* str)
{
	OutputDebugStringW(str);
}

void Debug::Out(const std::string& str)
{
	Out(str.c_str());
}

void Debug::Out(const std::wstring& str)
{
	Out(str.c_str());
}

void Debug::OutLine(const char* str)
{
	//OutLine(str.c_str());
}

void Debug::OutLine(const wchar_t* str)
{
	//OutLine(str.c_str());
}

void Debug::OutLine(const std::string& str)
{
	OutLine(str.c_str());
}

void Debug::OutLine(const std::wstring& str)
{
	OutLine(str.c_str());
}

void Debug::Out(int val)
{
	/*std::ostringstream oss;
	oss << val;
	Out();*/
}

void Debug::Out(float val)
{
}

