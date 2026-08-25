/*
 * === QuickUnique.cpp ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#include "QuickUnique.h"

QuickUnique::QuickUnique(int minVal, int maxVal)
{
	_minVal = minVal;
	_maxVal = maxVal;
	_lastNum = minVal - 1;
}

int QuickUnique::next()
{
	int newNum;
	do
	{
		newNum = random(_minVal, _maxVal + 1);
	} while (newNum == _lastNum);
	_lastNum = newNum;
	return newNum;
}

void QuickUnique::setRange(int minVal, int maxVal)
{
	_minVal = minVal;
	_maxVal = maxVal;
	_lastNum = minVal - 1;
}