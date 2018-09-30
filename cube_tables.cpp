#include "cube_tables.h"

namespace Cube {

// The following tables respect the following conventions
//
//    7-------6
//   /|      /|
//  / |     / |  Corners
// 4-------5  |
// |  3----|--2
// | /     | /   y z
// |/      |/    |/
// 0-------1     o--x
//
//
//     o---10----o
//    /|        /|
//  11 7       9 6   Edges
//  /  |      /  |
// o----8----o   |
// |   o---2-|---o
// 4  /      5  /
// | 3       | 1
// |/        |/
// o----0----o
//
// Sides are ordered according to the Voxel::Side enum.
// Edges are ordered according to the Voxel::Edge enum (only g_edge_inormals!).
//

//static const unsigned int CORNER_COUNT = 8;
//static const unsigned int EDGE_COUNT = 12;

// Order doesn't technically matter here, they are for reading convenience.
// If you need a special ordering, combine index with other tables
const Vector3 g_corner_position[CORNER_COUNT] = {
	Vector3(0, 0, 0),
	Vector3(1, 0, 0),
	Vector3(1, 0, 1),
	Vector3(0, 0, 1),
	Vector3(0, 1, 0),
	Vector3(1, 1, 0),
	Vector3(1, 1, 1),
	Vector3(0, 1, 1)
};

const int g_side_quad_triangles[SIDE_COUNT][6] = {
	// LEFT
	{ 0, 1, 2, 0, 2, 3 },
	// RIGHT
	{ 0, 1, 2, 0, 2, 3 },
	// BOTTOM
	{ 0, 1, 2, 0, 2, 3 },
	// TOP
	{ 0, 1, 2, 0, 2, 3 },
	// BACK
	{ 0, 1, 2, 0, 2, 3 },
	// FRONT
	{ 0, 1, 2, 0, 2, 3 },
};

const unsigned int g_side_coord[SIDE_COUNT] = { 0, 0, 1, 1, 2, 2 };
const unsigned int g_side_sign[SIDE_COUNT] = { 0, 1, 0, 1, 0, 1 };

const Vector3i g_side_normals[SIDE_COUNT] = {
	Vector3i(-1, 0, 0),
	Vector3i(1, 0, 0),
	Vector3i(0, -1, 0),
	Vector3i(0, 1, 0),
	Vector3i(0, 0, -1),
	Vector3i(0, 0, 1),
};

// Corners have same winding, relative to the face's normal
const unsigned int g_side_corners[SIDE_COUNT][4] = {
	{ 3, 0, 4, 7 },
	{ 1, 2, 6, 5 },
	{ 1, 0, 3, 2 },
	{ 4, 5, 6, 7 },
	{ 0, 1, 5, 4 },
	{ 2, 3, 7, 6 }
};

const unsigned int g_side_edges[SIDE_COUNT][4] = {
	{ 3, 7, 11, 4 },
	{ 1, 6, 9, 5 },
	{ 0, 1, 2, 3 },
	{ 8, 9, 10, 11 },
	{ 0, 5, 8, 4 },
	{ 2, 6, 10, 7 }
};

// 3---2
// | / | {0,1,2,0,2,3}
// 0---1
//static const unsigned int g_vertex_to_corner[Voxel::SIDE_COUNT][6] = {
//    { 0, 3, 7, 0, 7, 4 },
//    { 2, 1, 5, 2, 5, 6 },
//    { 0, 1, 2, 0, 2, 3 },
//    { 7, 6, 5, 7, 5, 4 },
//    { 1, 0, 4 ,1, 4, 5 },
//    { 3, 2, 6, 3, 6, 7 }
//};

const Vector3i g_corner_inormals[CORNER_COUNT] = {
	Vector3i(-1, -1, -1),
	Vector3i(1, -1, -1),
	Vector3i(1, -1, 1),
	Vector3i(-1, -1, 1),

	Vector3i(-1, 1, -1),
	Vector3i(1, 1, -1),
	Vector3i(1, 1, 1),
	Vector3i(-1, 1, 1)
};

const Vector3i g_edge_inormals[EDGE_COUNT] = {
	Vector3i(0, -1, -1),
	Vector3i(1, -1, 0),
	Vector3i(0, -1, 1),
	Vector3i(-1, -1, 0),

	Vector3i(-1, 0, -1),
	Vector3i(1, 0, -1),
	Vector3i(1, 0, 1),
	Vector3i(-1, 0, 1),

	Vector3i(0, 1, -1),
	Vector3i(1, 1, 0),
	Vector3i(0, 1, 1),
	Vector3i(-1, 1, 0)
};

const unsigned int g_edge_corners[EDGE_COUNT][2] = {
	{ 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 },
	{ 0, 4 }, { 1, 5 }, { 2, 6 }, { 3, 7 },
	{ 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 4 }
};

// Order is irrelevant
const Vector3i g_moore_neighboring_3d[MOORE_NEIGHBORING_3D_COUNT] = {
	Vector3i(-1, -1, -1),
	Vector3i(0, -1, -1),
	Vector3i(1, -1, -1),
	Vector3i(-1, -1, 0),
	Vector3i(0, -1, 0),
	Vector3i(1, -1, 0),
	Vector3i(-1, -1, 1),
	Vector3i(0, -1, 1),
	Vector3i(1, -1, 1),

	Vector3i(-1, 0, -1),
	Vector3i(0, 0, -1),
	Vector3i(1, 0, -1),
	Vector3i(-1, 0, 0),
	//Vector3i(0,0,0),
	Vector3i(1, 0, 0),
	Vector3i(-1, 0, 1),
	Vector3i(0, 0, 1),
	Vector3i(1, 0, 1),

	Vector3i(-1, 1, -1),
	Vector3i(0, 1, -1),
	Vector3i(1, 1, -1),
	Vector3i(-1, 1, 0),
	Vector3i(0, 1, 0),
	Vector3i(1, 1, 0),
	Vector3i(-1, 1, 1),
	Vector3i(0, 1, 1),
	Vector3i(1, 1, 1),
};

} // namespace CubeTables

