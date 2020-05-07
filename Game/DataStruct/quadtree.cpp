#include "quadtree.h"

const float MAX_CAPACITY = 4;

data::QuadTree::QuadTree(const Rectangle& pQuad)
{
	quad = pQuad;
	dataVector.shrink_to_fit();
	divided = false;
}

data::QuadTree::~QuadTree()
{
	dataVector.clear();
	dataVector.shrink_to_fit();

	if (divided) {
		delete topLeftQuad;
		delete topRightQuad;
		delete botLeftQuad;
		delete botRightQuad;
		divided = false;
	}
}

void data::QuadTree::clear()
{
	dataVector.clear();
	dataVector.shrink_to_fit();

	if (divided) {
		delete topLeftQuad;
		delete topRightQuad;
		delete botLeftQuad;
		delete botRightQuad;
		divided = false;
	}
}

void data::QuadTree::querry(const Rectangle &range, std::vector<Node>& pointsInRange)
{
	if (!quad.Intersect(range)) return;

	for (int i = 0; i < dataVector.size(); i++) {
		Node p = dataVector[i];
		if (range.Contains(p.point))
		pointsInRange.push_back(p);
	}

	if (!divided) return;

	topLeftQuad->querry(range, pointsInRange);
	topRightQuad->querry(range, pointsInRange);
	botLeftQuad->querry(range, pointsInRange);
	botRightQuad->querry(range, pointsInRange);
}

void data::QuadTree::insert(const Point& p, Entity* data)
{
	if (dataVector.size() < MAX_CAPACITY) {
		dataVector.push_back(Node(p, data));
		return;
	} else {
		if (!divided) subdivide();
		float halfwidth = quad.width / 2;
		if (p.x < quad.x + halfwidth) {
			if (p.y < quad.y + halfwidth) topLeftQuad->insert(p, data);
			else botLeftQuad->insert(p, data);
		} else {
			if (p.y < quad.y + halfwidth) topRightQuad->insert(p, data);
			else botRightQuad->insert(p, data);
		}
	}
}

void data::QuadTree::subdivide()
{
	divided = true;
	float halfwidth = quad.width / 2;
	topLeftQuad = new QuadTree(Rectangle(quad.x, quad.y, halfwidth));
	topRightQuad = new QuadTree(Rectangle(quad.x + halfwidth, quad.y, halfwidth));
	botLeftQuad = new QuadTree(Rectangle(quad.x, quad.y + halfwidth, halfwidth));
	botRightQuad = new QuadTree(Rectangle(quad.x + halfwidth, quad.y + halfwidth, halfwidth));
}