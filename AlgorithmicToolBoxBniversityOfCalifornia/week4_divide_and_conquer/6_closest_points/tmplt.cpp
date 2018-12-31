#include<bits/stdc++.h>
using namespace std;

 
struct Point {
	int x, y;
 
	double Distance(const Point &p) {
		auto dx = this->x - p.x, dy = this->y - p.y;
		return std::sqrt(dx * dx + dy * dy);
	}
};
 
typedef std::vector<Point> Points;
 
double closest_strip(Points strip, double d = std::numeric_limits<double>::max()) {
	auto min = d;
 
	for (auto i = strip.begin(); i != strip.end(); ++i)
		for (auto j = i + 1; j != strip.end() && j->y - i->y < min; ++j)
			min = std::min(min, i->Distance(*j));
 
	return min;
}
 
double closest_sorted(Points px, Points py) {
	if (px.size() <= 3)
		return closest_strip(px);
 
	auto mid = px.size() / 2;
	std::vector<Point> pyl, pyr;
 
	for (auto p : px) {
		if (p.x <= px[mid].x) pyl.push_back(p);
		else pyr.push_back(p);
	}
 
	Points pxl = Points(px.begin(), px.begin() + mid);
	Points pxr = Points(px.begin() + mid + 1, px.end());
 
	auto dl = closest_sorted(pxl, pyl);
	auto dr = closest_sorted(pxr, pyr);
	auto dlr = std::min(dl, dr);
 
	Points strip;
	for (auto p : pyr) 
		if (p.x - px[mid].x < dlr) strip.push_back(p);
 
	return std::min(dlr, closest_strip(strip, dlr));
}
 
double closest(Points p) {
	Points px = p, py = p;
 
	std::sort(px.begin(), px.end(), [](Point p1, Point p2) { return p1.x < p2.x; });
	std::sort(py.begin(), py.end(), [](Point p1, Point p2) { return p1.y < p2.y; });
 
	return closest_sorted(px, py);
}
 
int main() {
	int  n;
	cin>>n;
	Points points(n);
	for(int i=0;i<n;i++)
	cin>>points[i].x>>points[i].y;
	std::cout <<setprecision(9)<< closest(points);
 
	return 0;
}