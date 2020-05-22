class Window
{
	float L, R, B, T;
	int   DIMX, DIMY;
public:
	Window(float left = -1, float right = 1, float bottom = -1, float top = 1, int DX = 400,int DY = 400)
	{
		L = left;
		R = right;
		B = bottom;
		T = top;
		DIMX = DX;
		DIMY = DY;
	}
	Window(const Window &w) {
		L = w.L;
		R = w.R;
		B = w.B;
		T = w.T;
		DIMX = w.DIMX;
		DIMY = w.DIMY;
	}
	float getl() { return L; }
	float getr() { return R; }
	float getb() { return B; }
	float gett() { return T; }
	int getDIMY() { return DIMY;  }
	int getDIMX() { return DIMX;  }
	void setl(float l) { L = l; }
	void setr(float r) { R = r; }
	void setb(float b) { B = b; }
	void sett(float t) { T = t; }
	void set_window(Window& a);
};

