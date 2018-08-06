#pragma once

struct point {
	double x, y;

	point (double _x, double _y) : x (_x), y (_y) 
	{}
};

struct qr_code {
	point corners [4];
	// top-left, top-right, bottom-left, bottom-right
	qr_code (point a, point b, point c, point d) : corners ({a, b, c, d})
	{}
};
