
#include "Rectangle.h"
#include "FileParser.h"
#include <map>
#include <vector>
#include <list>
#include <stack>

typedef int* PInt;

class ColisionDetector
{
public:
	ColisionDetector();
	~ColisionDetector();

	//main method which computes all intersections
	void findIntersections(char* fileName);
private:
	// initialize the collision matrix
	void initMatrix(int dimension);

	//prints the collisions for rectangle with index 'root'
	void printSet(int root, std::list<int> l);

	// generates all subsets of a given size for a vector
	void subset(int root, std::vector<int> arr, int totalSize, int partitionSize, int index, std::list<int> &l);
private:
	std::vector<Rectangle> rectangles;
	PInt* matrix;
	int matrixSize;
	FileParser fileParser;
};

