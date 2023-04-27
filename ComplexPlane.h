#pragma once


using namespace sf;


class ComplexPlane
{
	const unsigned int MAX_ITER = 64;
	const float BASE_WIDTH = 4.0;
	const float BASE_HEIGHT = 4.0;
	const float BASE_ZOOM = 0.5;
public:
	ComplexPlane(float aspectRatio);
	void zoomIn();
	void zoomOut();
	void setCenter(Vector2f coord );
	void setMouseLocation(Vector2f coord);
	void loadText(Text& text);
	size_t countIterations(Vector2f coord);
	void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
	View getView();
private:
	Vector2f m_mouseLocation;
	View m_view;
	int m_zoomCount;
	float m_aspectRatio;

};
