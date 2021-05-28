#pragma once
#include <string>
class Debug
{
public:
	static void Out(const char* str);
	static void Out(const wchar_t* str);
	static void Out(const std::string& str);
	static void Out(const std::wstring& str);
	static void OutLine(const char* str);
	static void OutLine(const wchar_t* str);
	static void OutLine(const std::string& str);
	static void OutLine(const std::wstring& str);

	static void Out(int val);
	static void Out(float val);
};

extern int test;

struct Vector2 {
	float x, y;
};
using Position2 = Vector2;
inline Vector2 operator+(const Vector2& lval, const Vector2& rval) {
	Vector2 ret = { lval.x+rval.x,lval.y+ rval.y};
	return ret;
}
