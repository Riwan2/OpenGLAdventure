#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <vector>
#include "../Entity/entity.h"

namespace data 
{
	struct Point {
		float x, y;
		Point() : x(0), y(0)
		{}
		Point(float pX, float pY) : x(pX), y(pY) 
		{}
	};

	struct Rectangle {
		float x, y, width;
		Rectangle() : x(0), y(0), width(0)
		{}
		Rectangle(float pX, float pY, float w) : x(pX), y(pY), width(w) 
		{}
		inline bool Intersect(const Rectangle& r) const {
			return !(r.x > x + width || r.x + r.width < x || r.y > y + width || r.y + r.width < y);
		}
		inline bool Contains(const Point& p) const {
			return (p.x >= x && p.x <= x + width && p.y >= y && p.y <= y + width);
		}
	};

	struct Node {
		Point point;
		Entity* data;
		Node() : point(0, 0), data(0)
		{}
		Node(Point p, Entity* d) : point(p), data(d)
		{}
	};

	class QuadTree
	{
	public:
		QuadTree(const Rectangle& pQuad);
		~QuadTree();

		void insert(const Point& p, Entity* data);
		void querry(const Rectangle& range, std::vector<Node>& pointsInRange);
		void subdivide();
		void clear();

		std::vector<Node> dataVector;
		bool divided;
		Rectangle quad;
		QuadTree* topLeftQuad;
		QuadTree* topRightQuad;
		QuadTree* botLeftQuad;
		QuadTree* botRightQuad;
		friend std::ostream& operator << (std::ostream& os, const QuadTree& qt);
	};

	inline std::ostream& operator << (std::ostream& os, const QuadTree& qt)
	{
		os << "QuadTree : " << "x = " << qt.quad.x << " ; y = " << qt.quad.y << " ; width = " << qt.quad.width << std::endl;
		return os;
	}

}

#endif //QUADTREE_H