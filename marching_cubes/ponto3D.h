class Ponto3D
{
    private:
    float x, y, z;

    public:

    Ponto3D(float x1, float y1, float z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

	Ponto3D operator+(const Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2);
	Ponto3D operator-(const Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2);
	Ponto3D operator*(const Ponto3D& pt3dPoint, float fScale);
	Ponto3D operator*(float fScale, const Ponto3D& pt3dPoint);
	Ponto3D operator/(const Ponto3D& pt3dPoint, float fScale);
	Ponto3D& operator*=(Ponto3D& pt3dPoint, float fScale);
	Ponto3D& operator/=(Ponto3D& pt3dPoint, float fScale);
	Ponto3D& operator+=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2);
	Ponto3D& operator-=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2);
    Ponto3D& operator=(Ponto3D& pt3dPoint1, const Ponto3D& pt3dPoint2);
    float get_x(void);
    float get_y(void);
    float get_z(void);

}