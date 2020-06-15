class Ponto3D
{
    public:

    float x, y, z;



    Ponto3D(float x1 = 0, float y1 = 0, float z1 = 0)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Ponto3D operator+(const Ponto3D& pt3dPoint);
	Ponto3D operator-(const Ponto3D& pt3dPoint);
	Ponto3D operator*(float fScale);
	Ponto3D operator/(float fScale);
	void operator*=(float fScale);
	void operator/=(float fScale);
	void operator+=(const Ponto3D& pt3dPoint);
	void operator-=(const Ponto3D& pt3dPoint);
    void operator=(const Ponto3D& pt3dPoint);

    //float get_x(void);
    //float get_y(void);
    //float get_z(void);

};