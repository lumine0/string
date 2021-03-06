#pragma once

#include "Array.h"
#include <iostream>
#include <functional>
using namespace std;

class String
{
	typedef function<bool(char)> Condition;
	typedef function<bool(char, char)> Comparison;
	Array<char> str;
	int length;
	void Sorting(int bot, int top, Comparison);
public:
	explicit String(int capacity = 80) : str(capacity > 10 ? capacity : 10), length(0) {};
	String(char* origin);
	String(const String &that) :str(that.str), length(that.length){};
	String(String&& that) :str(move(that.str)), length(that.length){};
	String(char* origin, int capacity);
	String(String &that, int capacity);

	int Length() const;
	int Capacity();

	operator char*() const;
	explicit operator int() const;
	explicit operator double() const;

	String& operator =(const String &that);
	String& operator =(String &&that);
	String& operator =(char* string);
	String& operator +=(char* string);
	String& operator +=(const String &that);
	String& operator +=(char c);

	bool operator >(const String &that);
	bool operator >=(const String &that);
	bool operator <(const String &that);
	bool operator <=(const String &that);
	bool operator ==(const String &that);
	bool operator !=(const String &that);

	int CompareTo(String that) const;
	int CompareTo(char* that) const;
	static int Compare(const String &str1, const String &str2);
	static int Compare(const String &str1, char* str2);
	static int Compare(char* str1, const String &str2);

	String operator +(const String &that);
	String operator +(char* that);
	String operator +(char c);

	String& Concat(String that);
	String& Concat(char*);
	String& Concat(int);
	String& Concat(double);
	String& Concat(String* strArray, int count);
	String& Concat(Array<String> strArray);
	String& Concat(Array<String> strArray, int count);

	char operator [](int index);

	bool Contains(const String &that, int startPos=0, int endPos=0) const;
	bool StartsWith(const String &that) const;
	bool EndsWith(const String &that) const;

	int IndexOf(char c, int startPos = 0) const;
	int IndexOf(const String &that) const;
	int LastIndexOf(char c) const;
	int LastIndexOf(const String &that) const;
	int IndexOfAny(const String &that) const;
	int IndexWhere(Condition f) const;

	String Take(int num);
	String Drop(int num);
	String TakeRight(int num);
	String DropRight(int num);
	String TakeWhile(Condition f);
	String DropWhile(Condition f);
	String TakeRightWhile(Condition f);
	String DropRightWhile(Condition f);

	String& Remove(int from, int count);
	String& Insert(const String &that, int pos);
	String& Replace(char from, char to);
	String& Replace(String from, String to);
	String& Clear();

	String PadLeft(int count, char c = ' ');
	String PadRight(int count, char c = ' ');

	Array<String> Split(char sep);

	String TrimEnd();
	String TrimStart();
	String Trim();
	String Normalize();

	template <typename T>
	Array<T> Map(function<T(char)>);
	String Map(function<char(char)>);

	String ToLower();
	String ToUpper();

	void CopyTo(String &that);

	String Reverse();
	String Shuffle();
	String SortBy(Comparison);
	String SortAZ();
	String SortZA();
};

ostream& operator<<(ostream& os, const String &string);
istream& operator>>(istream& is, String &string);
String operator+(char* str1, String str2);
String operator+(char c, String string);


