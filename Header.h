#pragma once
// Dimensions
struct Dims { 
	int x; int y; 
	int area() { return x * y; }
};

// Input struct
struct Inputs { 
	int X; int O;
	void clear() { X = -1; O = -1; };
	Inputs() { clear(); }
} inputs;