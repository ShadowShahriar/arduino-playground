/*
 * === QuickUnique.h ===
 * @version 0.0.1
 * @author S. Shahriar
 * @date 2026-08-26
 * @license MIT
 * @copyright 2026 S. Shahriar <hi@shadowshahriar.dev>
 */

#ifndef QUICKUNIQUE_H
#define QUICKUNIQUE_H

#include <Arduino.h>
class QuickUnique
{
private:
	int _minVal;
	int _maxVal;
	int _lastNum;

public:
	QuickUnique(int minVal, int maxVal);
	int next();
	void setRange(int minVal, int maxVal);
};
#endif